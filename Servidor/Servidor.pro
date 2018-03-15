#-------------------------------------------------
#
# Project created by QtCreator 2018-02-28T17:59:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Servidor
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -Wall
INCLUDEPATH += -I/usr/local/include/thrift
LIBS+= -L/usr/local/lib -lthrift
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    pila.cpp \
    enemigo.cpp \
    hilogeneracionenemigos.cpp \
    matrizortogonal.cpp \
    gema.cpp \
    niveles.cpp \
    Juego.cpp \
    Servidor_constants.cpp \
    Servidor_types.cpp \
    hiloapache.cpp \
    arbolpunteo.cpp \
    usuario.cpp

HEADERS += \
        mainwindow.h \
    enemigo.h \
    pila.h \
    hilogeneracionenemigos.h \
    matrizortogonal.h \
    gema.h \
    niveles.h \
    Juego.h \
    Servidor_constants.h \
    Servidor_types.h \
    hiloapache.h \
    arbolpunteo.h \
    usuario.h

FORMS += \
        mainwindow.ui
