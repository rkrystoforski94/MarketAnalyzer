#include "StockData.h"

StockData::StockData(std::string stock)
{
	this->currentPrice = 0.0;
	this->prevClosePrice = 0.0;
	this->openPrice = 0.0;
	this->dayMinPrice = 0.0;
	this->dayMaxPrice = 0.0;
	this->weekMinPrice = 0.0;
	this->weekMaxPrice = 0.0;
	this->absChange = 0.0;
	this->procChange = 0.0;
	this->stockShortName = stock;
	this->stockFullName = stock;
}

StockData::~StockData()
{
}

std::string StockData::GetCurrentPrice()
{
	return ApiGetCurrentPrice(this->stockShortName);
}

std::string StockData::GetPrevClosePrice()
{
	return ApiGetPrevClosePrice(this->stockShortName);
}

std::string StockData::GetOpenPrice()
{
	return ApiGetOpenPrice(this->stockShortName);
}

std::string StockData::GetDayRangePrice()
{
	return ApiGetDayRangePrice(this->stockShortName);
}

std::string StockData::Get52wRangePrice()
{
	return ApiGet52wRangePrice(this->stockShortName);
}

std::string StockData::GetAbsoluteChange()
{
	return ApiGetAbsoluteChange(this->stockShortName);
}

std::string StockData::GetProcentChange()
{
	return ApiGetProcentChange(this->stockShortName);
}
