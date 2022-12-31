// stockapi.h - Contains declarations of math functions
#pragma once
#include <string>

#ifdef STOCKAPIH_EXPORTS
#define STOCKAPIH_API __declspec(dllexport)
#else
#define STOCKAPIH_API __declspec(dllimport)
#endif

namespace sa {

    extern "C" STOCKAPIH_API void stockapi_init(
        const unsigned long long a, const unsigned long long b);

    extern "C" STOCKAPIH_API bool test_request();

    extern "C" STOCKAPIH_API unsigned long long get_previous_();

    extern "C" STOCKAPIH_API std::string get_stock_price(std::string stockName);

}