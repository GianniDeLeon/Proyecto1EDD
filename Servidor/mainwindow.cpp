#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "niveles.h"

Niveles *niveles;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->setReadOnly(true);
    QString tam = ui->TamNiveles->text();
    ui->TamNiveles->setText("");
    int tam2 = tam.toInt();
    ui->textEdit->setText("201503823@Gianni:~ Iniciando los niveles");
    niveles = new Niveles(tam2,ui->textEdit);
    niveles->Jugar(1);
}

void MainWindow::setTextTextEdit(QString texto)
{
    ui->textEdit->setText(texto);
}
