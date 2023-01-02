#ifndef MARKETANAL_H
#define MARKETANAL_H

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MarketAnal.h"
#include "Log.h"

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
    app::logger::Log log;
};


#endif // !MARKETANAL_H