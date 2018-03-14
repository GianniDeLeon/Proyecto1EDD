#ifndef NIVELES_H
#define NIVELES_H
#include "matrizortogonal.h"
#include <QTextEdit>
class Niveles
{
public:
    int tam;
    QTextEdit *texto;
    Niveles(int tam,QTextEdit *texto);
    struct Nodo;
    void crearNiveles();
    Nodo *inicio;
    void setTam(int tam);
    void aumentarTam();
    void Jugar(int nivel);
    MatrizOrtogonal::ListaGemas *ini;
    void stop();
    void graficarNiveles();
    bool atacar(int x, int y);
};

#endif // NIVELES_H
