#include "MarketAnal.h"
#include <QtWidgets/QApplication>
#include "Log.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MarketAnal w;
    app::logger::dbgIn("Main: ", "HELLO", "WORLD", 42);

    w.show();

    return a.exec();
}
