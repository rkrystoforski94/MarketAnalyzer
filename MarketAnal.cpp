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
    stockapi_init( 123, 234);
    qDebug() << "Test " << get_previous_();
}