#ifndef ARBOLPUNTEO_H
#define ARBOLPUNTEO_H


class ArbolPunteo
{
public:
    ArbolPunteo();
    struct Cola;
    struct Nodo;
    Nodo *raiz;
    Cola *inicio1,*fin1,*inicio2,*fin2;
    Nodo *crearNodo(int punteo, int nivel, int seg, int min);
    void incertarNodo(int punteo, int nivel, int seg, int min, Nodo *&root);
    void recorridoAnchura();
    void graficarArbol();
    void agregarACola(Cola *&inicio,Cola *&fin, Nodo *nodo);
    Cola *sacarCola(Cola *&inicio);

    void incertarEnArbol(int punteo, int nivel, int seg, int min);
};

#endif // ARBOLPUNTEO_H
