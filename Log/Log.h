#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <QtWidgets/QApplication>
#include <QDebug>
#include <sstream>
#include <fstream>
#include <iomanip>

namespace app {
namespace logger {

#ifdef DBG_MODE

template <typename T>
void MagicLog(std::ostream& o, T t)
{
	o << t << ", ";
}

template<typename T, typename... Args>
void MagicLog(std::ostream& o, T t, Args... args) // recursive variadic function
{
	MagicLog(o, t);
	MagicLog(o, args...);
}

template<typename... Args>
void dbgIn(std::string logType, Args... args)
{
	std::ostringstream oss;
	MagicLog(oss, args...);
	qDebug() << QString::fromStdString(logType) << QString::fromStdString(oss.str());
}

#endif // DBG_MODE

class Log
{
public:
	enum LogLevel
	{
		LogLevelInfo = 0,
		LogLevelWarning,
		LogLevelError
	};
public:
	Log();
	Log(LogLevel level) : m_LogLevel(level) {};
	Log(const Log&) = delete;
	Log(const Log&&) = delete;

	void setLogLevel(LogLevel logLevel);

	void Info(const char* message);
	void Warning(const char* message);
	void Error(const char* message);

	void fnError(const char* message, const char* fnName);

	~Log();

private:
	LogLevel m_LogLevel;
	std::fstream m_fileName;
};

} //namespace logger
} // namespace app

#endif