#ifndef PILA_H
#define PILA_H


class Pila
{
public:
    Pila();
    void generarEnemigo();
    void Push(Nodo);
    Nodo *Pop();
protected:
    struct Nodo;
    Nodo *inicioPila;
};

#endif // PILA_H
