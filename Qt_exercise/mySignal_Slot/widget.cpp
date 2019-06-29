#include "widget.h"
#include <QPushButton>

// 需求：创建两个类  Teacher类  Student类
// 下课后，Teacher zt 发出信号 饿了
// 学生响应信号 Student st 处理信号的槽函数 请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    zt = new Teacher(this); // this用途
    st = new Student(this);

    // 连接老师学生
    // connect(zt, &Teacher::hungry, st, &Student::treat);

    // 函数指针，指向函数地址
    // void(Teacher:: *teacherSignal) (QString) = &Teacher::hungry;
    // void(Student:: *stSlot)(QString) = &Student::treat;
    // 有参的 信号和槽连接
    // connect(zt, teacherSignal, st, stSlot);

    //ClassOver();

    //点击按钮，触发ClassOver
     QPushButton* btn = new QPushButton("下课", this);
    // 触发无参 信号和槽
    // 信号连接 信号
     void (Teacher:: *noTeacherSignal)(void) = &Teacher::hungry;
     void (Student:: *noStSlot)(void) = &Student::treat;
     connect(btn, &QPushButton::clicked, zt, noTeacherSignal);
     connect(zt, noTeacherSignal, st, noStSlot);

    // 断开信号和槽
    // disconnect(zt, noTeacherSignal, st, noStSlot);

    //QPushButton* btn2 = new QPushButton("下课，吃饭", this);
    //btn2->move(50, 50);
    // 信号和槽的拓展
    //connect(btn2, SIGNAL(clicked()), zt, SIGNAL(hungry(QString)));
    connect(zt, SIGNAL(hungry(QString)), st, SLOT(treat(void)));


    ClassOver();
}

void Widget::ClassOver()
{
    // 触发老师饿了的信号
    // 老师饿了的信号属于自定义信号，触发自定义信号关键字 emit
    emit zt->hungry(); // 触发无参的信号
    emit zt->hungry("拉面");
}

Widget::~Widget()
{

}
