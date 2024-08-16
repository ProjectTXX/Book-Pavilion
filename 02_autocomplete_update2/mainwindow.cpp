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
#include<QScrollBar>
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
#include<QFontDialog>
#include<QColorDialog>
#include<QToolBar>
#include<QObject>




//一个创建book封面的函数
BookWidget* bkcover_create(QString bkname,BookWidget* bookwidget,Preview* preview,View* view,QTextEdit* textedit,QListWidget* lwright,QToolBar* toolbar)
{


    QHBoxLayout* hlayout=new QHBoxLayout(bookwidget);
    bookwidget->setLayout(hlayout);


    QVBoxLayout* vlayout1=new QVBoxLayout(bookwidget);
    QVBoxLayout* vlayout2=new QVBoxLayout(bookwidget);
    QVBoxLayout* vlayout3=new QVBoxLayout(bookwidget);
    QVBoxLayout* vlayout4=new QVBoxLayout(bookwidget);

    hlayout->addLayout(vlayout1);
    hlayout->addLayout(vlayout2);
    hlayout->addLayout(vlayout3);
    hlayout->addLayout(vlayout4);

    QLabel* label_cover=new QLabel(bookwidget);
    vlayout1->addWidget(label_cover);

    QToolButton* toolbu=new QToolButton(bookwidget);
    QLabel* auth=new QLabel(bookwidget);
    auth->setText("作者：成对");
    auth->setStyleSheet("QLabel{font-size:15pt}");
    toolbu->setText(bkname);
    QLabel* label_intro=new QLabel(bookwidget);
    label_intro->setStyleSheet("QLabel{font-size:13pt}");
    QLabel* label2_empty=new QLabel(bookwidget);
    vlayout2->addWidget(toolbu);
    vlayout2->addWidget(auth);
    vlayout2->addWidget(label2_empty);
    vlayout2->addWidget(label_intro);
    vlayout2->setStretchFactor(toolbu,5);
    vlayout2->setStretchFactor(auth,5);
    vlayout2->setStretchFactor(label2_empty,1);
    vlayout2->setStretchFactor(label_intro,5);
    toolbu->setStyleSheet("QToolButton{font-size:20pt}");

    QLabel* label_empty=new QLabel(bookwidget);
    QPushButton* pb1=new QPushButton(bookwidget);
    pb1->setText("书籍详情");
    pb1->setStyleSheet("QPushButton{font-size:20pt}");
    vlayout3->addWidget(label_empty);
    vlayout3->addWidget(pb1);

    QLabel* label_extro1=new QLabel(bookwidget);
    QLabel* label_extro2=new QLabel(bookwidget);
    QLabel* label_extro3=new QLabel(bookwidget);
    QLabel* label_extro4=new QLabel(bookwidget);
    QLabel* label_extro5=new QLabel(bookwidget);
    label_extro1->setText("788万总字数\n100万总订阅");
    label_extro1->setStyleSheet("QLabel{font-size:15pt}");
    QPushButton* pb2=new QPushButton(bookwidget);
    pb2->setText("加入书架");
    pb2->setStyleSheet("QPushButton{font-size:20pt}");
    vlayout4->addWidget(label_extro1);
    vlayout4->addWidget(label_extro2);
    vlayout4->addWidget(label_extro3);
    vlayout4->addWidget(label_extro4);
    vlayout4->addWidget(label_extro5);
    vlayout4->addWidget(pb2);





    hlayout->setStretchFactor(vlayout1,2);
    hlayout->setStretchFactor(vlayout2,4);
    hlayout->setStretchFactor(vlayout3,3);
    hlayout->setStretchFactor(vlayout4,3);


    label_intro->setWordWrap(true);



    QSqlQuery q;
    QString s=QString("select id from book where title='%1'").arg(bkname);
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
    label_cover->setPixmap(pix);
    label_cover->setScaledContents(true); // 图片内容会根据标签大小缩放
    label_cover->setFixedSize(QSize(500,400));
    s=QString("select introduce from book where id=%1").arg(id);
    q.exec(s);
    q.next();
    s=q.value(0).toString();
    label_intro->setText(s);


    //下一章和上一章的按钮
    QToolButton* pre=new QToolButton(view);
    QToolButton* next=new QToolButton(view);
    pre->setText("上一章");
    pre->setStyleSheet("QToolButton{font-size: 15pt}"
                       "QToolButton{font-weight:bold}");
    next->setStyleSheet("QToolButton{font-size: 15pt}"
                        "QToolButton{font-weight:bold}");
    next->setText("下一章");

    QLabel* l=new QLabel(view);
    l->setText("                                    "
               "                                    "
               "                                    "
               "                                    ");
    toolbar->addWidget(l);
    toolbar->addWidget(pre);
    toolbar->addWidget(next);


    //设置封面上对应的按钮
    QObject::connect(toolbu,&QToolButton::clicked,preview,[=](){
        preview->hide();
        view->show();
        QSqlQuery que;
        QString s=QString("select id from book where title='%1'").arg(bkname);
        que.exec(s);
        que.next();
        int id=que.value(0).toInt();
        view->setId(id);
        s=QString("select last_browser from book where id=%1").arg(id);
        que.exec(s);
        que.next();
        int last=que.value(0).toInt();

        textedit->setText("");
        s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(last);
        que.exec(s);
        que.next();
        qDebug()<<que.value(0).toString();
        QFont font;
        font.setBold(true);
        font.setPointSize(20);
        textedit->setCurrentFont(font);
        textedit->append(QString("第%1章 %2").arg(last).arg(que.value(0).toString()));
        textedit->append("\n");




        font.setBold(false);
        font.setPointSize(16);
        textedit->setCurrentFont(font);
        textedit->append(q.value(0).toString());
        s=QString("select content from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(last);
        que.exec(s);
        que.next();
        textedit->append(que.value(0).toString());
        s=QString("select bar_value from book where id=%1").arg(id);
        que.exec(s);
        que.next();
        textedit->verticalScrollBar()->setValue(que.value(0).toInt());




        s=QString("select sum_chapter from book where title='%1'").arg(bkname);
        que.exec(s);
        que.next();
        int count=que.value(0).toInt();
        //将目录显示在lwright上
        for(int i=1;i<=count;i++)
        {
            QListWidgetItem* it=new QListWidgetItem(lwright);
            it->setSizeHint(QSize(100,50));

            s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(i);
            que.exec(s);
            que.next();

            lwright->addItem(it);
            it->setText(QString("第%1章 %2").arg(i).arg(que.value(0).toString()));
            it->setData(Qt::UserRole,QString("%1").arg(que.value(0).toString()));
            QFont font;
            font.setPointSize(17);
            it->setFont(font);

        }

        //设置item点按槽函数
        QObject::connect(lwright,&QListWidget::itemClicked,view,[=](QListWidgetItem* item){
            textedit->setText("");
            QString chapter_title=item->data(Qt::UserRole).toString();

            QSqlQuery que;
            QString s=QString("select book_chapter_id from book_content where book_id=%1 and chapter_title='%2'").arg(id).arg(chapter_title);
            que.exec(s);
            que.next();
            int cnt=que.value(0).toInt();

            s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(cnt);
            que.exec(s);
            que.next();
            QFont font;
            font.setBold(true);
            font.setPointSize(20);
            textedit->setCurrentFont(font);
            textedit->append(QString("第%1章 %2").arg(cnt).arg(que.value(0).toString()));
            textedit->append("\n");

            font.setBold(false);
            font.setPointSize(16);
            textedit->setCurrentFont(font);

            s=QString("select content from book_content where book_id=%1 and chapter_title='%2'").arg(id).arg(chapter_title);
            que.exec(s);
            que.next();
            textedit->append(que.value(0).toString());
            textedit->verticalScrollBar()->setValue(0);

            s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(id);
            que.exec(s);
        });
    });
    //下一章按钮
    QObject::connect(next,&QToolButton::clicked,view,[=](){
        //获取资源
        textedit->setText("");
        QSqlQuery q;
        QString s=QString("select sum_chapter from book where id=%1").arg(id);
        q.exec(s);
        q.next();
        int sum=q.value(0).toInt();
        s=QString("select last_browser from book where id=%1").arg(id);
        q.exec(s);
        q.next();
        int cnt=q.value(0).toInt();
        if(cnt>=sum)qDebug()<<"后面没有了";
        else cnt+=1;

        s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(cnt);
        q.exec(s);
        q.next();
        qDebug()<<q.value(0).toString();

        QFont font;
        font.setBold(true);
        font.setPointSize(20);
        textedit->setCurrentFont(font);
        textedit->append(QString("第%1章 %2").arg(cnt).arg(q.value(0).toString()));
        textedit->append("\n");

        s=QString("select content from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(cnt);
        q.exec(s);
        if(q.next())
        {
            font.setBold(false);
            font.setPointSize(16);
            textedit->setCurrentFont(font);
            textedit->append(q.value(0).toString());
            textedit->verticalScrollBar()->setValue(0);
            //更新book表的last_browser
            s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(id);
            q.exec(s);
        }
        else {
           qDebug()<<"查询内容失败";
        }


    });
    //上一章按钮
    QObject::connect(pre,&QToolButton::clicked,view,[=](){
        //获取资源
        textedit->setText("");
        QSqlQuery q;
        QString s=QString("select last_browser from book where id=%1").arg(id);
        q.exec(s);
        q.next();

        int cnt=q.value(0).toInt();
        if(cnt>1)cnt-=1;
        else qDebug()<<"1不能再减1了";

        s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(cnt);
        q.exec(s);
        q.next();
        qDebug()<<q.value(0).toString();
        QFont font;
        font.setBold(true);
        font.setPointSize(20);
        textedit->setCurrentFont(font);
        textedit->append(QString("第%1章 %2").arg(cnt).arg(q.value(0).toString()));
        textedit->append("\n");

        s=QString("select content from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(cnt);
        q.exec(s);
        if(q.next())
        {
            font.setBold(false);
            font.setPointSize(16);
            textedit->setCurrentFont(font);
            textedit->append(q.value(0).toString());
            textedit->verticalScrollBar()->setValue(0);
            //更新book表的last_browser
            s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(id);
            q.exec(s);
        }
        else {
           qDebug()<<"查询内容失败";
        }


    });
    return bookwidget;

}
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
    //创建一个view实例
    view=new View;

    //布局view界面
    QToolBar* toolbar=new QToolBar(view);
    QTextEdit* textedit=new QTextEdit(view);
    QListWidget* lwleft=new QListWidget(view);
    QListWidget* lwright=new QListWidget(view);
    QHBoxLayout* hlayout=new QHBoxLayout(view);
    view->getui()->verticalLayout->addWidget(toolbar);
    view->getui()->verticalLayout->addLayout(hlayout);
    hlayout->addWidget(lwleft);
    hlayout->addWidget(textedit);
    hlayout->addWidget(lwright);
    hlayout->setStretchFactor(lwleft,1);
    hlayout->setStretchFactor(textedit,4);
    hlayout->setStretchFactor(lwright,1);
    textedit->verticalScrollBar()->setValue(1);
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
            QString name=lsname[i];
            BookWidget* bookwidget=new BookWidget(preview);


            QListWidgetItem* it=new QListWidgetItem(lw);
            bookwidget=bkcover_create(name,bookwidget,preview,view,textedit,lwright,toolbar);
            it->setData(Qt::UserRole,QString("%1").arg(lsname[i]));
            //it->setSizeHint(QSize(800,600));
            it->setSizeHint(bookwidget->sizeHint());
            lw->addItem(it);
            lw->setItemWidget(it,bookwidget);
        }



        this->hide();
        preview->show();
    });

    //设置默认情况下的字体大小以及背景颜色
    textedit->setStyleSheet("QTextEdit{font-size:16pt}");
    //添加按钮选项

    QToolButton* font=new QToolButton(view);
    QToolButton* color=new QToolButton(view);
    QToolButton* background=new QToolButton(view);
    QToolButton* eyeprotect=new QToolButton(view);
    QToolButton* back=new QToolButton(view);


    toolbar->addWidget(back);
    toolbar->addWidget(font);
    toolbar->addWidget(color);
    toolbar->addWidget(background);
    toolbar->addWidget(eyeprotect);


    back->setText("返回");
    back->setStyleSheet("QToolButton{font-size: 13pt}"
                        "QToolButton{font-weight:bold}");
    font->setText("字体大小");
    font->setStyleSheet("QToolButton{font-size: 12pt}");
    color->setText("字体颜色");
    color->setStyleSheet("QToolButton{font-size: 12pt}");
    background->setText("背景颜色");
    background->setStyleSheet("QToolButton{font-size: 12pt}");
    eyeprotect->setText("护眼模式");
    eyeprotect->setStyleSheet("QToolButton{font-size: 13pt}");


    //选择按钮的设置
    connect(back,&QToolButton::clicked,view,[=](){
        view->hide();
        preview->show();
    });
    connect(font,&QPushButton::clicked,view,[=](){
       bool ok;
       QFont select=QFontDialog::getFont(&ok,view);
       if(ok)
       {
           textedit->setFont(select);
       }
    });
    connect(color,&QToolButton::clicked,view,[=](){
        QColor select=QColorDialog::getColor(Qt::black,view);
        if(select.isValid())
        {
            textedit->setStyleSheet(QString("QTextEdit{color:%1};").arg(select.name()));
        }

    });
    connect(background,&QPushButton::clicked,view,[=](){
        QColor select=QColorDialog::getColor(Qt::blue,view);
        if(select.isValid())
        {
            textedit->setStyleSheet(QString("QTextEdit{background-color:%1};").arg(select.name()));
        }
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
