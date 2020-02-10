#ifndef QUERYSTU_H
#define QUERYSTU_H

#include <QDialog>
#include <QFile>
#include <QList>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class QueryStu;
}

class QueryStu : public QDialog
{
    Q_OBJECT

public:
    explicit QueryStu(QWidget *parent = nullptr);
    ~QueryStu();
    int readFromFile();
    void doQuery(int index,QString cnt);
    void disPlay(int row,QStringList subs);
    void setTableTitle();

private slots:
    void on_btn_search_clicked(bool checked);

private:
    Ui::QueryStu *ui;
    QList<QString> stu_lines;
    QStandardItemModel *model;
};

#endif // QUERYSTU_H
