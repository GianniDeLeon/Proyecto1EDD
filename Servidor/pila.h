#ifndef PILA_H
#define PILA_H
#include "enemigo.h"

class Pila
{
public:
    Pila();
    struct Nodo;
    void generarEnemigo();
    void Push(Nodo*);
    Enemigo *Pop();
    bool Vacia();
    void pushEnemigo(Enemigo *en);
protected:
    Nodo *inicioPila;
};

#endif // PILA_H
