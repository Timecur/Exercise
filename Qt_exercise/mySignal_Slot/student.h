#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject* parent = 0);

signals:

public slots:
    // 自定义槽函数
    // 高版本可以写到 public下或全局函数
    // 槽函数返回值void
    // 槽函数需要声明，也需要实现
    // 槽函数也可以有参数， 可以重载
    void treat();
    void treat(QString foodName);
};

#endif // STUDENT_H
