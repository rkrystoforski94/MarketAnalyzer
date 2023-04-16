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

std::string StockData::GetCurrentPrice(std::shared_ptr<std::string> response)
{
	return ApiGetCurrentPrice(response);
}

std::string StockData::GetPrevClosePrice(std::shared_ptr<std::string> response)
{
	return ApiGetPrevClosePrice(response);
}

std::string StockData::GetOpenPrice(std::shared_ptr<std::string> response)
{
	return ApiGetOpenPrice(response);
}

std::string StockData::GetDayRangePrice(std::shared_ptr<std::string> response)
{
	return ApiGetDayRangePrice(response);
}

std::string StockData::Get52wRangePrice(std::shared_ptr<std::string> response)
{
	return ApiGet52wRangePrice(response);
}

std::string StockData::GetAbsoluteChange(std::shared_ptr<std::string> response)
{
	return ApiGetAbsoluteChange(response);
}

std::string StockData::GetProcentChange(std::shared_ptr<std::string> response)
{
	return ApiGetProcentChange(response);
}

std::string StockData::RefreshData()
{
	return ApiRefreshData(this->stockShortName);
}
