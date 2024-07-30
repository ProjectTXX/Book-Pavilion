#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QString>
#include<QSqlDatabase>//数据驱动
#include<QMessageBox>
#include<QDialog>
#include"signup.h"
#include<QSqlQuery>//数据库执行语句

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->Password->setEchoMode(QLineEdit::Password);//不可视化
    //点击checkbox密码可视化，否则不可视化
    connect(ui->show,&QCheckBox::clicked,[&](bool x){
        ui->Password->setEchoMode(x?QLineEdit::Normal:QLineEdit::Password);
    });
    connect(ui->exit, SIGNAL(clicked(bool)), this, SLOT(close()));//PutButton退出

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Login_clicked()//登录操作
{
    Sql_init();//数据库初始化
    QString user;
    QString pwd;
    user=ui->Person->text();//获取用户名
    pwd=ui->Password->text();//获取密码
    //判断用户名密码是否为空，为空则提示不能为空
    if(user=="")
    {
         QMessageBox::warning(this,"","用户名不能为空");
    }
    else if(pwd=="")
    {
          QMessageBox::warning(this,"","密码不能为空");
    }
    else if(user!=""&&pwd!="")
    {
        QString sql=QString("select * from user where user='%1' and pwd='%2'").arg(user).arg(pwd);
        //创建执行语句
        QSqlQuery query(sql);
        //判断执行结果
        if(!query.next())
        {
            qDebug()<<"Login error";
            QMessageBox::information(this,"登录认证","账户或密码错误！");
        }
        else
        {
            qDebug()<<"Login success";
            QMessageBox::information(this,"登录认证","登录成功！");
            //登录之后跳转页面





            //关闭该界面
            this->close();
        }

    }
}

void Widget::on_Enroll_clicked()//注册
{
    this->close();
    Signup *s=new Signup;
    s->show();
}
void Sql_init()
{

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if(!db.open())
    {
        qDebug()<<"open error";
    }
    //创建数据表
    QString createsql=QString("create table if not exists user(id integer primary key autoincrement,"
                              "username ntext unique not NULL,"
                              "password ntext not NULL)");
    QSqlQuery querry;//执行语句
    if(querry.exec(createsql))
    {
        qDebug()<<"数据表创建成功！";
    }
    else
    {
        qDebug()<<"数据表创建失败！";
    }
}
