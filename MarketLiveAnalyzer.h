#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include <qdebug.h>

class MarketLiveAnalyzer : public QMainWindow
{
    Q_OBJECT

public:
    MarketLiveAnalyzer(QWidget *parent = nullptr);
    ~MarketLiveAnalyzer();

private slots:
    void on_testBtn_clicked();

private:
    Ui::QtWidgetsApplication1Class ui;
};
