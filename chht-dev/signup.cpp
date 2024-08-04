#include "signup.h"
#include "ui_signup.h"
#include"widget.h"
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include"smtp.h"
#include<QTime>


Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup),
    timer(new QTimer(this)),
    countdown(30),
    isCounting(false)

{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);//不可视化
    connect(ui->checkBox,&QCheckBox::clicked,[&](bool x){
        ui->Password->setEchoMode(x?QLineEdit::Normal:QLineEdit::Password);
    });
    connect(timer,&QTimer::timeout,this,&Signup::updateTimer);
    connect(ui->Send,&QPushButton::clicked,this,&Signup::on_Send_clicked);
    //发送验证码，邮箱验证码
    QString qq=ui->Mail->text();
    QByteArray m_qq=qq.toUtf8();
    smtp s("2760622686@qq.com","esbvhabibepudehc");
       s.send(m_qq,"Book-Pavilion注册验证码","");

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



    int code_1=ui->Mailverify->text().toInt();
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
    else if(username!=""&&password!=""&&code_1==code)
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



void Signup::on_Send_clicked()//发送验证码的按钮
{
    //添加一个发送验证码的逻辑
    //调用一个函数来发送邮件
    QString recvaddr0=ui->Mail->text();
       QRegExp re("^[A-Za-z0-9]+([_\\.][A-Za-z0-9]+)*@([A-Za-z0-9\\-]+\\.)+[A-Za-z]{2,6}$");
       if(re.exactMatch(recvaddr0)){

       //验证邮箱格式
           QMessageBox::information(NULL,"提示","验证码将在30s内发送至您的邮箱，请耐心等待。");
           QTime time= QTime::currentTime();
           qsrand(time.msec()+time.second()*1000);
           code = 1000+qrand() % (9999-1000);    //产生1000~9999以内的随机数
           smtp smtp("2760622686@qq.com","esbvhabibepudehc");//实例化对象
           QByteArray recvaddr=recvaddr0.toUtf8();//QString转QByteArray
           QString subject="xx系统登录/注册验证码";
           QString content="欢迎登录/注册Book-Pavilion电子阅读器，本次操作的验证码为："+QString::number(code);
           content+="请勿泄露或转发，如非本人操作，请忽略此短信";
           smtp.send(recvaddr,subject,content);
       }
       else{


           QMessageBox::warning(NULL,"提示","邮箱格式不正确,请重新输入。");
       }




    //禁用发送按钮并启动倒计时
    ui->Send->setEnabled(false);
    ui->Send->setText("倒计时：");
    this->isCounting=true;
    timer->start(1000);//每秒更新一次
}
 void Signup::updateTimer()
 {
     if(countdown>0)
     {
         ui->Send->setText(QString("倒计时：%1s").arg(countdown));
         countdown--;
     }
     else
     {
         timer->stop();
         ui->Send->setEnabled(true);
         ui->Send->setText("发送验证码");
         isCounting=false;
     }
 }
