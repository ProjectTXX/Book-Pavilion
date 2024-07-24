#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_form.h"
#include<QLabel>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<unistd.h>
#include<QTimer>
void mysqlConnect(QSqlDatabase db)
{
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("hcc");
    db.setPassword("2028915986hcc");
    db.setDatabaseName("login");

    if(!db.open())
    {
        qDebug()<<"数据库打开失败！！！";
    }
    else qDebug()<<"成功！！！";
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    form=new Form;
    QSqlDatabase db;
    mysqlConnect(db);
//登录界面注册按钮
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        this->hide();
        form->show();
    });

//注册界面取消按钮
    connect(form->getui()->pushButton_2,&QPushButton::clicked,form,[=](){
        form->hide();
        this->show();
    });
//注册界面确定按钮
        connect(form->getui()->pushButton,&QPushButton::clicked,form,[&](){
        if(form->getPassword()!=form->getPassword_())
        {
            form->getui()->label_4->setText("请重新输入密码！！！");

            return;

        }
        QSqlQuery que;
        QString s1=form->getAccount(),s2=form->getPassword();
        if(s1==""||s2=="")
        {
            qDebug()<<"空";
            form->getui()->label_4->setText("账号或者密码不能为空");
            return;
        }
        QString sql = "INSERT INTO user (account, password) VALUES ('" + s1 + "', '" + s2 + "')";
        bool ret=que.exec(sql);
        if(!ret)
        {
            qDebug()<<"插入出错！！！！！";
            exit(1);
        }
        form->getui()->label_4->setText("注册成功!!!");
        QTimer::singleShot(2000, form, [=]() {
                form->hide();
                this->show();
            });


    });
//登陆界面登录按钮
        connect(ui->pushButton,&QPushButton::clicked,this,[=](){
           QString a=ui->textEdit->toPlainText();
           QString sql="select password from user where account='"+a+"'";
           QSqlQuery que;
           if(!que.exec(sql))
           {
               qDebug()<<"查询失败";
               exit(1);
           }else qDebug()<<"查询成功！！！";
           QString p=ui->textEdit_2->toPlainText();
           if(!que.next())
           {
               ui->label_3->setText("请输入正确的账户或密码");
               return;
           }
           if(que.value(0).toString()==p)
           {
               this->hide();
           }
        });

    db.close();
}

MainWindow::~MainWindow()
{
    delete form;
    delete ui;
}
