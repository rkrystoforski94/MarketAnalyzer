#include "MarketAnal.h"
#include "stockapi.h"
#include <PredefinedData.h>
#include <StockData.h>

MarketAnal::MarketAnal(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MarketAnal::~MarketAnal()
{}

void MarketAnal::on_showMarketBtn_clicked()
{
    StockData sd_allegro(predef::stock.allegro.stockName);
    qDebug() << "Cena apple: " << sd_allegro.GetCurrentPrice().c_str();
    qDebug() << "Cena apple: " << predef::stock.allegro.stockName.c_str();

    StockData sd_netflix(predef::stock.netflix.stockName);
    qDebug() << "Cena apple: " << sd_netflix.GetDayRangePrice().c_str();
    qDebug() << "Cena apple: " << predef::stock.netflix.stockName.c_str();

    log.fnError(__FUNCTION__, "Test message");
}