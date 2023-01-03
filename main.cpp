#include "MainApp/MarketAnal.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MarketAnal w;

    w.show();

    return a.exec();
}
