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
    StockData sda(predef::stock.allegro.stockName);
    std::shared_ptr<std::string> response = std::make_shared<std::string>(sda.RefreshData());
    qDebug() << "Cena " << predef::stock.allegro.stockName.c_str() << ": " << sda.GetCurrentPrice(response).c_str();
    qDebug() << "prev_close_price" << sda.GetPrevClosePrice(response).c_str();
    qDebug() << "open_price" << sda.GetOpenPrice(response).c_str();
    qDebug() << "day_range_price" << sda.GetDayRangePrice(response).c_str();
    qDebug() << "52w_range_price" << sda.Get52wRangePrice(response).c_str();
    qDebug() << "absolute_change" << sda.GetAbsoluteChange(response).c_str();
    qDebug() << "procent_change" << sda.GetProcentChange(response).c_str();

    StockData sdn(predef::stock.netflix.stockName);
    response = std::make_shared<std::string>(sdn.RefreshData());
    qDebug() << "Cena " << predef::stock.netflix.stockName.c_str() << ": " << sdn.GetCurrentPrice(response).c_str();
    qDebug() << "prev_close_price" << sdn.GetPrevClosePrice(response).c_str();
    qDebug() << "open_price" << sdn.GetOpenPrice(response).c_str();
    qDebug() << "day_range_price" << sdn.GetDayRangePrice(response).c_str();
    qDebug() << "52w_range_price" << sdn.Get52wRangePrice(response).c_str();
    qDebug() << "absolute_change" << sdn.GetAbsoluteChange(response).c_str();
    qDebug() << "procent_change" << sdn.GetProcentChange(response).c_str();
    
    log.fnError(__FUNCTION__, "Test message");
}