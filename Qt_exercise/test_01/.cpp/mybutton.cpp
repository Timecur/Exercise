#include "mybutton.h"
#include <QDebug> //Qt中打印信息使用的头文件，自动加换行

MyButton::MyButton(QWidget* parent):QPushButton (parent)
{

}

MyButton::~MyButton()
{
    qDebug() << "MyButton is deconstruct";
}
