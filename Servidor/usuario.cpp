#include "usuario.h"
#include "arbolpunteo.h"
#include <string>
#include "gema.h"
using namespace std;

typedef struct Usuario::ListaGemas
{
    Gema *gem;
    ListaGemas *siguiente;
}ListaGemas;

ListaGemas *InLgem=NULL;

Usuario::Usuario(string nombre)
{
    this->nombre = nombre;
    this->arbol = new ArbolPunteo;
    this->cantGema = 0;
}

void Usuario::incertarNodoArbol()
{
    arbol->incertarEnArbol(this->punteo,this->nivel,this->seg,this->min);
}

void Usuario::incertarGema(Gema *gem)
{
    cantGema ++;
    ListaGemas *nuevo = new ListaGemas;
    nuevo->gem = gem;
    nuevo->siguiente = InLgem;
    InLgem = nuevo;
}

Gema *Usuario::popGema()
{
    if(InLgem != NULL)
    {
        Gema *gemapop = InLgem->gem;
        InLgem = InLgem->siguiente;
        cantGema --;
        return gemapop;
    }
    else
    {
        return NULL;
    }
}
