#ifndef USUARIO_H
#define USUARIO_H
#include "arbolpunteo.h"
#include <string>
#include "gema.h"
using namespace std;
class Usuario
{
public:
    struct ListaGemas;
    int punteo,nivel,seg,min,cantGema;
    string nombre;
    ArbolPunteo *arbol;
    Usuario(string nombre);
    void incertarNodoArbol();
    void incertarGema(Gema *gem);
    Gema *popGema();
};

#endif // USUARIO_H
