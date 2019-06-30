#include "mywidget.h"
#include <QApplication> // 包含头文件 应用程序

// 程序入口
int main(int argc, char *argv[])
{
    // 应用程序对象a； Qt中有且只有一个
    QApplication a(argc, argv);
    // 创建 MyWidget对象 w  MyWidget 基类：QWidget
    MyWidget w;
    // 窗口默认不会弹出，若想弹出 调用show方法
    w.show();

    // a.exec() 进入消息循环机制 pause
    return a.exec();
}
