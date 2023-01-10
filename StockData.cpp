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

std::string StockData::GetPrevClosePrice()
{
	return "54321.09876";
}

std::string StockData::GetOpenPrice()
{
	return "54321.09876";
}

std::string StockData::GetDayRangePrice()
{
	return "54321.09876";
}

std::string StockData::Get52wRangePrice()
{
	return "54321.09876";
}

std::string StockData::GetAbsoluteChange()
{
	return "54321.09876";
}

std::string StockData::GetProcentChange()
{
	return "54321.09876";
}

