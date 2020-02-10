#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(ui->PushButtom_Quit, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btn_login,SIGNAL(clicked(bool)),this,SLOT(login()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login()
{
    static int count=0;
    //qDebug()<<"login";
    QString name=this->ui->le_account->text();
    QString passwd=this->ui->le_password->text();
    if(name=="jack"&&passwd=="1234")
    {
        qDebug()<<"success";
    }else{
        count++;
        qDebug()<<"failed";
        if(count>3){
            disconnect(ui->btn_login,SIGNAL(clicked(bool)),this,SLOT(login()));
        }
    }
}

void MainWindow::on_PushButtom_Quit_clicked()
{
    this->close();
}

void MainWindow::on_le_account_textChanged(const QString &arg1)
{
    qDebug()<<arg1;
}
