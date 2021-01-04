#include "widget.h"
#include <QApplication>
//#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
//    w.setStyle(QStyleFactory::create("windows"));
    w.setWindowTitle("Randomizer");
    w.show();

    return a.exec();
}
