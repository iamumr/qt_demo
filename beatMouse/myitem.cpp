#include "myitem.h"

myItem::myItem()
{
    this->setPixmap(QPixmap(":/bg/pic/bg1.png"));
    this->start=false;
    this->mouse=false;
    this->setCursor(QCursor(QPixmap(":/mouse/pic/pictureUp.png")));
}

void myItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/pic/picturedown.png")));
    if(this->isStart()){
        handler* hand=handler::getInstance();
        if(this->isMouse())
        {
            hand->addScore();
            this->setPixmap(QPixmap(":/mouse/pic/beatmouse.png"));
            this->mouse=false;//否则多次极大同一只老鼠
        }
    }
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/pic/pictureUp.png")));
}

void myItem::setMouse(bool mouse)
{
    this->mouse=mouse;
}

bool myItem::isMouse()
{
    return this->mouse;
}

void myItem::setStart(bool start)
{
    this->start=start;
}

bool myItem::isStart()
{
    return this->start;
}
