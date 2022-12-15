#include "Log.h"


void Log::setLogLevel(LogLevel logLevel)
{
	m_LogLevel = logLevel;
}

void Log::Info(const char* message)
{
	if (m_LogLevel >= LogLevelInfo)
	{
		qDebug() << "[INFO]:" << message;
	}
}

void Log::Warning(const char* message)
{
	if (m_LogLevel >= LogLevelWarning)
	{
		qDebug() << "[WARNING]:" << message;
	}
}

void Log::Error(const char* message)
{
	if (m_LogLevel >= LogLevelError)
	{
		qDebug() << "[ERROR]" << message;
	}
}