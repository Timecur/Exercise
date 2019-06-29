#include "mywidget.h"
#include "mybutton.h"
#include <QDebug>

// 命名规范 以及 快捷键
// 类名 首字母大写 单词与单词之间 首字母大写
// 函数、变量 首字母小写 单词与单词间 首字母大写
/*
 *  快捷键： 运行 - ctrl + R
 *          编译 - ctrl + B
 *          查找 - ctrl + F
 *  帮助文档 1.F1 2.左侧按钮 3.assistant.exe
 *  字体缩放 ctrl + 鼠标滑轮
 *  自动对齐 ctrl + i
 *  整行上下移动 ctrl + shift 上下箭头
 *  同名之间的.h .cpp文件切换 F4
 */


MyWidget::MyWidget(QWidget *parent) // 在创建对象之初先提供一个parent对象指针，作用：？
    : QMainWindow(parent)
{
    // 按钮
    QPushButton* btn = new QPushButton;
    // btn->show(); // 用顶层方式弹出。若想在MyWiget窗口中显示，就需要依赖MyWidget窗口

    // 设置父亲
    btn->setParent(this);

    // 设置文字
    btn->setText("Nemo");// 将char*隐式类型转化为QString

    // 重置按钮大小
    btn->resize(150 ,100);

    // 创建按钮第二种方式
    QPushButton* btn2 = new QPushButton("第二按钮", this); //此方式可以安装btn2大小进行显示
    // 重置窗口大小
    this->resize(200, 100);// 宽  高
    // 后创建，显示靠前
    // 移动第二个按钮
    btn2->move(100, 100);

    // 重置窗口标题
    setWindowTitle("xxx---xxx");

    // 设置窗口大小
    setFixedSize(600, 400);

    MyButton* myBtn = new MyButton;
    myBtn->setText("my button");
    myBtn->resize(100, 50);
    myBtn->move(200, 100);
    myBtn->setParent(this);

    // 点击myBtn 关闭窗口
    connect(myBtn, &MyButton::clicked, this, &MyWidget::close);
    // connect(myBtn, &QPushButton::clicked, this, &MyWidget::close);

}

MyWidget::~MyWidget()
{
    qDebug() << "MyWidget is deconstruct~";
}
