#include "Log.h"

namespace app {
namespace logger {

#ifdef DBG_MODE

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

void Log::fnError(const char* fnName, const char* message)
{
	if (m_LogLevel >= LogLevelError)
	{
		qDebug() << "[ERROR]:" << "Function" << fnName
				<< message;
	}
}

#else
	void Log::Info(const char* message) {};
	void Log::Warning(const char* message) {};
	void Log::Error(const char* message) {};

	void Log::fnError(const char* message, const char* fnName) {};
#endif // DBG_MODE

} // namespace logger
} // namespace app