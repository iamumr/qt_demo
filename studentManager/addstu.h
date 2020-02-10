#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class addStu; }
QT_END_NAMESPACE

class addStu : public QDialog
{
    Q_OBJECT

public:
    addStu(QWidget *parent = nullptr);
    ~addStu();
    void clearUserInterface();
    void writeToFile(QString);

private slots:
    void on_pb_confirm_clicked();

    void on_pb_cancel_clicked();

private:
    Ui::addStu *ui;
};
#endif // ADDSTU_H
