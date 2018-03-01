#include "enemigo.h"

Enemigo::Enemigo(int vida, int id)
{
    this->vida = vida;
    this->id = id;
}

int Enemigo::impacto()
{
    vida --;
    return vida;
}

int Enemigo::getId()
{
    return id;
}

int Enemigo::getVida()
{
    return vida;
}
