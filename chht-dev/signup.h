#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include<QTimer>
#include<QLabel>
#include<QWidget>
#include<QLineEdit>

namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = 0);
    ~Signup();

private slots:
    void on_Enroll_clicked();

    void on_return_2_clicked();

    void on_Send_clicked();

    void updateTimer();//倒计时逻辑的成员函数

private:
    Ui::Signup *ui;
    QTimer *timer;
    int countdown;
    bool isCounting;
    int code;//随机验证码
};

#endif // SIGNUP_H
