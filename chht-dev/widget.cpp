#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QString>
#include<QtSql/QSqlQuery>
#include<QMessageBox>
#include<QDialog>

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
        //格式化字符串，将字符串中的占位符替换成指定的参数，用字符串S来检测账号与密码是否正确或对应
         QString S = QString("select * from user_table where name=’%1’ and password=’%2’").arg(user).arg(pwd);
         QSqlQuery query;//执行查询语句
         if(query.exec(S))
         {
             QMessageBox::information(NULL,"登陆成功","登陆成功！",QMessageBox::Yes);

         }
         else
         {
             QMessageBox::warning(this,"error","用户名或者密码错误！！！");
         }
         //清空内容并且定位光标
         ui->Person->clear();
         ui->Password->clear();
         ui->Person->setFocus();//将光标定位到用户名输入框
    }
}

void Widget::on_Enroll_clicked()//注册
{
    QString user,pwd;
    user=ui->Person->text();//获取注册的账户名
    pwd=ui->Password->text();//获取注册的密码
    if(user=="")
        QMessageBox::warning(this,"","用户名不能为空");
    else if(pwd=="")
        QMessageBox::warning(this,"","密码不能为空");
    else
    {
        //插入信息到数据库中
        QString i=QString("insert into user_table values(’%1’,’%2’);").arg(user).arg(pwd);
        //先查询该账户是否已经被注册，若已被注册，更换账户名注册
        QString s=QString("select * from user_table where name = ‘%1’").arg(user);
        QSqlQuery query;
        query.exec(s);
        if(query.first())
            QMessageBox::warning(this,"ERROR","用户名重复！");
        else if(query.exec(i))
        {
            QMessageBox::information(this,"注册成功！","注册成功！！",QMessageBox::Yes);

        }
        else
       {
            QMessageBox::warning(this,"ERROR","注册失败! ");
        }
    }
}
