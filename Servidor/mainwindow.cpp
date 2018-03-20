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
        ui->textEdit->append("201503823@Gianni:~ Iniciando los niveles");
        //niveles = new Niveles(tam2,ui->textEdit);
        niveles = new Niveles(tam2,ui->textEdit);
//        connect(niveles,&Niveles::escritura,[&](QString n){
//            //return connect(sender, signal, sender, std::move(slot), Qt::DirectConnection);
//            ui->textEdit->setPlainText(n);
//        });
        ui->textEdit->append("201503823@Gianni:~ Graficando los niveles");
        niveles->graficarNiveles();
        ui->textEdit->append("201503823@Gianni:~ Iniciando Servicios de apache");
        HiloApache *apach = new HiloApache(niveles,ui->textEdit);
        apach->start();
        ui->textEdit->append("201503823@Gianni:~ Apache iniciado exitosamente");
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
        ui->textEdit->append("201503823@Gianni:~ Cambio de tamaño de niveles y tamaño maximo de matriz");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    niveles->graficarNiveles();
    QGraphicsScene *scene = new QGraphicsScene();
    QPixmap m("niveles.png");
    scene->setBackgroundBrush(m);
    ui->graphicsView->setScene(scene);
    ui->textEdit->append("201503823@Gianni:~ Graficando Niveles");
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
        ui->textEdit->append("201503823@Gianni:~ Graficando pila");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    niveles->graficarMatriz();
    QGraphicsScene *scene = new QGraphicsScene();
    QPixmap m("matriz.png");
    scene->setBackgroundBrush(m);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QRect rcontent = ui->graphicsView->contentsRect();
    ui->graphicsView->setSceneRect(0, 0, rcontent.width(), rcontent.height());
    ui->textEdit->append("201503823@Gianni:~ Graficando matriz");
    //raphicsView.setSceneRect(0, 0, rcontent.width(), rcontent.height());
    //ui->graphicsView->ensureVisible();
    //v.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindow::on_actionsalir_triggered()
{
    exit(0);
}

void MainWindow::on_actionDesarrollador_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Gianni De Leon\n201503823\nEDD seccion B\n1er Semestre 2018");
    msgBox.exec();
}

void MainWindow::on_actionAplicacion_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Servidor desarrollado en C++ y QT con el IDE QTCreator\nPara conexiones se uso ApacheThrift\nCliente desarrollado en java");
    msgBox.exec();
}

void MainWindow::on_actionManual_Tecnico_triggered()
{
    system("okular /home/mrrobot/Público/MultimediaEDDP1/ManualTecnico.pdf");
}

void MainWindow::on_actionManual_de_Usuario_triggered()
{
    system("okular /home/mrrobot/Público/MultimediaEDDP1/ManualdeUsuario.pdf");
}
