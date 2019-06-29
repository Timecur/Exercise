#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>
#include <QPushButton>

class MyWidget : public QMainWindow
{
    Q_OBJECT  //Q_OBJECT宏 写了这个宏 就支持Qt中的信号和槽机制

public:
    MyWidget(QWidget *parent = 0);   // 构造函数   默认parent为0
    ~MyWidget();
};

#endif // MYWIDGET_H
