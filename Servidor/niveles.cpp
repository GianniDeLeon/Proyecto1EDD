#include <iostream>
#include "niveles.h"
#include "matrizortogonal.h"
#include <QTextEdit>
#include <fstream>
#include <string>
QTextEdit *texto;
using namespace std;
typedef struct Niveles::Nodo
{
    bool Lock;
    int nivel;
    MatrizOrtogonal *matriz;
    Nodo *siguiente, *anterior;
}Nodo;

Nodo *Play,*Pnivel;

Niveles::Niveles(int tam,QTextEdit *texto)
{
    this->tam = tam;
    this->inicio = NULL;
    this->texto = texto;
    texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Creando niveles");
    crearNiveles();
}

void Niveles::crearNiveles()
{
    int i;
    bool lock = false;
    for(i=1;i<=this->tam;i++)
    {
        Nodo *nuevo = new Nodo;
        nuevo->nivel = i;
        nuevo->Lock = lock;
        MatrizOrtogonal *nuevaMa = new MatrizOrtogonal(this->tam,this->texto);
        nuevo->matriz = nuevaMa;
        if(inicio == NULL)
        {
            nuevo->anterior = NULL;
            nuevo->siguiente = NULL;
            inicio = nuevo;
            Pnivel = nuevo;
        }
        else
        {
            inicio->siguiente = nuevo;
            nuevo->anterior = inicio;
            inicio = nuevo;
        }
        lock = true;
    }
}

void Niveles::setTam(int tam)
{
    texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Cambiando la cantidad de niveles y los limites de las matrices");
    this->tam = tam;
    aumentarTam();
}

void Niveles::aumentarTam()
{
    texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Realizando cambio de tamaño en los niveles");
    int i;
    Nodo *aux = Pnivel;
    MatrizOrtogonal *mat;
    for(i=1;i<=this->tam;i++)
    {
        if(aux != NULL)
        {
            mat = aux->matriz;
            mat->setLimit(this->tam);
            aux = aux->siguiente;
            if(aux != NULL && i == this->tam)
            {
                cout << "Debe ser el ultimo Nivel:"<<aux->nivel<<endl;
                aux->anterior->siguiente = NULL;
            }
        }
        else
        {
            Nodo *nuevo = new Nodo;
            nuevo->nivel = i;
            nuevo->Lock = true;
            MatrizOrtogonal *nuevaMa = new MatrizOrtogonal(this->tam,this->texto);
            nuevo->matriz = nuevaMa;
            inicio->siguiente = nuevo;
            nuevo->anterior = inicio;
            inicio = nuevo;
        }
    }
}

void Niveles::Jugar(int nivel)
{
    texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Iniciando el juego");
    Nodo *aux = inicio;
    while(aux != NULL)
    {
        if(aux->nivel == nivel)
        {
            cout << "Nivel:" << nivel << " Encontrado"<<endl;
            if(aux->Lock)
            {
                cout << "Nivel bloqueado"<<endl;
            }
            else
            {
                Play = aux;
                Play->matriz->start();
            }
        }
        aux = aux->anterior;
    }
}

void Niveles::graficarNiveles()
{
    ofstream ficheroSalida;
    ficheroSalida.open ("niveles.dot");
    ficheroSalida << "digraph niveles{";
    Nodo *aux = Pnivel;
    Nodo *ant = Pnivel;
    string lockan, lockaux;
    while(aux != NULL)
    {
        aux = aux->siguiente;
        if(aux != NULL)
        {
            if(ant->Lock)
            {
                lockan = "Lock";
            }
            else
            {
                lockan = "Unlock";
            }
            if(aux->Lock)
            {
                lockaux = "Lock";
            }
            else
            {
                lockaux = "Unlock";
            }
            ficheroSalida<<lockan<<ant->nivel<< " -> " <<lockaux<<aux->nivel<<";\n";
            ficheroSalida<<lockaux<<aux->nivel<< " -> "<<lockan<<ant->nivel<<";\n";
            ant = aux;
        }
    }
    ficheroSalida << "}";
    ficheroSalida.close();
    system("dot -Tpng niveles.dot -o niveles.png");
    system("nomacs niveles.png");
}

//void Niveles::stop()
//{
//    if(ini != NULL)
//    {
//        struct MatrizOrtogonal::ListaGemas *aux;
//        struct ListaGemas aux = Play->matriz->getListaGemas();
//        if(aux != NULL)
//        {
//            while(aux != NULL)
//            {
//                aux->siguiente = ini;
//                ini = aux;
//                aux = aux->siguiente;
//            }
//        }
//    }
//    else
//    {
//        this->ini = Play->matriz->getListaGemas();
//    }
//}
