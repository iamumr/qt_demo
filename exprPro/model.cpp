#include "model.h"

model::model()
{
    this->num1=0;
    this->num2=0;
}

void model::setFlag(int flag)
{
    this->flag=flag;
}

void model::setNum1(int num)
{
    this->num1=num;

}

void model::setNum2(int num)
{
    this->num2=num;
}

QString model::doExpr()
{
    int result=0;
    switch (this->flag) {
    case 1:
        result=num1+num2;
        break;
    case 2:
        result=num1-num2;
        break;
    case 3:
        result=num1*num2;
        break;
    case 4:
        if(num2==0){
            return "Error";
        }
        result=num1/num2;
        break;
    default:
        return QString::number(this->num1);

    }
    return QString::number(result);
}
