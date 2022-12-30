// stockapi.h - Contains declarations of math functions
#pragma once

#ifdef PLIKH_EXPORTS
#define PLIKH_API __declspec(dllexport)
#else
#define PLIKH_API __declspec(dllimport)
#endif


extern "C" PLIKH_API void stockapi_init(
    const unsigned long long a, const unsigned long long b);

extern "C" PLIKH_API bool test_request();

extern "C" PLIKH_API unsigned long long get_previous_();
