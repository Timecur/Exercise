#ifndef TEACHER_H
#define TEACHER_H
#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject* parent = 0);

signals:
    // 自定义信号， 要写到signals下
    // 返回类型 必须void
    // 信号只需要有声明 不需要实现 --- 在.c文件中可以不写
    // 信号可以有参数，可以重载
    void hungry();
    void hungry(QString foodName);

public slots:

};

#endif // TEACHER_H
