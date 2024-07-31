#include "signup.h"
#include "ui_signup.h"
#include"widget.h"
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);//不可视化
    connect(ui->checkBox,&QCheckBox::clicked,[&](bool x){
        ui->Password->setEchoMode(x?QLineEdit::Normal:QLineEdit::Password);
    });

}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_Enroll_clicked()
{
    Sql_init();//初始化数据表
    QString username=ui->Person->text();//得到文本里的账户与密码
    QString password=ui->Password->text();


    //验证码与邮箱待定




    QString sql=QString("insert into user(username,password) values('%1','%2');")
            .arg(username).arg(password);
    //创建执行语句
    QSqlQuery query;
    //判断执行结果
    if(!query.exec(sql))
    {
        qDebug()<<"insert into error";
        QMessageBox::information(this,"注册认证","插入失败!");
    }
    else if(username!=""&&password!="")
    {
        qDebug()<<"insert into success";
        QMessageBox::information(this,"注册认证","注册成功！");
        Widget *w=new Widget;
        this->close();
        w->show();
    }




}

void Signup::on_return_2_clicked()
{
    Widget *w=new Widget;
    w->show();
    this->close();
}


