#ifndef NIVELES_H
#define NIVELES_H
#include "matrizortogonal.h"
#include <QTextEdit>
#include "arbolpunteo.h"
#include <string>
#include "usuario.h"
using namespace std;
class Niveles : public QObject
{
public:
    int tam,min,seg,punteo;
    QTextEdit *texto;
    Niveles(int tam,QTextEdit *texto);
    struct LisUsuario;
    struct Nodo;
    void crearNiveles();
    Nodo *inicio;
    Usuario *jugando;
    LisUsuario *inicioLisUsu;
    void setTam(int tam);
    void aumentarTam();
    bool Jugar(int nivel);
    MatrizOrtogonal::ListaGemas *ini;
    void stop();
    void graficarNiveles();
    bool atacar(int x, int y);
    void graficarpila(int x, int y);
    bool crearUsuario(string nombre);
    void finjuego();
    void setMin(int min);
    void setSeg(int seg);
    void pushLisUsuario(Usuario *usr);
    void graficarLisUsuario();
    void graficarArbol();
    void pausar();
    int getPunteo();
    void PopGemaNivel();
    int getCantGemas();
    bool buscarUsuario(string nombre);
    void graficarLisEnemigosElim();
    bool desbloquearNivelGema(int nivel);
    Nodo *buscarNivel(int nivel);
    bool ganoNivel();
    bool onOffCheat();
    void graficarMatriz();
signals:
    void escritura(QString);
};

#endif // NIVELES_H
