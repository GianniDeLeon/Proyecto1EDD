#ifndef ENEMIGO_H
#define ENEMIGO_H


class Enemigo
{
public:
    Enemigo(int,int);
    int impacto();
    int getVida();
    int getId();
protected:
    int vida;
    int id;
};

#endif // ENEMIGO_H
