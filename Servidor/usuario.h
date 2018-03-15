#ifndef USUARIO_H
#define USUARIO_H
#include "arbolpunteo.h"
#include <string>
using namespace std;
class Usuario
{
public:
    int punteo,nivel,seg,min;
    string nombre;
    ArbolPunteo *arbol;
    Usuario(string nombre);
    void incertarNodoArbol();
};

#endif // USUARIO_H
