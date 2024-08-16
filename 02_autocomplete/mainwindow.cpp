#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ui_view.h"
#include"ui_preview.h"
#include"ui_preview2.h"
#include<QCompleter>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QScrollArea>
#include<QPushButton>
#include<QToolButton>
#include<QIcon>
#include<QVBoxLayout>
#include<QLabel>
#include<QPixmap>
//用字符匹配方法实现关键字搜索
QStringList key_search(QString text)
{
    QSqlQuery qu;
    QString s="select bname from bknm";
    if(!qu.exec(s))qDebug("查询出错");
    QStringList list;
    while(qu.next())
    {
        QString name=qu.value(0).toString();
        if(text.size()>name.size())continue;
        for(int i=0;i<name.size();i++)
        {
            QString sub=name.mid(i,text.size());
            if(sub==text)
            {
                list<<name;
                break;
            }
        }

    }
    return list;
}
//连接数据库
void mysqlConnect(QSqlDatabase& db)
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
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建一个preview实例
    preview=new Preview;
    //创建一个preview2类型，将preview2放在preview里面的psa里，再在preview2里面放别的控件实现滚动效果
    preview2=new Preview2;
    //创建一个view实例
    view=new View;


    //创建一个滑动窗口psa并将它放入preview布局中
    QScrollArea* psa=new QScrollArea(preview);
    preview->getui()->layout->addWidget(psa);
    psa->setWidgetResizable(true);
    //设置psa的中心控件为preview2
    psa->setWidget(preview2);

    //设置一个布局vlayout并且把布局放入preview2中
    //QVBoxLayout* vlayout=new QVBoxLayout(preview2);
    //preview2->setLayout(vlayout);
    /*vlayout->addWidget(preview2);

    */



    //创建一个滑动窗口sa并将它放入view布局中
    view->setLayout(view->getui()->layout);
    QScrollArea* sa=new QScrollArea(view);
    view->getui()->layout->addWidget(sa);
    sa->setWidgetResizable(true);
    sa->setWidget(view->getui()->textEdit);


    //view->getui()->layout->addWidget(sa);
    //view->getui()->layout->setStretch(0,1);



    QSqlDatabase db;
    mysqlConnect(db);
    //将查询到的内容放入list，然后通过list来提供自动补全功能
    QStringList list;
    QSqlQuery que;
    QString sql="select bname from bknm";
    que.exec(sql);
    if(!que.next())
    {

        return;
    }
    do
    {
        list<<que.value(0).toString();
    }while(que.next());
    QCompleter* comp=new QCompleter(list,this);
    comp->setMaxVisibleItems(2);
    comp->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(comp);
    //等待用户输入完，点击确定
    connect(ui->lineEdit,&QLineEdit::returnPressed,this,[&](){
        QString text=ui->lineEdit->text();
        if(text=="")return;
        //从数据库书名表中获取按关键字搜索到的书名
        QStringList lsname=key_search(text);
        //给preview设置布局
        preview->setLayout(preview->getui()->layout);

        //根据lsname创造相对应的书名按钮给用户提供预览
        /*QToolButton*bu =new QToolButton(preview2);
        bu->setText("deassdad");
        QToolButton*bu1 =new QToolButton(preview2);
        bu1->setText("dsdasds");
        QToolButton*bu2 =new QToolButton(preview2);
        bu2->setText("qweedqwSd");
        preview2->getui()->layout->addWidget(bu);
        preview2->getui()->layout->addWidget(bu1);
        preview2->getui()->layout->addWidget(bu2);
        bu->setIcon(QIcon(":/pic"));
        bu->setIconSize(QSize(50,50));*/
//        preview2->getui()->toolButton->setIcon(QIcon(":/pic"));
//        preview2->getui()->toolButton->setIconSize(QSize(5000,3000));

        //preview2->getui()->toolButton_2->setIcon(QIcon(":/pic"));
        //preview2->getui()->toolButton_2->setIconSize(QSize(1000,500));

        //preview2->getui()->toolButton_3->setIcon(QIcon(":/pic"));
        //preview2->getui()->toolButton_3->setIconSize(QSize(1000,500));
        /*for(int i=0;i<lsname.size();i++)
        {

             QToolButton*bu =new QToolButton(preview2);
             //qDebug()<<lsname.size();
             preview2->getui()->layout->addWidget(bu);
             bu->setObjectName(QString("bu%1").arg(i));
             QString name=lsname[i];
             bu->setText(name);
             bu->setIcon(QIcon(":/pic"));
             bu->setIconSize(QSize(50000,50000));
             bu->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
             //preview->layout()->addWidget(bu);
             preview2->getui()->layout->setStretchFactor(bu, i+1);
             //vlayout->addWidget(bu);


         }*/
        for(int i=0;i<lsname.size();i++)
        {

            QLabel *la =new QLabel(preview2);
            //qDebug()<<lsname.size();
            preview2->getui()->layout->addWidget(la);
            la->setObjectName(QString("bu%1").arg(i));
            QString name=lsname[i];
            la->setText(name);
            //la->setIcon(QIcon(":/pic1.png"));
            QIcon* icon=new QIcon(":/pic1.png");
            la->setPixmap(icon->pixmap(100,50));

            la->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            //la->setScaledContents(true);
            //preview->layout()->addWidget(bu);
            preview2->getui()->layout->setStretchFactor(la,i+1);
            //vlayout->addWidget(bu);


        }

        this->hide();
        preview->show();


        //点击书本按钮显示书籍内容
        connect(preview->findChild<QToolButton*>("bu0"),&QPushButton::clicked,preview,[=](){
            preview->hide();
            //显示书内容
            view->show();
            QSqlQuery q;
            QString sql="select content from book";
            q.exec(sql);
            while(q.next())
            {
                QString s=q.value(0).toString();
                //qDebug()<<s;
                view->getui()->textEdit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


                view->getui()->textEdit->append(q.value(0).toString());
             }
        });

        /**/



    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
