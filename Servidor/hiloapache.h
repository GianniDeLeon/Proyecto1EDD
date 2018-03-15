#ifndef HILOAPACHE_H
#define HILOAPACHE_H
#include "niveles.h"
#include <QThread>

class HiloApache : public QThread
{
public:
    HiloApache(Niveles *nivel);
    Niveles *nivel;

protected:
    void run();
};

#endif // HILOAPACHE_H
