#ifndef HILOGENERACIONENEMIGOS_H
#define HILOGENERACIONENEMIGOS_H

#include <QThread>

class HiloGeneracionEnemigos : public QThread
{
    Q_OBJECT
public:
    explicit HiloGeneracionEnemigos(QObject *parent = nullptr);

protected:
    void run();
};

#endif // HILOGENERACIONENEMIGOS_H
