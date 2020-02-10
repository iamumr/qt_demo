#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc=new myScene;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this->sc,SLOT(stopGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this,SLOT(tozeroScore()));
    this->score=0;
    handler* hand=handler::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(updateScore()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret=QMessageBox::question(this,"确定","你真的要关闭么？","是","否");
    if(1==ret)
    {
        event->ignore();
    }
}

void MainWindow::updateScore()
{
    score++;
    this->ui->lcdNumber->display(this->score);
}

void MainWindow::tozeroScore()
{
    this->score=0;
}
