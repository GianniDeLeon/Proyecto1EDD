#include "enemigo.h"

Enemigo::Enemigo(int vida, int id)
{
    this->vida = vida;
    this->id = id;
    this->nivel = vida;
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

int Enemigo::getNivel()
{
    return nivel;
}
