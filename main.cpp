#include "stdafx.h"
#include "MarketLiveAnalyzer.h"
#include <QtWidgets/QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MarketLiveAnalyzer w;
    w.show();

    qDebug() << "Test Print";

    qInfo() << "Test Print2";
   

    return a.exec();
}
