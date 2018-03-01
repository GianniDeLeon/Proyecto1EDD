#include "hilogeneracionenemigos.h"
#include "pila.h"

Pila *pila;

HiloGeneracionEnemigos::HiloGeneracionEnemigos()
{
    pila = new Pila();
}

void HiloGeneracionEnemigos::run()
{
    while (true) {
       pila->generarEnemigo();
       msleep(8000);
    }
}
