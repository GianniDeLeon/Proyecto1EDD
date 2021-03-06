#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H
#include "enemigo.h"
#include "gema.h"
#include <QThread>
#include <QTextEdit>
#include <string>
using namespace std;
class MatrizOrtogonal : public QThread
{
public:
    QTextEdit *texto;
    MatrizOrtogonal(int,QTextEdit *texto);
    void setPausa();
    void setFinHilo();
    int NumImpactos,Punteo;
    struct NodoCheat;
    struct NodoRaiz;
    struct Nodo;
    struct CabezeraX;
    struct CabezeraY;
    struct ListaEnemigos;
    struct ListaGemas;
    void setLimit(int limit);
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
    void incertarGema(Gema *gem);
    ListaGemas *getListaGemas();
    bool atacarNodo(int x, int y);
    void sumarPunteo(int nivel);
    int getPunteo();
    void PilaVacia(Nodo *&nod);
    void generarEnemigo();
    void movertope();
    bool graficarPila(int x, int y);
    void menuCab();
    void recorrerLV1();
    void recorrerLV2();
    void recorrerLV3();
    void recorrerCabX();
    void recorrerNodoX(Nodo *nod);
    void recorrerCaby();
    void recorrerNodoY(Nodo *nod);
    Gema *getGema();
    bool cheat();
    int getContGema();
    void graficarN1();
    void graficarN2();
    void graficarN3();
    void graficarEnemigosEliminados();
    void limpiar();
    void PushCheat(int x, int y);
    NodoCheat *crearNodoCheat(int x, int y);
    NodoCheat *PopCheat();
    void graficarMatriz();
private:
    NodoRaiz *inicio;
    int limit;

protected:
    void run();
};

#endif // MATRIZORTOGONAL_H
