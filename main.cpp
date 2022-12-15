#include "stdafx.h"
#include "MarketLiveAnalyzer.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Log.h"


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

    return a.exec();
}
