#include "stockapi.h"
// plikH.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "stockapi.h"
#include <memory>

#include <iostream>
#include <string>
#include <cpr/cpr.h>

// TODO : FastHTML
// multi filter is required
// GetListedData(); // return_not_empty() method would be useful
// execute not from ctor would be more handy
// "Only first found" option would speed up work in certain cases
// queue is important so thread needs to work on separate containers
// space sensetive would be helpful <tag ... attr1 = "n a me" attr2 = "nam e" ...>
// "n a me" != "nam e"
// GetAllTagOpenIndexes() should filter out wrong tags (not append if not match)
// !! remove comments

#include "../../FastHTML/include/FastHTML.h"

#include <array>
#include <algorithm>
#include <cctype>

void get_response(std::string url, std::shared_ptr<std::string> resp);
void get_tagdata_from_response(std::vector<const char*> tagClass, std::shared_ptr<std::string> resp, std::string& data);
std::string removeBrackets(std::string str);


// DLL internal state variables:
static unsigned long long previous_;
static unsigned long long current_;
static unsigned index_;
static std::string _getStockPrice;
static std::string _getPrevClosePrice;
static std::string _getOpenPrice;
static std::string _getDayRangePrice;
static std::string _getWeekRangePrice;
static std::string _getAbsChangePrice;
static std::string _getProcentChangePrice;


void sa::stockapi_init(
    const unsigned long long a,
    const unsigned long long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b;
}

unsigned long long sa::get_previous_()
{
    return previous_;
}

bool sa::test_request()
{
    std::cout << "Czyli co, tutaj musze pisac?" << '\n';

    cpr::Response r = cpr::Get(cpr::Url{ "https://api.github.com/repos/whoshuu/cpr/contributors" },
        cpr::Authentication{ "user", "pass", cpr::AuthMode::BASIC },
        cpr::Parameters{ {"anon", "true"}, {"key", "value"} });
    std::cout << "Status code: " << r.status_code << '\n';
    std::cout << "Header:\n";
    for (const std::pair<const std::basic_string<char>, std::basic_string<char>>& kv : r.header) {
        std::cout << '\t' << kv.first << ':' << kv.second << '\n';
    }
    std::cout << "Text: " << r.text << '\n';
    return true;
}

std::string sa::get_stock_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/" + stockName;
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::pair<std::string, std::map<std::string, std::string>> filter;
    filter.first = "span";
    filter.second["data-test"] = "instrument-price-last";
    HResponse obj1(response.get(), filter);
    _getStockPrice = obj1.GetLastData();

    return _getStockPrice;
}

std::string sa::get_prev_close_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/" + stockName;
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    //<dd data-test="sharesOutstanding" class="font-bold">
    // <span class="key-info_dd-numeric__5IsvY"><span>
    //
    std::pair<std::string, std::map<std::string, std::string>> filter;
    filter.first = "dd";
    filter.second["data-test"] = "prevClose";
    filter.second["class"] = "font-bold";
    HResponse obj1(response.get(), filter);
    std::string s = obj1.GetLastData();

    filter.first = "span";
    filter.second.clear();
    HResponse obj2(&s, filter);
    auto resps = obj2.GetListedData();
    _getPrevClosePrice = "UPS2";
    for (auto var : resps)
    {
        if (var != "") {
            _getPrevClosePrice = var;
            break;
        }
    }
    return _getPrevClosePrice;
}

std::string sa::get_open_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/" + stockName;
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    // <dd data-test="open" class="font-bold"><span class="key-info_dd-numeric__5IsvY">
    // <span>183.95</span><span></span></span></dd>
    //
    std::pair<std::string, std::map<std::string, std::string>> filter;
    filter.first = "dd";
    filter.second["data-test"] = "open";
    filter.second["class"] = "font-bold";
    HResponse obj1(response.get(), filter);
    std::string s = obj1.GetLastData();

    filter.first = "span";
    filter.second.clear();
    HResponse obj2(&s, filter);
    auto resps = obj2.GetListedData();
    _getOpenPrice = "UPS2";
    for (auto var : resps)
    {
        if (var != "") {
            _getOpenPrice = var;
            break;
        }
    }

    return _getOpenPrice;
}

std::string sa::get_day_range_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/" + stockName;
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::string min;
    std::string max;

    //<dd data-test="dailyRange" class="font-bold">
    // <span class="key-info_dd-numeric__5IsvY">
    // <span>359</span>
    // <span></span></span>
    // <span class="ml-1 mr-1">-</span>
    // <span class="key-info_dd-numeric__5IsvY">
    // <span>379.43</span>
    // <span></span></span>
    //</dd>
    //
    std::pair<std::string, std::map<std::string, std::string>> filter;
    filter.first = "dd";
    filter.second["data-test"] = "dailyRange";
    filter.second["class"] = "font-bold";
    HResponse obj1(response.get(), filter);
    std::string s = obj1.GetLastData();

    filter.first = "span";
    filter.second.clear();
    HResponse obj2(&s, filter);

    auto allPrices = obj2.GetListedData();
    std::array<std::string, 2> pricesArr;
    unsigned int index = 0;
    for (auto val : allPrices) {
        if (val != "") {
            pricesArr[index++] = val;
        }
        if (index >= 2) break;
    }
    std::sort(pricesArr.begin(), pricesArr.end());
    min = pricesArr[0];
    max = pricesArr[pricesArr.size() - 1];

    _getDayRangePrice = min;
    _getDayRangePrice.append(" - " + max);

    return _getDayRangePrice;
}

std::string sa::get_52w_range_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/" + stockName;
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::string min;
    std::string max;

    // 
    //<dd data-test="weekRange" class="font-bold">
    // <span class="key-info_dd-numeric__5IsvY">
    // <span>162.71</span><span></span></span>
    // <span class="ml-1 mr-1">-</span>
    // <span class="key-info_dd-numeric__5IsvY">
    // <span>412.98</span><span></span></span>
    //</dd>
    //
    std::pair<std::string, std::map<std::string, std::string>> filter;
    filter.first = "dd";
    filter.second["data-test"] = "weekRange";
    filter.second["class"] = "font-bold";
    HResponse obj1(response.get(), filter);
    std::string s = obj1.GetLastData();

    filter.first = "span";
    filter.second.clear();
    HResponse obj2(&s, filter);

    auto allPrices = obj2.GetListedData();
    std::array<std::string, 2> pricesArr;
    unsigned int index = 0;
    for (auto val : allPrices) {
        if (val != "") {
            pricesArr[index++] = val;
        }
        if (index >= 2) break;
    }
    std::sort(pricesArr.begin(), pricesArr.end());
    min = pricesArr[0];
    max = pricesArr[pricesArr.size() - 1];
    //

    _getWeekRangePrice = min;
    _getWeekRangePrice.append(" - " + max);

    return _getWeekRangePrice;
}

std::string sa::get_absolute_change(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/" + stockName;
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    //<div class="text-xl flex items-end flex-wrap">
    // <span class="instrument-price_change-value__h13Qh ml-2.5 text-negative-main" data-test="instrument-price-change">-0.99</span>
    // <span class="instrument-price_change-percent__bT4yt ml-2.5 text-negative-main" data-test="instrument-price-change-percent">(-0.27%)</span>
    //</div>
    //
    std::pair<std::string, std::map<std::string, std::string>> filter;
    filter.first = "div";
    filter.second["class"] = "text-xlflexitems-endflex-wrap"; // no spaces
    HResponse obj1(response.get(), filter);
    std::string s = obj1.GetFirstData(); // queue sensetive

    filter.first = "span";
    filter.second.clear();
    filter.second["data-test"] = "instrument-price-change"; 
    HResponse obj2(&s, filter);

    _getAbsChangePrice = obj2.GetFirstData(); // queue sensetive

    return _getAbsChangePrice;
}

std::string sa::get_procent_change(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/" + stockName;
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    //<div class="text-xl flex items-end flex-wrap">
    // <span class="instrument-price_change-value__h13Qh ml-2.5 text-negative-main" data-test="instrument-price-change">-0.99</span>
    // <span class="instrument-price_change-percent__bT4yt ml-2.5 text-negative-main" data-test="instrument-price-change-percent">(-0.27%)</span>
    //</div>
    //
    std::pair<std::string, std::map<std::string, std::string>> filter;
    filter.first = "div";
    filter.second["class"] = "text-xlflexitems-endflex-wrap"; // no spaces
    HResponse obj1(response.get(), filter);
    std::string s = obj1.GetFirstData(); // queue sensetive

    filter.first = "span";
    filter.second.clear();
    filter.second["data-test"] = "instrument-price-change";
    HResponse obj2(&s, filter);

    _getProcentChangePrice = removeBrackets(obj2.GetLastData()); // queue sensetive

    return _getProcentChangePrice;
}

// ***************** STATIC ***************** \\

static void get_response(std::string url, std::shared_ptr<std::string> resp)
{
    cpr::Response r = cpr::Get(
        cpr::Url{ url },
        cpr::Authentication{ "user", "pass", cpr::AuthMode::BASIC },
        cpr::Parameters{ {"anon", "true"}, {"key", "value"} },
        cpr::Header{ {"accept", "application/json"}, {"User - Agent", "Mozilla / 5.0 (Windows NT 10.0; Win64; x64) AppleWebKit / 537.36 (KHTML, like Gecko) Chrome / 108.0.0.0 Safari / 537.36"} });
    *resp = r.text;  // Unicode is probably handed by CPR
}

static void get_tagdata_from_response(std::vector<const char *> tagClass, std::shared_ptr<std::string> resp, std::string &data)
{
    data = "Missing data";
    const unsigned int val = static_cast<unsigned int>(0xff);
    size_t estimatedRespSize = tagClass.size() * val;
    std::size_t found = (*resp).find(tagClass.front());
    if (found == std::string::npos) return;
    size_t sts = strlen(tagClass.front());
    std::string localResp = (*resp).substr(found + (sts), estimatedRespSize);

    for (auto singleTag = std::next(tagClass.begin()); singleTag != tagClass.end(); singleTag++)
    {
        if (estimatedRespSize > val) estimatedRespSize -= val;
        char* tmp = const_cast<char *>(*singleTag);
        found = localResp.find(tmp);
        if (found == std::string::npos) return;
        sts = strlen(tmp);
        localResp = localResp.substr(found + (sts), estimatedRespSize);
    }
    
    std::size_t begin = localResp.find(">");
    if (begin == std::string::npos) return;

    std::size_t end = localResp.find("<");
    if (end == std::string::npos) return;

    data = localResp.substr(begin + 1, end - begin - 1);
}

static std::string removeBrackets(std::string str)
{
    str.erase(remove(str.begin(), str.end(), '('), str.end());
    str.erase(remove(str.begin(), str.end(), ')'), str.end());
    return str;
}
