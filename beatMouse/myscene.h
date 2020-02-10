#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <myitem.h>
#include <QTimer>
#include <QRandomGenerator>

class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);

signals:

public slots:
    void startGame();
    void stopGame();
    void pauseGame();

private slots:
    void showMouse();

private:
    myItem * item[16];
    QTimer * ptimer;
};

#endif // MYSCENE_H
