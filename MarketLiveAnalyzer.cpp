#include "stdafx.h"
#include "MarketLiveAnalyzer.h"
#include <iostream>

MarketLiveAnalyzer::MarketLiveAnalyzer(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

MarketLiveAnalyzer::~MarketLiveAnalyzer()
{
    qDebug() << "~MarketLiveAnalyzer called";
}

void MarketLiveAnalyzer::on_show_market_clicked()
{
    qDebug() << "onShowMarketClicked method used";
    return;
}
