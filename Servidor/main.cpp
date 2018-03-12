#include "mainwindow.h"
#include <QApplication>
#include "niveles.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    Niveles *nivel = new Niveles(8);
    nivel->Jugar(1);
//    MatrizOrtogonal *matriz = new MatrizOrtogonal(10);
//    matriz->menuCab();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
