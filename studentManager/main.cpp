#include "addstu.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
//    addStu w;
//    w.show();
    return a.exec();
}
