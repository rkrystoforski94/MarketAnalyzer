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

};
