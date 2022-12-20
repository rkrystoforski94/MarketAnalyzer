#include "MarketLiveAnalyzer.h"

MarketLiveAnalyzer::MarketLiveAnalyzer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MarketLiveAnalyzer::~MarketLiveAnalyzer()
{}

void MarketLiveAnalyzer::on_testBtn_clicked()
{
    qDebug() << "Test";
    close();
}