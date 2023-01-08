#pragma once
#include <sstream>

namespace data_api
{
// General interface for play with our data
class IDataApi
{
public:
	virtual int getData() = 0;

	virtual std::stringstream printData() = 0;

	virtual int convertFromJson(void* data) = 0;
private:
	void* data;
};


} // namespace data_api