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
    //std::string *response;
    std::shared_ptr<std::string> response = std::make_shared<std::string>();
    
    cpr::Response r = cpr::Get(
        cpr::Url{ url },
        cpr::Authentication{ "user", "pass", cpr::AuthMode::BASIC },
        cpr::Parameters{ {"anon", "true"}, {"key", "value"} },
        cpr::Header{ {"accept", "application/json"}, {"User - Agent", "Mozilla / 5.0 (Windows NT 10.0; Win64; x64) AppleWebKit / 537.36 (KHTML, like Gecko) Chrome / 108.0.0.0 Safari / 537.36"} });
    *response = r.text;

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
    divTag.push_back("key-info_dd-numeric__5IsvY");
    divTag.push_back("span");
    get_tagdata_from_response(divTag, response, _getPrevClosePrice);

    return _getPrevClosePrice;
}

std::string sa::get_open_price()
{
    return "54321.09876";
}

std::string sa::get_day_range_price()
{
    return "54321.09876";
}

std::string sa::get_52w_range_price()
{
    return "54321.09876";
}

std::string sa::get_absolute_change()
{
    return "54321.09876";
}

std::string sa::get_procent_change()
{
    return "54321.09876";
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
    std::size_t found = (*resp).find(tagClass.front());
    if (found == std::string::npos) return;
    std::string localResp = (*resp).substr(found, 100);

    for (auto singleTag = std::next(tagClass.begin()); singleTag != tagClass.end(); singleTag++)
    {
        found = localResp.find(*singleTag);
        if (found == std::string::npos) return;
        localResp = localResp.substr(found, 100);
    }
    
    std::size_t begin = localResp.find(">");
    if (begin == std::string::npos) return;

    std::size_t end = localResp.find("<");
    if (end == std::string::npos) return;

    data = localResp.substr(begin + 1, end - begin - 1);
}
