#include "myscene.h"

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
//    this->item=new myItem;
//    this->item->setPos(0,0);
//    this->addItem(this->item);
    for(int i=0;i<16;i++)
    {
        this->item[i]=new myItem;
        this->item[i]->setPos(i/4*this->item[i]->sceneBoundingRect().width(),i%4*this->item[i]->sceneBoundingRect().height());
        this->addItem(this->item[i]);
    }
    //this->item[4]->setPic(":/bg/pic/bg.png");
    this->ptimer=new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));
    //this->ptimer->start(500);
}

void myScene::showMouse()
{
    //随机数0-15
    int count =QRandomGenerator::global()->bounded(3);
    for(int i=0;i<16;i++)
    {
        this->item[i]->setPic(":/bg/pic/bg1.png");
        this->item[i]->setMouse(false);
    }
    for(int i=0;i<count;i++)
    {
        int index=QRandomGenerator::global()->bounded(16);
        this->item[index]->setPic(":/bg/pic/bg.png");
        this->item[index]->setMouse(true);
    }

}

void myScene::startGame()
{
    for(int i=0;i<16;i++)
    {
        this->item[i]->setStart(true);
    }
    this->ptimer->start(800);
}

void myScene::stopGame()
{
    for(int i=0;i<16;i++)
    {
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();
    for(int i=0;i<16;i++)
    {
        this->item[i]->setPic(":/bg/pic/bg1.png");
        this->item[i]->setMouse(false);
    }
}

void myScene::pauseGame()
{
    for(int i=0;i<16;i++)
    {
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();
}
