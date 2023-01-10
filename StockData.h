// StockData.h - Contains ...
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MarketAnal.h"

class StockData
{
public:
	StockData();
    virtual ~StockData();
private:
    std::string stockShortName;
    double currentPrice;

public:
    std::string GetCurrentPrice();
    std::string GetPrevClosePrice();
    std::string GetOpenPrice();
    std::string GetDayRangePrice();
    std::string Get52wRangePrice();
    std::string GetAbsoluteChange();
    std::string GetProcentChange();
};
