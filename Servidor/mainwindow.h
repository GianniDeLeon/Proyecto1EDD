#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "niveles.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void setTextTextEdit(QString texto);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_actionsalir_triggered();

    void on_actionDesarrollador_triggered();

    void on_actionAplicacion_triggered();

    void on_actionManual_Tecnico_triggered();

    void on_actionManual_de_Usuario_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
