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
#include<QTextEdit>
#include<QListWidget>
#include<QListView>
#include<QByteArray>
//用字符匹配方法实现关键字搜索
QStringList key_search(QString text)
{
    QSqlQuery qu;
    QString s="select title from book";
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
    QSqlDatabase db;
    mysqlConnect(db);
    ui->setupUi(this);
    //创建一个preview实例
    preview=new Preview;
    //创建一个preview2类型，将preview2放在preview里面的psa里，再在preview2里面放别的控件实现滚动效果
    //preview2=new Preview2;
    //创建一个view实例
    view=new View;
    view->setLayout(view->getui()->layout);
    view->getui()->layout->setStretchFactor(view->getui()->listWidget,1);
    view->getui()->layout->setStretchFactor(view->getui()->sa,5);
    view->getui()->layout->setStretchFactor(view->getui()->listWidget_2,1);
    //创建一个滑动窗口psa并将它放入preview布局中
    //QScrollArea* psa=new QScrollArea(preview);
    //preview->getui()->layout->addWidget(psa);
    //psa->setWidgetResizable(true);

    //设置psa的中心控件为preview2
    //psa->setWidget(preview2);

    //创建一个滑动窗口sa并将它放入view布局中,并且把textEdit放入sa中
    QTextEdit* textedit=new QTextEdit();
    view->getui()->sa->setWidget(textedit);
    textedit->setReadOnly(true);




    //将查询到的内容放入list，然后通过list来提供自动补全功能
    QStringList list;
    QSqlQuery que;
    QString sql="select title from book";
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
    connect(ui->lineEdit,&QLineEdit::returnPressed,this,[=](){
        QString text=ui->lineEdit->text();
        if(text=="")return;
        //从数据库书名表中获取按关键字搜索到的书名
        QStringList lsname=key_search(text);
        qDebug()<<lsname;
        //给preview设置布局
        preview->setLayout(preview->getui()->layout);

        QListView* lv1=new QListView(preview);
        preview->getui()->layout->addWidget(lv1);
        preview->getui()->layout->setStretchFactor(lv1,1);
        QListWidget* lw=new QListWidget(preview);
        preview->getui()->layout->addWidget(lw);
        preview->getui()->layout->setStretchFactor(lw,3);
        QListView* lv2=new QListView(preview);
        preview->getui()->layout->addWidget(lv2);
        preview->getui()->layout->setStretchFactor(lv2,1);

        lw->setWordWrap(true);

        for(int i=0;i<lsname.size();i++)
        {
            QListWidgetItem* it=new QListWidgetItem(lw);
            it->setSizeHint(QSize(100,500));
            lw->addItem(it);
            QSqlQuery q;
            QString s=QString("select id from book where title='%1'").arg(lsname[i]);
            q.exec(s);
            q.next();
            int id=q.value(0).toInt();

            s=QString("select img from image where book_id=%1").arg(id);
            q.exec(s);
            q.next();
            QByteArray image=q.value(0).toByteArray();
            QPixmap pix;
            if(image.isEmpty())
            {
                qDebug("image is empty");
                exit(1);
            }
            pix.loadFromData(image);
            if(pix.isNull())
            {
                qDebug("pix is null");
                exit(1);
            }
            QIcon icon(pix);
            it->setIcon(icon);
            lw->setIconSize(QSize(2000,500));
            s=QString("select introduce from book where id=%1").arg(id);
            q.exec(s);
            q.next();
            s=q.value(0).toString();
            it->setText(s);

        }

        connect(lw,&QListWidget::itemClicked,preview,[=](QListWidgetItem* item){
            preview->hide();
            view->show();
            QSqlQuery que;
            QString sql="select content from book_content where book_id=36";
            que.exec(sql);
            que.next();
            textedit->append(que.value(0).toString());
        });
        //为预览界面设置按钮书本
        /*for(int i=0;i<lsname.size();i++)
        {

             QToolButton*bu =new QToolButton(preview2);
             preview2->getui()->layout->addWidget(bu);
             bu->setObjectName(QString("bu%1").arg(i));
             QString name=lsname[i];
             bu->setText(name);
             bu->setIcon(QIcon(":/pic"));
             bu->setIconSize(QSize(1000,500));
             bu->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
             preview2->getui()->layout->setStretchFactor(bu, i+1);
             connect(bu,&QPushButton::clicked,preview,[=](){
                 preview->hide();
                 //显示书内容
                 view->show();
                 QSqlQuery q;
                 QString sql=QString("select id from book where title='%1'").arg(name);
                 q.exec(sql);
                 q.next();
                 sql=QString("select content from book_content where book_id='%1'").arg(q.value(0).toInt());
                 q.exec(sql);
                 while(q.next())
                 {
                     QString s=q.value(0).toString();
                     textedit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
                     textedit->append(q.value(0).toString());
                 }
             });
         }*/
        this->hide();
        preview->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
