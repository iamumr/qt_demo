#ifndef EXPR_H
#define EXPR_H

#include <QDialog>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class expr; }
QT_END_NAMESPACE

class expr : public QDialog
{
    Q_OBJECT

public:
    expr(QWidget *parent = nullptr);
    ~expr();

private slots:
    void getBtn0();
    void getBtn1();
    void getBtn2();
    void getBtn3();
    void getBtn4();
    void getBtn5();
    void getBtn6();
    void getBtn7();
    void getBtn8();
    void getBtn9();

    void on_btn_clear_clicked();

    void on_btn_plus_clicked();

    void on_btn_sub_clicked();

    void on_btn_mul_clicked();

    void on_btn_div_clicked();

    void on_btn_equal_clicked();

private:
    Ui::expr *ui;
    model *mode;
    QString tmp;
};
#endif // EXPR_H
