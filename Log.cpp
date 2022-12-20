#include "Log.h"

namespace app {
namespace logger {



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

void Log::fnError(const char* message, const char* fnName)
{
	if (m_LogLevel >= LogLevelError)
	{
		qDebug() << "[ERROR]:" << "Function " << fnName
				<< message;
	}
}

} // namespace logger
} // namespace app