#include "matrizortogonal.h"
#include "pila.h"
#include <iostream>
using namespace std;

typedef struct MatrizOrtogonal::Nodo
{
    Pila *pila;
    Nodo *arriba, *abajo, *derecha, *izquierda;
    int x,y;
}Nodo;

typedef struct MatrizOrtogonal::CabezeraX
{
    int x;
    CabezeraX *sigiente, *anterior;
    Nodo *abajo;
}CabezeraX;

typedef struct MatrizOrtogonal::CabezeraY
{
    int y;
    CabezeraY *sigiente, *anterior;
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

CabezeraX *MatrizOrtogonal::incertarCabezeraX(int x)
{
    CabezeraX *cab;
    cab = inicio->izquierda;
    if(cab == NULL)
    {
        cab = crearCabezerax(x);
        cab->anterior = NULL;
        cab->sigiente = NULL;
        inicio->izquierda = cab;
        return cab;
    }
    else
    {
        bool opt=true;
        CabezeraX *nueva;
        while(opt)
        {
            if(cab->x > x)
            {
                nueva = crearCabezerax(x);
                if(cab->anterior == NULL)
                {
                    inicio->izquierda = nueva;
                    nueva->sigiente = cab;
                    cab->anterior = nueva;
                }
                else
                {
                    cab->anterior->sigiente = nueva;
                    nueva->anterior = cab->anterior;
                    cab->anterior = nueva;
                    nueva->sigiente = cab;
                }
                opt = false;
                return nueva;
            }
            else if(cab->sigiente == NULL)
            {
                nueva = crearCabezerax(x);
                cab->sigiente = nueva;
                nueva->anterior = cab;
                nueva->sigiente = NULL;
                opt = false;
                return nueva;
            }
            cab = cab->sigiente;
        }
    }
}

CabezeraX *MatrizOrtogonal::crearCabezerax(int x)
{
    CabezeraX *nueva = new CabezeraX;
    nueva->abajo = NULL;
    nueva->x = x;
    return nueva;
}

CabezeraY *MatrizOrtogonal::incertarCabezeray(int y)
{
    CabezeraY *cab;
    cab = inicio->abajo;
    if(cab == NULL)
    {
        cab = crearCabezeray(y);
        cab->anterior = NULL;
        cab->sigiente = NULL;
        inicio->abajo = cab;
        return cab;
    }
    else
    {
        bool opt=true;
        CabezeraY *nueva;
        while(opt)
        {
            if(cab->y > y)
            {
                nueva = crearCabezeray(y);
                if(cab->anterior == NULL)
                {
                    inicio->abajo = nueva;
                    nueva->sigiente = cab;
                    cab->anterior = nueva;
                }
                else
                {
                    cab->anterior->sigiente = nueva;
                    nueva->anterior = cab->anterior;
                    cab->anterior = nueva;
                    nueva->sigiente = cab;
                }
                opt = false;
                return nueva;
            }
            else if(cab->sigiente == NULL)
            {
                nueva = crearCabezeray(y);
                cab->sigiente = nueva;
                nueva->anterior = cab;
                nueva->sigiente = NULL;
                opt = false;
                return nueva;
            }
            cab = cab->sigiente;
        }
    }
}

CabezeraY *MatrizOrtogonal::crearCabezeray(int y)
{
    CabezeraY *nueva = new CabezeraY;
    nueva->y = y;
    nueva->izquierda = NULL;
    return nueva;
}

bool MatrizOrtogonal::eliminarCabecerax(int x)
{
    CabezeraX *cab;
    cab = inicio->izquierda;
    while(cab != NULL)
    {
        if(cab->x == x)
        {
            if(cab->anterior == NULL)
            {
                inicio->izquierda = NULL;
            }
            else
            {
                CabezeraX *aux;
                aux = cab->anterior;
                aux->sigiente = cab->sigiente;
                cab->sigiente->anterior = aux;
            }
            return true;
        }
        cab = cab->sigiente;
    }
    return false;
}

bool MatrizOrtogonal::eliminarCabeceray(int y)
{
    CabezeraY *cab;
    cab = inicio->abajo;
    while (cab != NULL)
    {
        if(cab->y ==y)
        {
            if(cab->anterior == NULL)
            {
                inicio->abajo = NULL;
            }
            else
            {
                CabezeraY *aux;
                aux = cab->anterior;
                aux->sigiente = cab->sigiente;
                cab->sigiente->anterior = aux;
            }
            return true;
        }
        cab = cab->sigiente;
    }
    return false;
}

CabezeraX *MatrizOrtogonal::buscarCabeceraX(int x)
{
    CabezeraX *cab;
    cab = inicio->izquierda;
    while(cab != NULL)
    {
        if(cab->x == x)
        {
            return cab;
        }
        cab = cab->sigiente;
    }
    return incertarCabezeraX(x);
}

CabezeraY *MatrizOrtogonal::buscarCabeceraY(int y)
{
    CabezeraY *cab;
    cab = inicio->abajo;
    while(cab != NULL)
    {
        if(cab->y == y)
        {
            return cab;
        }
        cab = cab->sigiente;
    }
    return incertarCabezeray(y);
}

void MatrizOrtogonal::incertarNodo(int x, int y)
{
    Nodo *nuevo = new Nodo;
    Pila *pil = new Pila;
    pil->generarEnemigo();
    nuevo->pila = pil;
    nuevo->x = x;
    nuevo->y = y;
    cout << "Enviando a posicionar el nodo en x" << endl;
    setPosicionXNodo(*&nuevo,x);
    cout << "Enviando a posicionar el nodo en y" << endl;
    setPosicionYNodo(*&nuevo,y);
}

void MatrizOrtogonal::setPosicionXNodo(Nodo *&nod, int x)
{
       CabezeraX *cab = buscarCabeceraX(x);
       cout << "Cabezera retornadaX: "<<cab->x << endl;
       Nodo *nop = cab->abajo;
       if(nop == NULL)
       {
           nod->arriba = NULL;
           nod->abajo = NULL;
           cab->abajo = nod;
       }
       else
       {
           cout << "Nodo retornado X:"<<nop->x<<" Y:"<<nop->y<<endl;
           bool opt = true;
           while(opt)
           {
               //ndo x igual problema...
               cout << "Nodo X:"<<nop->x<<" =X:"<<x<<endl;
               if(nop->x > x)
               {
                   if(nop->arriba == NULL)
                   {
                       nop->arriba = nod;
                       nod->abajo = nop;
                       cab->abajo = nod;
                   }
                   else
                   {
                       nop->arriba->abajo = nod;
                       nod->arriba = nop->arriba;
                       nod->abajo = nop;
                       nop->arriba = nod;
                   }
                   opt = false;
                   break;
               }
               nop = nop->abajo;
           }
       }
}

void MatrizOrtogonal::setPosicionYNodo(Nodo *&nod,int y)
{
    CabezeraY *cab = buscarCabeceraY(y);
    Nodo *nop = cab->izquierda;
    if(nop == NULL)
    {
        nod->izquierda = NULL;
        nod->derecha = NULL;
        cab->izquierda = nod;
    }
    else
    {
        bool opt = true;
        while(opt)
        {
            if(nop->y > y)
            {
                if(nop->derecha == NULL)
                {
                    nop->derecha = nod;
                    nod->izquierda = nop;
                    cab->izquierda = nod;
                }
                else
                {
                    nop->izquierda->derecha = nod;
                    nod->izquierda = nop->izquierda;
                    nod->derecha = nop;
                    nop->izquierda = nod;
                }
                break;
            }
            nop = nop->izquierda;
        }
    }
}

void MatrizOrtogonal::menuCab()
{
    incertarNodo(1,1);
    incertarNodo(1,2);
    //incertarNodo(3,3);
    //incertarNodo(1,3);
    incertarNodo(2,2);
    cout << "Recorriendo cabezera X" << endl;
    recorrerCabX();
    cout << "Recorriendo cabezera y" << endl;
    recorrerCaby();
}

void MatrizOrtogonal::recorrerCabX()
{
    CabezeraX *cab;
    cab = inicio->izquierda;
    while(cab != NULL)
    {
        cout << "Indice de la cabezeraX: " << cab->x << endl;
        recorrerNodoX(cab->abajo);
        cab = cab->sigiente;
    }
}

void MatrizOrtogonal::recorrerNodoX(Nodo *nod)
{
    while(nod != NULL)
    {
        cout << "Nodo posX:" << nod->x << " posY:" << nod->y << endl;
        nod = nod->abajo;
    }
}

void MatrizOrtogonal::recorrerNodoY(Nodo *nod)
{
    while(nod != NULL)
    {
        cout << "Nodo posX:" << nod->x << " posY:" << nod->y << endl;
        nod = nod->izquierda;
    }
}

void MatrizOrtogonal::recorrerCaby()
{
    CabezeraY *cab;
    cab = inicio->abajo;
    while(cab != NULL)
    {
        cout << "Indice de la cabezeraY: " << cab->y << endl;
        recorrerNodoY(cab->izquierda);
        cab = cab->sigiente;
    }
}
