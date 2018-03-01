#ifndef PILA_H
#define PILA_H


class Pila
{
public:
    Pila();
    struct Nodo;
    void generarEnemigo();
    void Push(Nodo*);
    Nodo *Pop();

protected:
    Nodo *inicioPila;
};

#endif // PILA_H
