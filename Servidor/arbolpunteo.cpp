#include "arbolpunteo.h"
#include <iostream>
//biblioteca para escritura de archivo
#include <fstream>

using namespace std;

typedef struct ArbolPunteo::Nodo
{
    int punteo=0,nivel=0,seg=0,min=0;
    Nodo *izq = NULL;
    Nodo *der = NULL;
}Nodo;

typedef struct ArbolPunteo::Cola
{
    Nodo *nodo;
    Cola *siguiente;
}Cola;

ArbolPunteo::ArbolPunteo()
{
    this->raiz = NULL;
    this->inicio1 = NULL;
    this->inicio2 = NULL;
    this->fin1 = NULL;
    this->fin2 = NULL;
}

void ArbolPunteo::recorridoAnchura()
{
    vaciarColas();
    if(this->raiz != NULL)
        {
            agregarACola(inicio1,fin1,raiz);
            while(inicio1 != NULL)
            {
                Cola *cola;
                cola = sacarCola(inicio1);
                Nodo *aux;
                aux = cola->nodo;
                agregarACola(inicio2,fin2,cola->nodo);
                if(aux->izq != NULL)
                {
                    agregarACola(inicio1,fin1,aux->izq);
                }
                if(aux->der != NULL)
                {
                    agregarACola(inicio1,fin1,aux->der);
                }
            }
            graficarArbol();
        }
}

void ArbolPunteo::graficarArbol()
{
    ofstream ficheroSalida;
    ficheroSalida.open ("arbol.dot");
    ficheroSalida << "digraph Arbol{";
    Cola *inicio = inicio2;
    while(inicio != NULL)
    {
        Nodo *aux;
        aux = inicio->nodo;
        if(aux->der != NULL)
        {
            ficheroSalida << aux->punteo << " -> " << aux->der->punteo << ";\n";
        }
        if(aux->izq != NULL)
        {
            ficheroSalida << aux->punteo << " -> " << aux->izq->punteo << ";\n";
        }
        inicio = inicio->siguiente;
    }
    ficheroSalida << "}";
    ficheroSalida.close();
    system("dot -Tpng arbol.dot -o arbol.png");
    system("nomacs arbol.png");
}

Nodo *ArbolPunteo::crearNodo(int punteo, int nivel, int seg, int min)
{
    Nodo *nuevo = new Nodo;
    nuevo->punteo = punteo;
    nuevo->nivel = nivel;
    nuevo->seg = seg;
    nuevo->min = min;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
}

void ArbolPunteo::incertarEnArbol(int punteo, int nivel, int seg, int min)
{
    incertarNodo(punteo,nivel,seg,min,this->raiz);
}

void ArbolPunteo::incertarNodo(int punteo, int nivel, int seg, int min, Nodo *&root)
{
    if(root == NULL)
        {
            root = crearNodo(punteo,nivel,seg,min);
        }
        else
        {
            if(punteo < root->punteo)
            {
                cout << "Incertando A la Izquierda " << punteo << endl;
                incertarNodo(punteo,nivel,seg,min,root->izq);
            }
            else
            {
                cout << "Incertando A la Derecha " << punteo << endl;
                incertarNodo(punteo,nivel,seg,min,root->der);
            }
        }
}

void ArbolPunteo::agregarACola(Cola *&inicio, Cola *&fin, Nodo *nodo)
{
    Cola *nuevo = new Cola;
    nuevo->nodo = nodo;
    nuevo->siguiente = NULL;
    if(inicio != NULL)
    {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
    else
    {
        inicio = nuevo;
        fin = nuevo;
    }
}

Cola *ArbolPunteo::sacarCola(Cola *&inicio)
{
    Cola *nodo;
    nodo = inicio;
    inicio = inicio->siguiente;
    return nodo;
}

void ArbolPunteo::vaciarColas()
{
    inicio1 = NULL;
    inicio2 = NULL;
}
