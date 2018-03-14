#ifndef HILOAPACHE_H
#define HILOAPACHE_H
#include "niveles.h"
#include <QThread>

class HiloApache : public QThread
{
public:
    HiloApache(Niveles *nivel,QTextEdit *textEdit);
    Niveles *nivel;
    QTextEdit *textEdit;

protected:
    void run();
};

#endif // HILOAPACHE_H
