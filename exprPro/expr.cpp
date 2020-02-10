#include "expr.h"
#include "ui_expr.h"

expr::expr(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::expr)
{
    ui->setupUi(this);
    this->mode=new model;
    connect(ui->btn_0,SIGNAL(clicked(bool)),this,SLOT(getBtn0()));
    connect(ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(getBtn1()));
    connect(ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(getBtn2()));
    connect(ui->btn_3,SIGNAL(clicked(bool)),this,SLOT(getBtn3()));
    connect(ui->btn_4,SIGNAL(clicked(bool)),this,SLOT(getBtn4()));
    connect(ui->btn_5,SIGNAL(clicked(bool)),this,SLOT(getBtn5()));
    connect(ui->btn_6,SIGNAL(clicked(bool)),this,SLOT(getBtn6()));
    connect(ui->btn_7,SIGNAL(clicked(bool)),this,SLOT(getBtn7()));
    connect(ui->btn_8,SIGNAL(clicked(bool)),this,SLOT(getBtn8()));
    connect(ui->btn_9,SIGNAL(clicked(bool)),this,SLOT(getBtn9()));
}

expr::~expr()
{
    delete ui;
}

void expr::getBtn0()
{
    if(ui->label->text()!="0"){
        QString tmp=ui->label->text()+'0';
        ui->label->setText(tmp);
    }
}

void expr::getBtn1()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'1';
    ui->label->setText(tmp);
}

void expr::getBtn2()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'2';
    ui->label->setText(tmp);
}

void expr::getBtn3()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'3';
    ui->label->setText(tmp);
}

void expr::getBtn4()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'4';
    ui->label->setText(tmp);
}

void expr::getBtn5()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'5';
    ui->label->setText(tmp);
}

void expr::getBtn6()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'6';
    ui->label->setText(tmp);
}

void expr::getBtn7()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'7';
    ui->label->setText(tmp);
}

void expr::getBtn8()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'8';
    ui->label->setText(tmp);
}

void expr::getBtn9()
{
    if(ui->label->text()=='0') ui->label->setText("");
    QString tmp=ui->label->text()+'9';
    ui->label->setText(tmp);
}

void expr::on_btn_clear_clicked()
{
    ui->label->setText("0");
}

void expr::on_btn_plus_clicked()
{
    mode->setNum1(ui->label->text().toInt());
    mode->setFlag(1);
    ui->label->setText("0");
}



void expr::on_btn_sub_clicked()
{
    mode->setNum1(ui->label->text().toInt());
    mode->setFlag(2);
    ui->label->setText("0");
}

void expr::on_btn_mul_clicked()
{
    mode->setNum1(ui->label->text().toInt());
    mode->setFlag(3);
    ui->label->setText("0");
}

void expr::on_btn_div_clicked()
{
    mode->setNum1(ui->label->text().toInt());
    mode->setFlag(4);
    ui->label->setText("0");
}

void expr::on_btn_equal_clicked()
{
    mode->setNum2(ui->label->text().toInt());
    ui->label->setText(mode->doExpr());
}
