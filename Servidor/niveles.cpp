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
    int nivel,punteoG;
    MatrizOrtogonal *matriz;
    Nodo *siguiente, *anterior;
}Nodo;
typedef struct Niveles::LisUsuario
{
    Usuario *usr;
    LisUsuario *siguiente;
}LisUsuario;

Nodo *Play,*Pnivel;
Usuario *jugando;
LisUsuario *inicioLisUsu;

Niveles::Niveles(int tam,QTextEdit *texto)
{
    this->tam = tam;
    this->min = 0;
    this->seg = 0;
    this->punteo = 0;
    this->inicio = NULL;
    this->texto = texto;
    Play = NULL;
    this->jugando = NULL;
    this->inicioLisUsu = NULL;
    texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Creando niveles");
    crearNiveles();
}

void Niveles::crearNiveles()
{
    int i,puntos = 80;
    bool lock = false;
    for(i=1;i<=this->tam;i++)
    {
        Nodo *nuevo = new Nodo;
        nuevo->nivel = i;
        nuevo->punteoG = puntos;
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
        puntos += 20;
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

bool Niveles::Jugar(int nivel)
{
    //texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Iniciando el juego");
    Nodo *aux = inicio;
    while(aux != NULL)
    {
        if(aux->nivel == nivel)
        {
            cout << "Nivel:" << nivel << " Encontrado"<<endl;
            if(aux->Lock)
            {
                //texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Nivel Blocqueado");
                cout << "Nivel bloqueado"<<endl;
                return false;
            }
            else
            {
                Play = aux;
                Play->matriz->limpiar();
                Play->matriz->start();
                return true;
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
    //system("nomacs niveles.png");
}

bool Niveles::atacar(int x, int y)
{
    MatrizOrtogonal *mat = Play->matriz;
    //texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Atacando el nodo");
    return mat->atacarNodo(x,y);
}

void Niveles::graficarpila(int x, int y)
{
    if(Play->matriz->graficarPila(x,y))
    {
        texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Pila graficada Correctamente");
    }
    else
    {
        texto->setText(texto->toPlainText() + "\n201503823@Gianni:~ Nodo Null no se grafica pila");
    }
}

bool Niveles::crearUsuario(string nombre)
{
    this->jugando = new Usuario(nombre);
    pushLisUsuario(jugando);
}

void Niveles::finjuego()
{
    this->punteo = Play->matriz->getPunteo();
    jugando->min = this->min;
    jugando->nivel = Play->nivel;
    jugando->punteo = this->punteo;
    jugando->seg = this->seg;
    Play->matriz->setFinHilo();
    jugando->incertarNodoArbol();
    //pthread_cancel(Play->matriz->thread());
    //sacar gemas de clase matrizOrtogonal
}

void Niveles::setMin(int min)
{
    this->min = min;
}

void Niveles::setSeg(int seg)
{
    this->seg = seg;
}

void Niveles::pushLisUsuario(Usuario *usr)
{
    LisUsuario *nuevo = new LisUsuario;
    nuevo->usr = usr;
    if(inicioLisUsu != NULL)
    {
        nuevo->siguiente = inicioLisUsu;
    }
    else
    {
        nuevo->siguiente = NULL;
    }
    inicioLisUsu = nuevo;
}

void Niveles::graficarLisUsuario()
{
    if(inicioLisUsu != NULL)
    {
        LisUsuario *aux = inicioLisUsu;
        ofstream ficheroSalida;
        ficheroSalida.open ("LisUsr.dot");
        ficheroSalida << "digraph LisUsr{";
        while(aux != NULL)
        {
            Usuario *usr = aux->usr;
            ficheroSalida << usr->nombre<<"Pts"<<usr->punteo;
            if(aux->siguiente != NULL)
            {
                ficheroSalida<<" -> ";
            }
            else
            {
                ficheroSalida<<";\n";
            }
            aux = aux->siguiente;
        }
        ficheroSalida << "}";
        ficheroSalida.close();
        system("dot -Tpng LisUsr.dot -o LisUsr.png");
        system("nomacs LisUsr.png");
    }
}

int Niveles::getPunteo()
{
    return Play->matriz->getPunteo();
}

void Niveles::graficarArbol()
{
    jugando->arbol->recorridoAnchura();
}

void Niveles::pausar()
{
    Play->matriz->setPausa();
}

void Niveles::PopGemaNivel()
{
    while(Play->matriz->getContGema() >= 3)
    {
        cout <<"Extrallendo una gema del nivel: "<<Play->nivel<<endl;
        jugando->incertarGema(Play->matriz->getGema());
    }
}

int Niveles::getCantGemas()
{
    if(Play != NULL)
    {
        PopGemaNivel();
    }
    return jugando->cantGema;
}

bool Niveles::buscarUsuario(string nombre)
{
    if(inicioLisUsu == NULL)
    {
        return false;
    }
    else
    {
        LisUsuario *aux = inicioLisUsu;
        while(aux != NULL)
        {
            Usuario *usr = aux->usr;
            if(usr->nombre == nombre)
            {
                jugando = usr;
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }
}

void Niveles::graficarLisEnemigosElim()
{
    Play->matriz->graficarEnemigosEliminados();
}

bool Niveles::desbloquearNivelGema(int nivel)
{
    Gema *gem = jugando->popGema();
    if(gem != NULL)
    {
        Nodo *Ndes = buscarNivel(nivel);
        if(Ndes != NULL)
        {
            Ndes->Lock = false;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

Nodo *Niveles::buscarNivel(int nivel)
{
    Nodo *aux = Pnivel;
    while(aux != NULL)
    {
        if(aux->nivel == nivel)
        {
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

bool Niveles::ganoNivel()
{
    if(getPunteo() >= Play->punteoG)
    {
        Play->siguiente->Lock = false;
        return true;
    }
    return false;
}
