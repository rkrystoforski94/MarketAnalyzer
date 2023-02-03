// StockData.h - Contains ...
#pragma once

// TODO: Move this define to more suitable place
#define INVESTING_COM_API
#ifdef INVESTING_COM_API
#include "stockapi.h" // dynamic lib, investing.com
#endif

#include <QtWidgets/QMainWindow>
#include "ui_MarketAnal.h"
#include "PredefinedData.h"


class StockData
{
public:
    StockData(std::string stock);
    virtual ~StockData();
private:
    std::string stockShortName;
    std::string stockFullName;
    double currentPrice;
    double prevClosePrice;
    double openPrice;
    double dayMinPrice;
    double dayMaxPrice;
    double weekMinPrice;
    double weekMaxPrice;
    double absChange;
    double procChange;

public:
    std::string GetCurrentPrice();
    std::string GetPrevClosePrice();
    std::string GetOpenPrice();
    std::string GetDayRangePrice();
    std::string Get52wRangePrice();
    std::string GetAbsoluteChange();
    std::string GetProcentChange();

    // to do add last update -> ret date
    // geter fields
    // update( database )
private:
#ifdef INVESTING_COM_API
    std::string(*ApiGetCurrentPrice)(std::string) = sa::get_stock_price;
    std::string(*ApiGetPrevClosePrice)(std::string) = sa::get_prev_close_price;
    std::string(*ApiGetOpenPrice)(std::string) = sa::get_open_price;
    std::string(*ApiGetDayRangePrice)(std::string) = sa::get_day_range_price;
    std::string(*ApiGet52wRangePrice)(std::string) = sa::get_52w_range_price;
    std::string(*ApiGetAbsoluteChange)(std::string) = sa::get_absolute_change;
    std::string(*ApiGetProcentChange)(std::string) = sa::get_procent_change;
#else
    std::string(*ApiGetCurrentPrice)(std::string);
    std::string(*ApiGetPrevClosePrice)(std::string);
    std::string(*ApiGetOpenPrice)(std::string);
    std::string(*ApiGetDayRangePrice)(std::string);
    std::string(*ApiGet52wRangePrice)(std::string);
    std::string(*ApiGetAbsoluteChange)(std::string);
    std::string(*ApiGetProcentChange)(std::string);
#endif
};