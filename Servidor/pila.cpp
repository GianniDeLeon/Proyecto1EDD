#include "pila.h"
#include "enemigo.h"
#include "gema.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct Pila::Nodo
{
    Enemigo *enemi;
    Gema *gem;
    Nodo *siguiente;
}Nodo;

Nodo *inicioPila;

Pila::Pila()
{
    //srand(time(NULL));
    inicioPila = NULL;
}

void Pila::Push(Nodo *nuevo)
{
    nuevo->siguiente = inicioPila;
    inicioPila = nuevo;
}

Enemigo *Pila::Pop()
{
    this->gemPop = NULL;
    Nodo *pop;
    Enemigo *popp = NULL;
    if(inicioPila != NULL)
    {
        pop = inicioPila;
        inicioPila = inicioPila->siguiente;
        popp = pop->enemi;
        this->gemPop = pop->gem;
    }
    return popp;
}

Gema *Pila::getGema()
{
    return this->gemPop;
}
void Pila::generarEnemigo()
{
    int vida,id;
    id = rand()%10000;
    vida = 1 + rand()%(4-1);
    this->gemPop = NULL;
    Enemigo *nuevo = new Enemigo(vida,id);
    //cout << "Id nueva: "<< id << endl;
    //cout << "Vida:" << vida << endl;
    Nodo *newNodo = new Nodo;
    newNodo->enemi = nuevo;
    newNodo->gem = NULL;
    Push(newNodo);
}

void Pila::generarGema()
{
    int id = rand()%10000;
    Gema *nuevo = new Gema(id);
    cout << "Nueva gema ID:" << id << endl;
    Nodo *newNodo = new Nodo;
    newNodo->enemi = NULL;
    newNodo->gem = nuevo;
    Push(newNodo);
}

bool Pila::Vacia()
{
    if(inicioPila == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Pila::pushEnemigo(Enemigo *en)
{
    Nodo *newNodo = new Nodo;
    newNodo->enemi = en;
    Push(newNodo);
}

void Pila::graficarPila()
{
    ofstream ficheroSalida;
    ficheroSalida.open ("/home/mrrobot/Público/MultimediaEDDP1/Pila.dot");
    ficheroSalida << "digraph Pila{\n";
    Nodo *aux = inicioPila;
    while(aux != NULL)
    {
        Enemigo *en = aux->enemi;
        if(en != NULL)
        {
            if(aux->siguiente != NULL)
            {
                ficheroSalida << "EnemigoID"<<en->getId()<<" -> ";
            }
            else
            {
                ficheroSalida << "EnemigoID"<<en->getId()<<";";
            }
        }
        else
        {
            Gema *gem = aux->gem;
            if(aux->siguiente != NULL)
            {
                ficheroSalida << "GemaID"<<gem->id<<" -> ";
            }
            else
            {
                ficheroSalida << "GemaID"<<gem->id<<";";
            }
        }
        aux = aux->siguiente;
    }
    ficheroSalida << "}";
    ficheroSalida.close();
    system("dot -Tpng /home/mrrobot/Público/MultimediaEDDP1/Pila.dot -o /home/mrrobot/Público/MultimediaEDDP1/Pila.png");
    system("nomacs /home/mrrobot/Público/MultimediaEDDP1/Pila.png");
}
