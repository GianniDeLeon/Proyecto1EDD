#include <iostream>
#include "niveles.h"
#include "matrizortogonal.h"
using namespace std;
typedef struct Niveles::Nodo
{
    bool Lock;
    int nivel;
    MatrizOrtogonal *matriz;
    Nodo *siguiente, *anterior;
}Nodo;

Nodo *Play;

Niveles::Niveles(int tam)
{
    this->tam = tam;
    this->inicio = NULL;
    crearNiveles();
}

void Niveles::crearNiveles()
{
    int i;
    bool lock = false;
    for(i=1;i<=this->tam;i++)
    {
        Nodo *nuevo = new Nodo;
        nuevo->nivel = i;
        nuevo->Lock = lock;
        MatrizOrtogonal *nuevaMa = new MatrizOrtogonal(this->tam);
        nuevo->matriz = nuevaMa;
        if(inicio == NULL)
        {
            nuevo->anterior = NULL;
            nuevo->siguiente = NULL;
            inicio = nuevo;
        }
        else
        {
            inicio->siguiente = nuevo;
            nuevo->anterior = inicio;
            inicio = nuevo;
        }
        lock = true;
    }
}

void Niveles::setTam(int tam)
{
    this->tam = tam;

}

void Niveles::aumentarTam()
{
    int i;
    Nodo *aux = inicio;
    MatrizOrtogonal *mat;
    for(i=1;i<=this->tam;i++)
    {
        if(aux != NULL)
        {
            mat = aux->matriz;
            mat->setLimit(this->tam);
            aux = aux->siguiente;
        }
        else
        {
            Nodo *nuevo = new Nodo;
            nuevo->nivel = i;
            nuevo->Lock = true;
            MatrizOrtogonal *nuevaMa = new MatrizOrtogonal(this->tam);
            nuevo->matriz = nuevaMa;
            inicio->siguiente = nuevo;
            nuevo->anterior = inicio;
            inicio = nuevo;
        }
    }
}

void Niveles::Jugar(int nivel)
{
    Nodo *aux = inicio;
    while(aux != NULL)
    {
        if(aux->nivel == nivel)
        {
            cout << "Nivel:" << nivel << " Encontrado"<<endl;
            if(aux->Lock)
            {
                cout << "Nivel bloqueado"<<endl;
            }
            else
            {
                Play = aux;
                Play->matriz->start();
            }
        }
        aux = aux->anterior;
    }
}
//void Niveles::stop()
//{
//    if(ini != NULL)
//    {
//        struct MatrizOrtogonal::ListaGemas *aux;
//        struct ListaGemas aux = Play->matriz->getListaGemas();
//        if(aux != NULL)
//        {
//            while(aux != NULL)
//            {
//                aux->siguiente = ini;
//                ini = aux;
//                aux = aux->siguiente;
//            }
//        }
//    }
//    else
//    {
//        this->ini = Play->matriz->getListaGemas();
//    }
//}
