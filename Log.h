#include <iostream>
#include <string>
#include <QtWidgets/QApplication>
#include <QDebug>
#include <sstream>
#include <initializer_list>
#include <tuple>

namespace app {
namespace logger {

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
	Log() = default;
	Log(LogLevel level) : m_LogLevel(level) {};
	Log(const Log&) = delete;
	Log(const Log&&) = delete;

	void setLogLevel(LogLevel logLevel);

	void Info(const char* message);
	void Warning(const char* message);
	void Error(const char* message);

	void fnError(const char* message, const char* fnName);

	~Log() = default;

private:
	LogLevel m_LogLevel = LogLevelError;
};

} //namespace logger
} // namespace app