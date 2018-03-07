#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H


class MatrizOrtogonal
{
public:
    MatrizOrtogonal(int);
    struct NodoRaiz;
    struct Nodo;
    struct CabezeraX;
    struct CabezeraY;
    CabezeraX *crearCabezerax(int x);
    CabezeraX *incertarCabezeraX(int x);
    CabezeraY *crearCabezeray(int y);
    CabezeraY *incertarCabezeray(int y);
    CabezeraX *buscarCabeceraX(int x);
    CabezeraY *buscarCabeceraY(int y);
    bool eliminarCabecerax(int x);
    bool eliminarCabeceray(int y);
    void incertarNodo(int x, int y);
    void setPosicionXNodo(Nodo *&nod, int x,int y);
    void setPosicionYNodo(Nodo *&nod, int y,int x);
    void eliminarNodo(int x, int y);
    void eliminarNodoX(Nodo *&nod);
    Nodo *buscarNodo(int x, int y);
    void eliminarNodoY(Nodo *&nod);
    void menuCab();
    void recorrerCabX();
    void recorrerNodoX(Nodo *nod);
    void recorrerCaby();
    void recorrerNodoY(Nodo *nod);
private:
    NodoRaiz *inicio;
    int limit;
};

#endif // MATRIZORTOGONAL_H
