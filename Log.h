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
void func2(std::tuple<T> list)
{
	for (auto elem : list)
	{
		std::cout << elem << std::endl;
	}
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