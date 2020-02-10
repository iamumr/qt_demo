#include "addstu.h"
#include "ui_addstu.h"
#include <QString>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
#include <QList>
#include <QAbstractButton>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
addStu::addStu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addStu)
{
    ui->setupUi(this);
}

addStu::~addStu()
{
    delete ui;
}


void addStu::on_pb_confirm_clicked()
{
    QString name=ui->le_name->text();
    QString id=ui->le_id->text();
    QString gender=ui->genderGroup->checkedButton()->text();
    QString age=ui->cbb_age->currentText();
    QString dev=ui->cbb_yx->currentText();
    QList<QAbstractButton*> ins_list=ui->insGroup->buttons();
    QString ins;
    for(int i=0;i<ins_list.length();i++)
    {
        QAbstractButton* che=ins_list[i];
        if(che->isChecked())
        {
            ins+=che->text()+" ";
        }
    }
//    QMessageBox msgBox;
//    msgBox.setText("请确认信息");
//    msgBox.setInformativeText(name+'\n'+id);
//    QMessageBox::aboutQt(this,"鸣谢");
    QString content=name+'\n'+id+'\n'+gender+'\n'+age+'\n'+dev+'\n'+ins;
    QString cnt=name+" "+id+" "+gender+" "+age+" "+dev+" "+ins+'\n';
    if(name.length()<1||id.length()<10||ins.length()<1){
        QMessageBox::critical(this,"错误","信息填写不完整，请重新填写","确认");
    }else{
        int ret=QMessageBox::information(this,"请确认信息",content,"确认","取消");
        if(0==ret)
        {
            clearUserInterface();
            writeToFile(cnt);
        }
    }


//    QMessageBox::warning();
//    qDebug()<<ret;
}

void addStu::clearUserInterface()
{
    ui->le_name->clear();
    ui->le_id->clear();
    ui->rdtn_male->setChecked(true);
    ui->cbb_age->setCurrentIndex(0);
    ui->cbb_yx->setCurrentIndex(0);
    QList<QAbstractButton*> ins_list=ui->insGroup->buttons();
    for(int i=0;i<ins_list.length();i++)
    {
        ins_list[i]->setChecked(false);
    }
    ui->le_name->setFocus();
}

void addStu::writeToFile(QString cnt)
{
    QFile file("stu.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败,请检查权限！");
        return;
    }
    QTextStream out(&file);
    out<<cnt;
    file.close();
}

void addStu::on_pb_cancel_clicked()
{
    this->close();
}
