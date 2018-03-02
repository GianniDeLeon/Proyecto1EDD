#include "matrizortogonal.h"
#include "pila.h"

typedef struct MatrizOrtogonal::Nodo
{
    Pila *pila;
    Nodo *arriba, *abajo, *derecha, *izquierda;
}Nodo;

typedef struct MatrizOrtogonal::CabezeraX
{
    int x;
    CabezeraX *sigiente;
    Nodo *abajo;
}CabezeraX;

typedef struct MatrizOrtogonal::CabezeraY
{
    int y;
    CabezeraY *siguiente;
    Nodo *izquierda;
}CabezeraY;

typedef struct MatrizOrtogonal::NodoRaiz
{
    CabezeraX *izquierda;
    CabezeraY *abajo;
}NodoRaiz;

NodoRaiz *inicio;
int limit;

MatrizOrtogonal::MatrizOrtogonal(int limit)
{
    this->limit = limit;
    inicio = new NodoRaiz;
    inicio->abajo = NULL;
    inicio->izquierda = NULL;
}

CabezeraX *MatrizOrtogonal::incertarCabezeraX(CabezeraX *cab ,int x)
{
    if(cab == NULL)
    {
        return crearCabezeraX(NULL,x);
    }
    else
    {
        if(cab->x < x)
        {
            incertarCabezeraX(&cab->sigiente,x);
        }
        else
        {
            return crearCabezeraX(&cab,x);
        }
    }
}

CabezeraX *MatrizOrtogonal::crearCabezeraX(CabezeraX sig, int x)
{
    CabezeraX *nuevo = new CabezeraX;
    nuevo->abajo = NULL;
    nuevo->sigiente = sig;
    nuevo->x = x;
    sig = nuevo;
    return sig;
}

CabezeraY *MatrizOrtogonal::incertarCabezeraY(CabezeraY *cab,int y)
{
    if(cab == NULL)
    {
        return crearCabezeraY(NULL,y);
    }
    else
    {
        if(cab->y < y)
        {
            incertarCabezeraY(&cab->sigiente,y);
        }
        else
        {
            return crearCabezeraY(&cab,y);
        }
    }
}

CabezeraY *MatrizOrtogonal::crearCabezeraY(CabezeraY *sig,int y)
{
    CabezeraY *nuevo = new CabezeraY;
    nuevo->siguiente = sig;
    nuevo->izquierda = NULL;
    nuevo->y = y;
    sig = nuevo;
    return sig;
}

CabezeraX *MatrizOrtogonal::buscarCabezeraX(int x)
{
    CabezeraX *nodo = inicio->izquierda;
    while (nodo != NULL) {
        if(nodo->x == x)
        {
            return nodo;
        }
        nodo = nodo->sigiente;
    }
    return NULL;
}

CabezeraY *MatrizOrtogonal::buscarCabezeraY(int y)
{
    CabezeraY *nodo = inicio->abajo;
    while (nodo != NULL)
    {
        if(nodo->y == y)
        {
            return nodo;
        }
        nodo = nodo->siguiente;
    }
    return NULL;
}

void MatrizOrtogonal::incertarNodo(int x, int y)
{
    if(x <= limit && y <= limit)
    {
        CabezeraX cabX;
        cabX = buscarCabezeraX(x);
        if(cabX == NULL)
        {
            cabX = incertarCabezeraX(&inicio->izquierda,x);
        }
        CabezeraY cabY;
        cabY = buscarCabezeraY(y);
        if(cabY == NULL)
        {
            cabY = incertarCabezeraY(&inicio->abajo,y);
        }

    }
}

