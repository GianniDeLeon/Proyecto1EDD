/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionsalir;
    QAction *actionDesarrollador;
    QAction *actionAplicacion;
    QAction *actionManual_Tecnico;
    QAction *actionManual_de_Usuario;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *InicioServidor;
    QPushButton *pushButton;
    QLineEdit *TamNiveles;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QTextEdit *textEdit;
    QWidget *tab;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menua;
    QMenu *menuAcerca_de;
    QMenu *menuManuales;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(641, 464);
        actionsalir = new QAction(MainWindow);
        actionsalir->setObjectName(QStringLiteral("actionsalir"));
        actionDesarrollador = new QAction(MainWindow);
        actionDesarrollador->setObjectName(QStringLiteral("actionDesarrollador"));
        actionAplicacion = new QAction(MainWindow);
        actionAplicacion->setObjectName(QStringLiteral("actionAplicacion"));
        actionManual_Tecnico = new QAction(MainWindow);
        actionManual_Tecnico->setObjectName(QStringLiteral("actionManual_Tecnico"));
        actionManual_de_Usuario = new QAction(MainWindow);
        actionManual_de_Usuario->setObjectName(QStringLiteral("actionManual_de_Usuario"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 651, 421));
        InicioServidor = new QWidget();
        InicioServidor->setObjectName(QStringLiteral("InicioServidor"));
        pushButton = new QPushButton(InicioServidor);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 100, 121, 26));
        TamNiveles = new QLineEdit(InicioServidor);
        TamNiveles->setObjectName(QStringLiteral("TamNiveles"));
        TamNiveles->setGeometry(QRect(160, 30, 113, 26));
        label = new QLabel(InicioServidor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 131, 18));
        label_2 = new QLabel(InicioServidor);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 30, 141, 18));
        lineEdit = new QLineEdit(InicioServidor);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(440, 30, 113, 26));
        pushButton_2 = new QPushButton(InicioServidor);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 100, 141, 26));
        tabWidget->addTab(InicioServidor, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        textEdit = new QTextEdit(tab_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(10, 10, 611, 281));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(12);
        textEdit->setFont(font);
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 631, 301));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 320, 111, 26));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 320, 21, 21));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 320, 16, 21));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 320, 91, 26));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(260, 320, 41, 26));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(340, 320, 41, 26));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(410, 320, 121, 26));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(550, 320, 80, 26));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 641, 23));
        menua = new QMenu(menuBar);
        menua->setObjectName(QStringLiteral("menua"));
        menuAcerca_de = new QMenu(menuBar);
        menuAcerca_de->setObjectName(QStringLiteral("menuAcerca_de"));
        menuManuales = new QMenu(menuBar);
        menuManuales->setObjectName(QStringLiteral("menuManuales"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menua->menuAction());
        menuBar->addAction(menuAcerca_de->menuAction());
        menuBar->addAction(menuManuales->menuAction());
        menua->addAction(actionsalir);
        menuAcerca_de->addAction(actionDesarrollador);
        menuAcerca_de->addAction(actionAplicacion);
        menuManuales->addAction(actionManual_Tecnico);
        menuManuales->addAction(actionManual_de_Usuario);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Servidor Gianni", nullptr));
        actionsalir->setText(QApplication::translate("MainWindow", "&salir", nullptr));
        actionDesarrollador->setText(QApplication::translate("MainWindow", "&Desarrollador", nullptr));
        actionAplicacion->setText(QApplication::translate("MainWindow", "&Aplicacion", nullptr));
        actionManual_Tecnico->setText(QApplication::translate("MainWindow", "Manual Tecnico", nullptr));
        actionManual_de_Usuario->setText(QApplication::translate("MainWindow", "Manual de Usuario", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Iniciar Servidor", nullptr));
        label->setText(QApplication::translate("MainWindow", "Cantidad de niveles:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Cantidad De niveles:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Cambio de Tama\303\261o", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(InicioServidor), QApplication::translate("MainWindow", "Inicio Servidor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Consola", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Graficar Matriz", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Y", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Graficar Pila", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Arbol de Punteos", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Niveles", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Graficas", nullptr));
        menua->setTitle(QApplication::translate("MainWindow", "&Juego", nullptr));
        menuAcerca_de->setTitle(QApplication::translate("MainWindow", "Acerca &de", nullptr));
        menuManuales->setTitle(QApplication::translate("MainWindow", "&Manuales", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
