#include "Log.h"

namespace app {
namespace logger {

Log::Log()
{
	time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	dbgIn("Log::Log()", "");
	m_LogLevel = LogLevelError;
	
	if (LOG_TO_FILE == 1)
	{
		m_fileName.open("MarketApp.log", std::ios::out | std::ios::trunc);

		if (!m_fileName.good())
		{
			Error("Cannnot open or create a log file");
			m_fileName.close();
		}

		m_fileName << "TIME: " << std::put_time(localtime(&now), "%F %T") << "\n";

		Info("Log file succesfully opened");

	}
}

Log::~Log()
{
	m_fileName.close();
}

#ifdef DBG_MODE

// TODO
// Extend info with function name calling this

void Log::Info(const char* message)
{
	if (m_LogLevel >= LogLevelInfo)
	{
		qDebug() << "[INFO]:" << message;
	}

	if (LOG_TO_FILE == 1)
	{
		m_fileName << "[INFO]:" << message << "\n";
	}
}

void Log::Warning(const char* message)
{
	if (m_LogLevel >= LogLevelWarning)
	{
		qDebug() << "[WARNING]:" << message;
	}

	if (LOG_TO_FILE == 1)
	{
		m_fileName << "[WARNING]:" << message << "\n";
	}
}

void Log::Error(const char* message)
{
	if (m_LogLevel >= LogLevelError)
	{
		qDebug() << "[ERROR]" << message;
	}

	if (LOG_TO_FILE == 1)
	{
		m_fileName << "[ERROR]" << message << "\n";
	}
}

void Log::fnError(const char* fnName, const char* message)
{
	if (m_LogLevel >= LogLevelError)
	{
		qDebug() << "[ERROR]:" << "Function" << fnName
				<< message;
	}

	if (LOG_TO_FILE == 1)
	{
		m_fileName << "[ERROR]:" << "Function" << fnName
			<< message << "\n";
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