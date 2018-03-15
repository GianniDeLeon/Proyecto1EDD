#ifndef PILA_H
#define PILA_H
#include "enemigo.h"
#include "gema.h"
class Pila
{
public:
    Pila();
    Gema *gemPop;
    Gema *getGema();
    struct Nodo;
    void generarEnemigo();
    void generarGema();
    void Push(Nodo*);
    Enemigo *Pop();
    bool Vacia();
    void pushEnemigo(Enemigo *en);
    void graficarPila();
protected:
    Nodo *inicioPila;
};

#endif // PILA_H
