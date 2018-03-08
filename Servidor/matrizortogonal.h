#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H
#include "enemigo.h"

class MatrizOrtogonal
{
public:
    MatrizOrtogonal(int);
    struct NodoRaiz;
    struct Nodo;
    struct CabezeraX;
    struct CabezeraY;
    struct ListaEnemigos;
    CabezeraX *crearCabezerax(int x);
    CabezeraX *incertarCabezeraX(int x);
    CabezeraY *crearCabezeray(int y);
    CabezeraY *incertarCabezeray(int y);
    CabezeraX *buscarCabeceraX(int x);
    CabezeraY *buscarCabeceraY(int y);
    bool eliminarCabecerax(int x);
    bool eliminarCabeceray(int y);
    void incertarNodo(int x, int y);
    void incertarNodo(int x, int y, Enemigo *en);
    void setPosicionXNodo(Nodo *&nod, int x,int y);
    void setPosicionYNodo(Nodo *&nod, int y,int x);
    void eliminarNodo(int x, int y);
    void eliminarNodoX(Nodo *&nod);
    Nodo *buscarNodo(int x, int y);
    void eliminarNodoY(Nodo *&nod);
    void incertarMaloPila(Nodo *&nod);
    void moverTopePila(int xi, int yi);
    void incertarEnemigoLista(ListaEnemigos *&ini, Enemigo *en);
    void atacarNodo(int x, int y);
    void PilaVacia(Nodo *&nod);
    void menuCab();
    void recorrerLV1();
    void recorrerLV2();
    void recorrerLV3();
    void recorrerCabX();
    void recorrerNodoX(Nodo *nod);
    void recorrerCaby();
    void recorrerNodoY(Nodo *nod);
private:
    NodoRaiz *inicio;
    int limit;
};

#endif // MATRIZORTOGONAL_H
