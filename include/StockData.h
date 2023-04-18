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
    std::string GetCurrentPrice(std::shared_ptr<std::string> response);
    std::string GetPrevClosePrice(std::shared_ptr<std::string> response);
    std::string GetOpenPrice(std::shared_ptr<std::string> response);
    std::string GetDayRangePrice(std::shared_ptr<std::string> response);
    std::string Get52wRangePrice(std::shared_ptr<std::string> response);
    std::string GetAbsoluteChange(std::shared_ptr<std::string> response);
    std::string GetProcentChange(std::shared_ptr<std::string> response);
    std::string RefreshData();

    // to do add last update -> ret date
    // geter fields
    // update( database )
private:
#ifdef INVESTING_COM_API
    std::string(*ApiGetCurrentPrice)(std::shared_ptr<std::string> response) = sa::get_stock_price;
    std::string(*ApiGetPrevClosePrice)(std::shared_ptr<std::string> response) = sa::get_prev_close_price;
    std::string(*ApiGetOpenPrice)(std::shared_ptr<std::string> response) = sa::get_open_price;
    std::string(*ApiGetDayRangePrice)(std::shared_ptr<std::string> response) = sa::get_day_range_price;
    std::string(*ApiGet52wRangePrice)(std::shared_ptr<std::string> response) = sa::get_52w_range_price;
    std::string(*ApiGetAbsoluteChange)(std::shared_ptr<std::string> response) = sa::get_absolute_change;
    std::string(*ApiGetProcentChange)(std::shared_ptr<std::string> response) = sa::get_procent_change;
    std::string(*ApiRefreshData)(std::string stockName) = sa::get_response_string;
#else
    std::string(*ApiGetCurrentPrice)(std::shared_ptr<std::string> response);
    std::string(*ApiGetPrevClosePrice)(std::shared_ptr<std::string> response);
    std::string(*ApiGetOpenPrice)(std::shared_ptr<std::string> response);
    std::string(*ApiGetDayRangePrice)(std::shared_ptr<std::string> response);
    std::string(*ApiGet52wRangePrice)(std::shared_ptr<std::string> response);
    std::string(*ApiGetAbsoluteChange)(std::shared_ptr<std::string> response);
    std::string(*ApiGetProcentChange)(std::shared_ptr<std::string> response);
    std::string(*ApiRefreshData)(std::string stockName);
#endif
};