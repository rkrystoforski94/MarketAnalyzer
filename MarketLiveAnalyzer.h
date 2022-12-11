#pragma once

#include <QtWidgets/QWidget>
#include "ui_MarketLiveAnalyzer.h"
#include <QDebug>

class MarketLiveAnalyzer : public QWidget
{
    Q_OBJECT

public:
    MarketLiveAnalyzer(QWidget *parent = nullptr);
    ~MarketLiveAnalyzer();

private:
    Ui::MarketLiveAnalyzerClass ui;

    void on_show_market_clicked();
};
