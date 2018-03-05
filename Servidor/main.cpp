#include "mainwindow.h"
#include <QApplication>
#include "hilogeneracionenemigos.h"
#include "matrizortogonal.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    MatrizOrtogonal *matriz = new MatrizOrtogonal(10);
    matriz->menuCab();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
