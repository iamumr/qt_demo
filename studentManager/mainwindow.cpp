#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstu.h"
#include "querystu.h"
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

void MainWindow::on_actionaddstu_triggered()
{
//    addStu a;
    a.show();
//    a.exec();

}

void MainWindow::on_actionqueryStu_triggered()
{
    QueryStu q;
    q.exec();
}
