#include "matrizortogonal.h"
#include "pila.h"
#include "enemigo.h"
#include <iostream>
#include<time.h>
#include "gema.h"
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

typedef struct MatrizOrtogonal::ListaEnemigos
{
    Enemigo *enemigo;
    ListaEnemigos *siguiente;
}ListaEnemigos;

typedef struct MatrizOrtogonal::ListaGemas
{
    Gema *gem;
    ListaGemas *siguiente;
}ListaGemas;

ListaEnemigos *LV1=NULL,*LV2=NULL,*LV3=NULL;
ListaGemas *LG=NULL;
NodoRaiz *inicio=NULL;
int limit;

MatrizOrtogonal::MatrizOrtogonal(int limit,QTextEdit *texto)
{
    this->limit = limit;
    this->NumImpactos =0;
    this->texto = texto;
    inicio = new NodoRaiz;
    inicio->abajo = NULL;
    inicio->izquierda = NULL;
}

void MatrizOrtogonal::setLimit(int limit)
{
    this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Cambiando los limites de la matrizOrtogonal");
    this->limit = limit;
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
    return NULL;
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
    return NULL;
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
    //cout << "Setiando posicion X"<<endl;
    setPosicionXNodo(*&nuevo,x,y);
    //cout << "Setiando posicion Y"<<endl;
    setPosicionYNodo(*&nuevo,y,x);
}

void MatrizOrtogonal::incertarNodo(int x, int y, Enemigo *en)
{
    Nodo *nuevo = new Nodo;
    Pila *pil = new Pila;
    pil->pushEnemigo(en);
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
                    nod->derecha = NULL;
                    cab->izquierda = nod;
                }
                else
                {
                    nop->derecha->izquierda = nod;
                    nod->izquierda = nop;
                    nod->derecha = nop->derecha;
                    nop->derecha = nod;
                }
                break;
            }
            else if(nop->izquierda == NULL)
            {
                nop->izquierda = nod;
                nod->derecha = nop;
                nod->izquierda = NULL;
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
    this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Nodo eliminado de la matriz");
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
        //cout <<"Eliminando nodo Final de la Cabecera Y"<<endl;
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

void MatrizOrtogonal::incertarMaloPila(Nodo *&nod)
{
    //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Generando enemigo en tope de pila");
    Pila *pill = *&nod->pila;
    pill->generarEnemigo();
}

void MatrizOrtogonal::moverTopePila(int xi, int yi)
{
    //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Moviendo tope de pila");
    Nodo *nod = buscarNodo(xi,yi);
    if(nod != NULL)
    {
        Enemigo *en = nod->pila->Pop();
        if(en != NULL)
        {
            int movimiento = 1 + rand()%(4-1);
            //cout <<"Moviendo tope de pila de X:"<<nod->x<<" Y:"<<nod->y<<" Random:"<<movimiento<<endl;
            Nodo *nodaux;
            int y=0,x=0;
            switch (movimiento) {
            case 1:
                    //Movimiento hacia arriba
                if(nod->y > 1)
                {
                    y = nod->y -1;
                    x = nod->x;
                    nodaux = buscarNodo(x,y);
                    if(nodaux != NULL)
                    {
                        nodaux->pila->pushEnemigo(en);
                    }
                    else
                    {
                        incertarNodo(x,y,en);
                    }
                }
                else
                {
                    //moverTopePila(xi,yi);
                }
                break;
            case 2:
                    //Movimiento hacia abajo
                if(nod->y < limit)
                {
                    y = nod->y + 1;
                    x = nod->x;
                    nodaux = buscarNodo(x,y);
                    if(nodaux != NULL)
                    {
                        nodaux->pila->pushEnemigo(en);
                    }
                    else
                    {
                        incertarNodo(x,y,en);
                    }
                }
                else
                {
                    //moverTopePila(xi,yi);
                }
                break;
            case 3:
                    //Moviminto hacia la derecha
                if(nod->x > 1)
                {
                    y = nod->y;
                    x = nod->x -1;
                    nodaux = buscarNodo(x,y);
                    if(nodaux != NULL)
                    {
                        nodaux->pila->pushEnemigo(en);
                    }
                    else
                    {
                        incertarNodo(x,y,en);
                    }
                }
                else
                {
                    //moverTopePila(xi,yi);
                }
                break;
            case 4:
                    //Movimiento hacia la izquierda
                if(nod->x < limit)
                {
                    y = nod->y;
                    x = nod->x +1;
                    nodaux = buscarNodo(x,y);
                    if(nodaux != NULL)
                    {
                        nodaux->pila->pushEnemigo(en);
                    }
                    else
                    {
                        incertarNodo(x,y,en);
                    }
                }
                else
                {
                   //moverTopePila(xi,yi);
                }
                break;
            default:
                break;
            }
            //cout << "Movimiento tope de pila de X:"<<nod->x<<" Y:"<<nod->y<<" a X:"<<x<<" Y:"<<y<<endl;
        }
        else
        {
            eliminarNodo(xi,yi);
        }
    }
    else
    {
        //cout << "No se movio tope de pila puesto que el nodo no existe"<<endl;
    }
}

void MatrizOrtogonal::incertarEnemigoLista(ListaEnemigos *&ini, Enemigo *en)
{
    this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Incertando enemigo en lista de eliminados");
    ListaEnemigos *nuevo = new ListaEnemigos;
    nuevo->enemigo = en;
    if(ini == NULL)
    {
        nuevo->siguiente= NULL;
        ini = nuevo;
    }
    else
    {
        nuevo->siguiente = ini;
        ini = nuevo;
    }
}

void MatrizOrtogonal::incertarGema(Gema *gem)
{
    this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Incertando gema en lista de gemas");
    ListaGemas *nuevo = new ListaGemas;
    nuevo->gem = gem;
    nuevo->siguiente = LG;
    LG = nuevo;
}

ListaGemas *MatrizOrtogonal::getListaGemas()
{
    return LG;
}

bool MatrizOrtogonal::atacarNodo(int x, int y)
{
    cout << "Iniciando el ataque en X:"<<x<<" Y:"<<y<<endl;
    //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Atacando nodo");
    Nodo *nod = buscarNodo(x,y);
    if(nod != NULL)
    {
        this->NumImpactos ++;
        Pila *pill = nod->pila;
        Enemigo *en = pill->Pop();
        if(en != NULL)
        {
            cout << "Atacando en la posicion X:"<<x<<" Y:"<<y<<endl;
            int vida = en->impacto();
            cout << "Vida restante del enemigo "<<vida<<" Nivel:"<<en->getNivel()<<endl;
            if(this->NumImpactos == 5)
            {
                //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ 5 impactos generando gema");
                this->NumImpactos = 0;
                pill->generarGema();
            }
            if(vida == 0)
            {
                //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Enemigo eliminado");
                switch (en->getNivel()) {
                case 1:
                    //cout << "Incertando en nivel 1"<<endl;
                    incertarEnemigoLista(*&LV1,en);

                    break;
                case 2:
                    //cout << "Incertando en nivel 2"<<endl;
                    incertarEnemigoLista(*&LV2,en);
                    break;
                case 3:
                    //cout << "Incertando en nivel 3"<<endl;
                    incertarEnemigoLista(*&LV3,en);
                    break;
                default:
                    break;
                }
                PilaVacia(*&nod);
            }
            else
            {
                pill->pushEnemigo(en);
            }
        }
        else
        {
            Gema *gem = pill->getGema();
            incertarGema(gem);
        }
        return true;
    }
    else
    {
        NumImpactos =0;
        return false;
    }
}

void MatrizOrtogonal::PilaVacia(Nodo *&nod)
{
    //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Pila vacia eliminando");
    Pila *pil = nod->pila;
    if(pil->Vacia())
    {
        eliminarNodo(nod->x,nod->y);
    }
}

void MatrizOrtogonal::run()
{
    while(true)
    {
        //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Moviendo Tope de Pila");
        movertope();
        msleep(4000);
        movertope();
        msleep(4000);
        generarEnemigo();
    }
}

void MatrizOrtogonal::generarEnemigo()
{
    int x,y;
    //cout << "Generando coordenadas aleatorias para incertar nodo"<<endl;
    x = 1 + rand()%(limit-1);
    y = 1 + rand()%(limit-1);
    //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Incertando Nodo o Generando enemigo");
    Nodo *nod = buscarNodo(x,y);
    if(nod != NULL)
    {
        //cout << "Nodo ya existente se generara malo en dicha posicion"<<endl;
        incertarMaloPila(*&nod);
    }
    else
    {
        //cout << "Incertando nodo"<<endl;
        incertarNodo(x,y);
    }
    //cout << "Generando coordenadas aleatorias para Mover tope de pila"<<endl;
}

void MatrizOrtogonal::movertope()
{
    int x,y;
    x = 1 + rand()%(limit-1);
    y = 1 + rand()%(limit-1);
    //cout << "Moviendo Tope de pila en X:"<<x<<" Y:"<<y<<endl;
    //this->texto->setText(this->texto->toPlainText() + "\n201503823@Gianni:~ Moviendo tope de pila");
    moverTopePila(x,y);
}

void MatrizOrtogonal::menuCab()
{
    incertarNodo(1,1);
    incertarNodo(1,2);
    incertarNodo(3,3);
    incertarNodo(1,3);
    incertarNodo(2,2);
    //cout << "Mover tope de pila"<<endl;
    moverTopePila(1,1);
    cout << "Atacando Nodo"<<endl;
    atacarNodo(1,2);
    atacarNodo(1,2);
    cout << "Recorriendo Lista de enemigos"<<endl;
    recorrerLV1();
    recorrerLV2();
    recorrerLV3();
//    cout << "Recorriendo cabezera X" << endl;
//    recorrerCabX();
//    cout << "Recorriendo cabezera y" << endl;
//    recorrerCaby();
//    cout << "Eliminando Nodo" << endl;
//    eliminarNodo(1,2);
//    //eliminarNodo(1,3);
//    //eliminarNodo(1,1);
//    //eliminarNodo(1,2);

//    eliminarNodo(2,2);
//    cout << "#######ELIMINACION##############"<<endl;
//    cout << "Recorriendo cabezera X" << endl;
//    recorrerCabX();
//    cout << "Recorriendo cabezera y" << endl;
//    recorrerCaby();

}

void MatrizOrtogonal::recorrerLV1()
{
    ListaEnemigos *aux = LV1;
    while(aux != NULL)
    {
        Enemigo *en = aux->enemigo;
        cout << "Enemigo ID:"<<en->getId()<<" Nivel:"<<en->getNivel()<<endl;
        aux = aux->siguiente;
    }
}

void MatrizOrtogonal::recorrerLV2()
{
    ListaEnemigos *aux = LV2;
    while(aux != NULL)
    {
        Enemigo *en = aux->enemigo;
        cout << "Enemigo ID:"<<en->getId()<<" Nivel:"<<en->getNivel()<<endl;
        aux = aux->siguiente;
    }
}

void MatrizOrtogonal::recorrerLV3()
{
    ListaEnemigos *aux = LV3;
    while(aux != NULL)
    {
        Enemigo *en = aux->enemigo;
        cout << "Enemigo ID:"<<en->getId()<<" Nivel:"<<en->getNivel()<<endl;
        aux = aux->siguiente;
    }
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
