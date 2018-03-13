#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "niveles.h"
#include <QMessageBox>
#include<QGraphicsScene>
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
