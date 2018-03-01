#include "mainwindow.h"
#include <QApplication>
#include "hilogeneracionenemigos.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    HiloGeneracionEnemigos *gen = new HiloGeneracionEnemigos();
    gen->start();
    return a.exec();
}
