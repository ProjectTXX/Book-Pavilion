#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QString>
#include"window.h"
#include"success.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



private slots:
    void on_Login_clicked();

    void on_Enroll_clicked();

private:
    Ui::Widget *ui;
};
void Sql_init();//初始化数据库
#endif // WIDGET_H
