#ifndef NIVELES_H
#define NIVELES_H
#include "matrizortogonal.h"

class Niveles
{
public:
    int tam;
    Niveles(int tam);
    struct Nodo;
    void crearNiveles();
    Nodo *inicio;
    void setTam(int tam);
    void aumentarTam();
    void Jugar(int nivel);
    MatrizOrtogonal::ListaGemas *ini;
    void stop();
};

#endif // NIVELES_H
