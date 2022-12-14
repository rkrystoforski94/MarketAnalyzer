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

    std::string APPLE_open_price = sa::get_open_price(stockFullNameLocal);
    qDebug() << "Open Cena apple: " << APPLE_open_price.c_str();

    std::string APPLE_dayrange_price = sa::get_day_range_price(stockFullNameLocal);
    qDebug() << "Day Range Cena apple: " << APPLE_dayrange_price.c_str();

    std::string APPLE_weekrange_price = sa::get_52w_range_price(stockFullNameLocal);
    qDebug() << "Week Range Cena apple: " << APPLE_weekrange_price.c_str();

    std::string APPLE_abschange_price = sa::get_absolute_change(stockFullNameLocal);
    qDebug() << "Absolute Change Cena apple: " << APPLE_abschange_price.c_str();

    std::string APPLE_procchange_price = sa::get_procent_change(stockFullNameLocal);
    qDebug() << "Procent Change Cena apple: " << APPLE_procchange_price.c_str() << "%";

    log.fnError(__FUNCTION__, "Test message");
}