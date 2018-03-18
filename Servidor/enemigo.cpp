#include "enemigo.h"

Enemigo::Enemigo(int vida, int id)
{
    switch (vida) {
    case 1:
            this->vida = 1;
        break;
    case 2:
            this->vida = 3;
        break;
    case 3:
        this->vida = 5;
        break;
    default:
        this->vida = 5;
        break;
    }
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
