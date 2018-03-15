#include "usuario.h"
#include "arbolpunteo.h"
#include <string>
using namespace std;

Usuario::Usuario(string nombre)
{
    this->nombre = nombre;
    this->arbol = new ArbolPunteo;
}

void Usuario::incertarNodoArbol()
{
    arbol->incertarEnArbol(this->punteo,this->nivel,this->seg,this->min);
}
