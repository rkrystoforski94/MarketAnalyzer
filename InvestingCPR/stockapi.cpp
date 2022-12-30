// plikH.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "stockapi.h"

#include <iostream>
#include <string>
#include <cpr/cpr.h>

// DLL internal state variables:
static unsigned long long previous_;
static unsigned long long current_;
static unsigned index_;


void stockapi_init(
    const unsigned long long a,
    const unsigned long long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b;
}

unsigned long long get_previous_()
{
    return previous_;
}

bool test_request()
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
