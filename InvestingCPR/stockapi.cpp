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

void get_response(std::string url, std::shared_ptr<std::string> resp);
void get_tagdata_from_response(std::vector<const char*> tagClass, std::shared_ptr<std::string> resp, std::string& data);


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
    std::string url = "https://www.investing.com/equities/";
    url.append(stockName);
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::vector<const char*> divTag;
    divTag.push_back("instrument-price-last");
    get_tagdata_from_response(divTag, response, _getStockPrice);

    return _getStockPrice;
}

std::string sa::get_prev_close_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/";
    url.append(stockName);
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::vector<const char*> divTag;
    divTag.push_back("data-test=\"prevClose\"");
    divTag.push_back("class=\"key-info_dd-numeric__5IsvY\"");
    divTag.push_back("span");
    get_tagdata_from_response(divTag, response, _getPrevClosePrice);

    return _getPrevClosePrice;
}

std::string sa::get_open_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/";
    url.append(stockName);
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::vector<const char*> divTag;
    divTag.push_back("data-test=\"open\"");
    divTag.push_back("class=\"key-info_dd-numeric__5IsvY\"");
    divTag.push_back("span");
    get_tagdata_from_response(divTag, response, _getOpenPrice);

    return _getOpenPrice;
}

std::string sa::get_day_range_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/";
    url.append(stockName);
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::string min;
    std::string max;

    std::vector<const char*> divTag;
    divTag.push_back("data-test=\"dailyRange\"");
    divTag.push_back("class=\"key-info_dd-numeric__5IsvY\"");
    divTag.push_back("span");
    get_tagdata_from_response(divTag, response, min);

    divTag.clear();
    divTag.push_back("data-test=\"dailyRange\"");
    divTag.push_back("class=\"key-info_dd-numeric__5IsvY\"");
    divTag.push_back("class=\"key-info_dd-numeric__5IsvY\"");
    divTag.push_back("span");
    get_tagdata_from_response(divTag, response, max);

    _getDayRangePrice = min;
    _getDayRangePrice.append(" - " + max);

    return _getDayRangePrice;
}

std::string sa::get_52w_range_price(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/";
    url.append(stockName);
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::string min;
    std::string max;

    std::vector<const char*> divTag;
    divTag.push_back("data-test=\"weekRange\"");
    divTag.push_back("class=\"key-info_dd-numeric__5IsvY\"");
    divTag.push_back("span");
    get_tagdata_from_response(divTag, response, min);

    divTag.clear();
    divTag.push_back("data-test=\"weekRange\"");
    divTag.push_back("class=\"key-info_dd-numeric__5IsvY\"");
    divTag.push_back("class=\"key-info_dd-numeric__5IsvY\"");
    divTag.push_back("span");
    get_tagdata_from_response(divTag, response, max);

    _getWeekRangePrice = min;
    _getWeekRangePrice.append(" - " + max);

    return _getWeekRangePrice;
}

std::string sa::get_absolute_change(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/";
    url.append(stockName);
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::string sign;
    std::string val;

    std::vector<const char*> divTag;
    divTag.push_back("data-test=\"instrument-price-change\"");
    get_tagdata_from_response(divTag, response, sign);

    divTag.clear();
    divTag.push_back("data-test=\"instrument-price-change\"");
    divTag.push_back("!--");
    get_tagdata_from_response(divTag, response, val);

    _getAbsChangePrice = sign;
    _getAbsChangePrice.append(val);

    return _getAbsChangePrice;
}

std::string sa::get_procent_change(std::string stockName)
{
    std::string url = "https://www.investing.com/equities/";
    url.append(stockName);
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    get_response(url, response);  // set response

    std::string sign;
    std::string val;

    std::vector<const char*> divTag;
    divTag.push_back("data-test=\"instrument-price-change-percent\"");
    divTag.push_back("!--");
    get_tagdata_from_response(divTag, response, sign);

    divTag.clear();
    divTag.push_back("data-test=\"instrument-price-change-percent\"");
    divTag.push_back("!--");
    divTag.push_back("!--");
    get_tagdata_from_response(divTag, response, val);

    _getProcentChangePrice = sign;
    _getProcentChangePrice.append(val);

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
    *resp = r.text;
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
