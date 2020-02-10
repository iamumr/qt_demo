#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myscene.h>
#include <QCloseEvent>
#include "handler.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent* event);

private slots:
    void updateScore();
    void tozeroScore();

private:
    Ui::MainWindow *ui;
    myScene * sc;
    int score;
};
#endif // MAINWINDOW_H
