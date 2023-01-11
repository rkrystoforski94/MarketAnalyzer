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

    extern "C" STOCKAPIH_API std::string get_prev_close_price(std::string stockName);

    extern "C" STOCKAPIH_API std::string get_open_price(std::string stockName);

    extern "C" STOCKAPIH_API std::string get_day_range_price(std::string stockName);

    extern "C" STOCKAPIH_API std::string get_52w_range_price(std::string stockName);

    extern "C" STOCKAPIH_API std::string get_absolute_change(std::string stockName);

    extern "C" STOCKAPIH_API std::string get_procent_change(std::string stockName);

}