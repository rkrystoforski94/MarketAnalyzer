#include <iostream>
#include <string>
#include <QtWidgets/QApplication>
#include <QDebug> 

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
	Log(const Log& ) = delete;
	Log(const Log&&) = delete;

	void setLogLevel(LogLevel logLevel);

	void Info(const char* message);
	void Warning(const char* message);
	void Error(const char* message);


	~Log() = default;
private:
	LogLevel m_LogLevel = LogLevelError;
};