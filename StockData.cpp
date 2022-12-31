#include "StockData.h"
#include "PredefinedData.h"
#include "stockapi.h"

StockData::StockData()
{
	this->currentPrice = 0.0;
	this->stockShortName = predefdata::fullstocknameArray->stockName[8];
}

StockData::~StockData()
{
}

std::string StockData::GetCurrentPrice()
{
	std::string stockShortNameLocal = this->stockShortName;
	return sa::get_stock_price(stockShortNameLocal);
}
