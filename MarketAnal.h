#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MarketAnal.h"

class MarketAnal : public QMainWindow
{
    Q_OBJECT

public:
    MarketAnal(QWidget *parent = nullptr);
    ~MarketAnal();
private slots:
    void on_showMarketBtn_clicked();

private:
    Ui::MarketAnalClass ui;
};
