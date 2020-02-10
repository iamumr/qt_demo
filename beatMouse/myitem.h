#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QString>
#include "handler.h"
#include <QCursor>
class myItem : public QGraphicsPixmapItem
{
public:
    myItem();
    void setPic(QString path);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setMouse(bool mouse);
    bool isMouse();
    void setStart(bool start);
    bool isStart();
private:
    bool mouse;
    bool start;
};

#endif // MYITEM_H
