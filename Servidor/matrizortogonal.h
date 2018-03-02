#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H


class MatrizOrtogonal
{
public:
    struct NodoRaiz;
    struct Nodo;
    struct CabezeraX;
    struct CabezeraY;
    MatrizOrtogonal(int);
    void incertarNodo(int,int);
    CabezeraX *incertarCabezeraX(CabezeraX *, int);
    CabezeraX *crearCabezeraX(CabezeraX *,int);
    CabezeraY *crearCabezeraY(CabezeraY *,int);
    CabezeraY *incertarCabezeraY(CabezeraY *, int);
    CabezeraX *buscarCabezeraX(int);
    CabezeraY *buscarCabezeraY(int);
private:
    NodoRaiz *inicio;
    int limit;
};

#endif // MATRIZORTOGONAL_H
