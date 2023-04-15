#include "mainwindowf.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowF w;
    w.show();
    return a.exec();
}
