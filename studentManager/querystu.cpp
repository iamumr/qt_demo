#include "querystu.h"
#include "ui_querystu.h"


QueryStu::QueryStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryStu)
{
    ui->setupUi(this);
    if(readFromFile()==-1)
    {
        QMessageBox::critical(this,"警告","数据库不存在");
        this->close();
    }
    this->model=new QStandardItemModel;
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("兴趣"));
    this->ui->tableView->setModel(model);

    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,100);
    this->ui->tableView->setColumnWidth(3,100);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,150);
}

QueryStu::~QueryStu()
{
    delete ui;
    delete this->model;
}

int QueryStu::readFromFile()
{
    QFile file("stu.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line=in.readLine();
        stu_lines.append(line);
    }
    file.close();
    return 1;
}
void QueryStu::on_btn_search_clicked(bool checked)
{
    this->model->clear();
    setTableTitle();
    int index=this->ui->cbb_method->currentIndex();
    QString cnt=ui->le_cnt->text();
    doQuery(index,cnt);
}

void QueryStu::doQuery(int index, QString cnt)
{
    int row=0;
    for(int i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines[i];
        line=line.trimmed();//去除字符串开始和末尾的空白
        QStringList subs=line.split(" ");
        switch(index){
        case 1:
            if(cnt==subs[0])
            {
                disPlay(row++,subs);
            }
            break;
        case 2:
            if(cnt==subs[1])
            {
                disPlay(row++,subs);
            }
            break;
        case 3:
            if(cnt==subs[2])
            {
                disPlay(row++,subs);
            }
            break;
        default:
            break;
        }
    }
}

void QueryStu::disPlay(int row, QStringList subs)
{
    int i=0;
    for(i=0;i<5;i++)
    {
        this->model->setItem(row,i,new QStandardItem(subs[i]));
    }
    QString ins;
    for(i=5;i<subs.length();i++)
    {
        ins+=subs[i]+" ";
    }
    this->model->setItem(row,5,new QStandardItem(ins));
}

void QueryStu::setTableTitle()
{
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("兴趣"));
    this->ui->tableView->setModel(model);

    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,100);
    this->ui->tableView->setColumnWidth(3,100);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,150);
}
