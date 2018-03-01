#include "pila.h"
#include "enemigo.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>
using namespace std;

typedef struct Pila::Nodo
{
    Enemigo *enemi;
    Nodo *siguiente;
}Nodo;

Nodo *inicioPila=NULL;

Pila::Pila()
{
    srand(time(NULL));
}

void Pila::Push(Nodo *nuevo)
{
    nuevo->siguiente = inicioPila;
    inicioPila = nuevo;
}

Nodo *Pila::Pop()
{
    Nodo *pop;
    pop = inicioPila;
    inicioPila = inicioPila->siguiente;
    return pop;
}

void Pila::generarEnemigo()
{
    int vida,id;
    id = rand()%10000;
    vida = 1 + rand()%(4-1);
    Enemigo *nuevo = new Enemigo(vida,id);
    cout << "Id nueva: "<< nuevo->getId() << endl;
    cout << "Vida:" << nuevo->getVida() << endl;
    Nodo *newNodo = new Nodo;
    newNodo->enemi = nuevo;
    Push(newNodo);
}


