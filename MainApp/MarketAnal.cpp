#include "MarketAnal.h"
#include "stockapi.h"

MarketAnal::MarketAnal(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MarketAnal::~MarketAnal()
{}

void MarketAnal::on_showMarketBtn_clicked()
{
    std::string stockFullNameLocal = "apple-computer-inc";
    std::string APPLE_price = sa::get_stock_price(stockFullNameLocal);
    qDebug() << "Cena apple: " << APPLE_price.c_str();
    std::string APPLE_prev_price = sa::get_prev_close_price(stockFullNameLocal);
    qDebug() << "Prev Cena apple: " << APPLE_prev_price.c_str();

    log.fnError(__FUNCTION__, "Test message");
}