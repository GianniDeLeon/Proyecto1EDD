#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "niveles.h"
#include <QMessageBox>
#include<QGraphicsScene>
#include "hiloapache.h"
/////
#include "Juego.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace  ::Servidor;
Niveles *niveles;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString tam = ui->TamNiveles->text();
    if(tam == "" || tam == NULL)
    {
        QMessageBox msgBox;
        msgBox.setText("No se ingreso el tamaño");
        msgBox.exec();
    }
    else
    {
        ui->pushButton->setEnabled(false);
        ui->TamNiveles->setText("");
        int tam2 = tam.toInt();
        ui->textEdit->setText("201503823@Gianni:~ Iniciando los niveles");
        niveles = new Niveles(tam2,ui->textEdit);
        ui->textEdit->setText("201503823@Gianni:~ Iniciando Servicios de apache");
        HiloApache *apach = new HiloApache(niveles,ui->textEdit);
        apach->start();
        ui->textEdit->setText("201503823@Gianni:~ Apache iniciado exitosamente");
        niveles->Jugar(1);
    }
}

void MainWindow::setTextTextEdit(QString texto)
{
    ui->textEdit->setText(texto);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString tam = ui->lineEdit->text();
    if(tam == "" || tam == NULL)
    {
        QMessageBox msgBox;
        msgBox.setText("No se ingreso el nuevo tamaño");
        msgBox.exec();
    }
    else
    {
        ui->lineEdit->setText("");
        int tam2 = tam.toInt();
        niveles->setTam(tam2);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    niveles->graficarNiveles();
    QGraphicsScene *scene = new QGraphicsScene();
    QPixmap m("niveles.png");
    scene->setBackgroundBrush(m);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString x = ui->lineEdit_2->text();
    QString y = ui->lineEdit_3->text();
    if(x == "" || x == NULL || y == "" || y == NULL)
    {
        QMessageBox msgBox;
        msgBox.setText("No se ingreso la coordenada completa");
        msgBox.exec();
    }
    else
    {
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        int xi = x.toInt();
        int yi = y.toInt();
        niveles->graficarpila(xi,yi);
        QGraphicsScene *scene = new QGraphicsScene();
        QPixmap m("Pila.png");
        scene->setBackgroundBrush(m);
        ui->graphicsView->setScene(scene);
    }
}
