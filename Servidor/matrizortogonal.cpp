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
            if(cab->anterior == NULL && cab->sigiente == NULL)
            {
                inicio->izquierda = NULL;
            }
            else if(cab->anterior == NULL)
            {
                inicio->izquierda = cab->sigiente;
                cab->sigiente->anterior = NULL;
                cab = NULL;
            }
            else if(cab->sigiente == NULL)
            {
                cab->anterior->sigiente = NULL;
                cab = NULL;
            }
            else
            {
                cab->anterior->sigiente = cab->sigiente;
                cab->sigiente->anterior = cab->anterior;
                cab = NULL;
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
            if(cab->anterior == NULL && cab->sigiente == NULL)
            {
                inicio->abajo = NULL;
            }
            else if(cab->anterior == NULL)
            {
                inicio->abajo = cab->sigiente;
                cab->sigiente->anterior = NULL;
                cab = NULL;
            }
            else if(cab->sigiente == NULL)
            {
                cab->anterior->sigiente = NULL;
                cab = NULL;
            }
            else
            {
                cab->anterior->sigiente = cab->sigiente;
                cab->sigiente->anterior = cab->anterior;
                cab = NULL;
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
    nuevo->abajo = NULL;
    nuevo->arriba = NULL;
    nuevo->derecha = NULL;
    nuevo->izquierda = NULL;
    setPosicionXNodo(*&nuevo,x,y);
    setPosicionYNodo(*&nuevo,y,x);
}

void MatrizOrtogonal::setPosicionXNodo(Nodo *&nod, int x,int y)
{
       CabezeraX *cab = buscarCabeceraX(x);
       Nodo *nop = cab->abajo;
       if(nop == NULL)
       {
           nod->arriba = NULL;
           nod->abajo = NULL;
           cab->abajo = nod;
       }
       else
       {
           bool opt = true;
           while(opt)
           {
               if(nop->y > y)
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
               else if(nop->abajo == NULL)
               {
                   nop->abajo = nod;
                   nod->arriba = nop;
                   break;
               }
               nop = nop->abajo;
           }
       }
}

void MatrizOrtogonal::setPosicionYNodo(Nodo *&nod,int y, int x)
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
            if(nop->x > x)
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
            else if(nop->izquierda == NULL)
            {
                nop->izquierda = nod;
                nod->derecha = nod;
                break;
            }
            nop = nop->izquierda;
        }
    }
}

Nodo *MatrizOrtogonal::buscarNodo(int x, int y)
{
    CabezeraX *cabx = buscarCabeceraX(x);
    if(cabx != NULL)
    {
        Nodo *nod = cabx->abajo;
        if(nod != NULL)
        {
            while(nod != NULL)
            {
                if(nod->x == x && nod->y == y)
                {
                    return nod;
                }
                nod = nod->abajo;
            }
        }
    }
    return NULL;
}

void MatrizOrtogonal::eliminarNodo(int x, int y)
{
    Nodo *nod = buscarNodo(x,y);
    if(nod != NULL)
    {
        eliminarNodoX(*&nod);
        eliminarNodoY(*&nod);
    }
}

void MatrizOrtogonal::eliminarNodoX(Nodo *&nod)
{
    if(nod->arriba == NULL && nod->abajo == NULL)
    {
        eliminarCabecerax(nod->x);
        //nod = NULL;
    }
    else if(nod->arriba == NULL)
    {
        CabezeraX *cabx = buscarCabeceraX(nod->x);
        cabx->abajo = nod->abajo;
        nod->abajo->arriba = NULL;
        //nod = NULL;
    }
    else if(nod->abajo == NULL)
    {
        nod->arriba->abajo = NULL;
        //nod = NULL;
    }
    else
    {
        nod->arriba->abajo = nod->abajo;
        nod->abajo->arriba = nod->arriba;
        //nod = NULL;
    }
}

void MatrizOrtogonal::eliminarNodoY(Nodo *&nod)
{
    if(nod->izquierda == NULL && nod->derecha == NULL)
    {
        eliminarCabeceray(nod->y);
        nod = NULL;
    }
    else if(nod->derecha == NULL)
    {
        CabezeraY *caby = buscarCabeceraY(nod->y);
        caby->izquierda = nod->izquierda;
        nod->izquierda->derecha = NULL;
        nod= NULL;
    }
    else if(nod->izquierda == NULL)
    {
        cout <<"Eliminando nodo Final de la Cabecera Y"<<endl;
        nod->derecha->izquierda = NULL;
        nod = NULL;
    }
    else
    {
        nod->izquierda->derecha = nod->derecha;
        nod->derecha->izquierda = nod->izquierda;
        nod = NULL;
    }
}
void MatrizOrtogonal::menuCab()
{
    incertarNodo(1,1);
    incertarNodo(1,2);
    incertarNodo(3,3);
    incertarNodo(1,3);
    incertarNodo(2,2);
    cout << "Recorriendo cabezera X" << endl;
    recorrerCabX();
    cout << "Recorriendo cabezera y" << endl;
    recorrerCaby();
    cout << "Eliminando Nodo" << endl;
    eliminarNodo(1,2);
    //eliminarNodo(1,3);
    //eliminarNodo(1,1);
    //eliminarNodo(1,2);

    eliminarNodo(2,2);
    cout << "#######ELIMINACION##############"<<endl;
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
