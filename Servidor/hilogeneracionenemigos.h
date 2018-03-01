#ifndef HILOGENERACIONENEMIGOS_H
#define HILOGENERACIONENEMIGOS_H
#include <QThread>

class HiloGeneracionEnemigos : public QThread
{
    Q_OBJECT
public:
    HiloGeneracionEnemigos();

protected:
    void run();
};

#endif // HILOGENERACIONENEMIGOS_H
