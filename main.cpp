#include "stdafx.h"
#include "MarketLiveAnalyzer.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Log.h"

using namespace app::logger;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MarketLiveAnalyzer w;
    Log log;
    w.show();

    log.setLogLevel(Log::LogLevelError);

    log.Error("Test Message");
    log.Info("Test Message");
    log.Warning("Test Message");

    log.fnError("failed with -1", "main");

    return a.exec();
}
