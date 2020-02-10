#ifndef MODEL_H
#define MODEL_H
#include <QString>

class model
{
public:
    model();
    void setNum1(int num);
    void setNum2(int num);
    void setFlag(int flag);
    QString doExpr();

private:
    int num1;
    int num2;
    int flag;//+-*/对应1 2 3 4

};

#endif // MODEL_H
