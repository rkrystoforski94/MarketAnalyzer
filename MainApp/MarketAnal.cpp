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
    qDebug() << "Cena " << predef::stock.allegro.stockName.c_str() << ": " << sd_allegro.GetCurrentPrice().c_str();
    qDebug() << "prev_close_price" << sd_allegro.GetPrevClosePrice().c_str();
    qDebug() << "open_price" << sd_allegro.GetOpenPrice().c_str();
    qDebug() << "day_range_price" << sd_allegro.GetDayRangePrice().c_str();
    qDebug() << "52w_range_price" << sd_allegro.Get52wRangePrice().c_str();
    qDebug() << "absolute_change" << sd_allegro.GetAbsoluteChange().c_str();
    qDebug() << "procent_change" << sd_allegro.GetProcentChange().c_str();

    StockData sd_netflix(predef::stock.netflix.stockName);
    qDebug() << "Cena " << predef::stock.netflix.stockName.c_str() << ": " << sd_netflix.GetCurrentPrice().c_str();
    qDebug() << "prev_close_price" << sd_netflix.GetPrevClosePrice().c_str();
    qDebug() << "open_price" << sd_netflix.GetOpenPrice().c_str();
    qDebug() << "day_range_price" << sd_netflix.GetDayRangePrice().c_str();
    qDebug() << "52w_range_price" << sd_netflix.Get52wRangePrice().c_str();
    qDebug() << "absolute_change" << sd_netflix.GetAbsoluteChange().c_str();
    qDebug() << "procent_change" << sd_netflix.GetProcentChange().c_str();
    


    log.fnError(__FUNCTION__, "Test message");
}