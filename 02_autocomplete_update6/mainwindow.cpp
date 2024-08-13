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
#include<QWidget>
#include<bitset>
#include<QPalette>
#include<QRandomGenerator>
//一个创建book封面的函数
BookWidget* bkcover_create(QString bkname,BookWidget* bookwidget,Preview* preview)
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
    QSqlQuery sq;
    QString sql=QString("select author from book where title='%1'").arg(bkname);
    sq.exec(sql);
    sq.next();
    auth->setText(QString("作者：%1").arg(sq.value(0).toString()));
    //*********
    auth->setStyleSheet("QLabel{font-size:15pt}");//15
    toolbu->setText(bkname);
    QLabel* label_intro=new QLabel(bookwidget);
    //********************
    label_intro->setStyleSheet("QLabel{font-size:13pt}");//13
    QLabel* label2_empty=new QLabel(bookwidget);
    vlayout2->addWidget(toolbu);
    vlayout2->addWidget(auth);
    vlayout2->addWidget(label2_empty);
    vlayout2->addWidget(label_intro);
    vlayout2->setStretchFactor(toolbu,5);
    vlayout2->setStretchFactor(auth,5);
    vlayout2->setStretchFactor(label2_empty,1);
    vlayout2->setStretchFactor(label_intro,15);
    //******************
    toolbu->setStyleSheet("QToolButton{font-size:20pt}");//20

    QLabel* label_empty=new QLabel(bookwidget);
    QPushButton* pb1=new QPushButton(bookwidget);
    pb1->setText("书籍详情");
    //*****************
    pb1->setStyleSheet("QPushButton{font-size:20pt}");//20
    vlayout3->addWidget(label_empty);
    vlayout3->addWidget(pb1);

    QLabel* label_extro1=new QLabel(bookwidget);
    QLabel* label_extro2=new QLabel(bookwidget);
    QLabel* label_extro3=new QLabel(bookwidget);
    QLabel* label_extro4=new QLabel(bookwidget);
    QLabel* label_extro5=new QLabel(bookwidget);
    label_extro1->setText("788万总字数\n100万总订阅");
    //************************
    label_extro1->setStyleSheet("QLabel{font-size:15pt}");//15
    QPushButton* pb2=new QPushButton(bookwidget);
    pb2->setText("加入书架");
    //**********************
    pb2->setStyleSheet("QPushButton{font-size:20pt}");//20
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
    //*************************
    label_cover->setFixedSize(QSize(500,400));//500,400

    s=QString("select introduce from book where id=%1").arg(id);
    q.exec(s);
    q.next();
    s=q.value(0).toString();
    label_intro->setText(s);


    //这是打开view界面的按钮
    QObject::connect(toolbu,&QToolButton::clicked,preview,[=](){
        preview->hide();

        View* view=new View;

        //设计view的封面
        //下一章和上一章的按钮
        QToolButton* pre=new QToolButton(view);
        QToolButton* next=new QToolButton(view);
        QToolButton* view_login=new QToolButton(view);
        QLabel* view_empty=new QLabel(view);
        view_login->setText("登录");
        view_login->setStyleSheet("QToolButton{""font-size:16pt;"
                                  "font-family:'楷体'""}");
        view_empty->setText("                                    ");
        pre->setText("上一章");
        //**********************
        pre->setStyleSheet("QToolButton{font-size: 15pt}"
                           "QToolButton{font-weight:bold}");
        next->setStyleSheet("QToolButton{font-size: 15pt}"
                            "QToolButton{font-weight:bold}");
        next->setText("下一章");

        QLabel* l=new QLabel(view);
        l->setText("                                  "
                   "                                  "
                   "                                  "
                   "                                  ");

        QToolBar* toolbar=new QToolBar(view);
        QTextEdit* textedit=new QTextEdit(view);
        QListWidget* lwleft=new QListWidget(view);
        QWidget* widgetright=new QWidget(view);


        //创建到顶和到底按钮
        QToolButton* upbt=new QToolButton(widgetright);
        QToolButton* downbt=new QToolButton(widgetright);
        upbt->setIcon(QIcon(":/up.png"));
        downbt->setIcon(QIcon(":/down.png"));
        upbt->setIconSize(QSize(100,100));
        downbt->setIconSize(QSize(100,100));
        upbt->setGeometry(0,900,100,100);
        downbt->setGeometry(0,1000,100,100);

        QObject::connect(upbt,&QToolButton::clicked,view,[=](){
            textedit->verticalScrollBar()->setValue(0);
        });

        QObject::connect(downbt,&QToolButton::clicked,view,[=](){
            textedit->verticalScrollBar()->setValue(textedit->verticalScrollBar()->maximum());
        });

        QHBoxLayout* hlayout=new QHBoxLayout(view);
        view->getui()->verticalLayout->addWidget(toolbar);
        view->getui()->verticalLayout->addLayout(hlayout);
        hlayout->addWidget(lwleft);
        hlayout->addWidget(textedit);
        hlayout->addWidget(widgetright);
        hlayout->setStretchFactor(lwleft,1);
        hlayout->setStretchFactor(textedit,4);
        hlayout->setStretchFactor(widgetright,1);
        textedit->verticalScrollBar()->setValue(1);
        textedit->setReadOnly(true);

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


        toolbar->addWidget(l);
        toolbar->addWidget(pre);
        toolbar->addWidget(next);

        toolbar->addWidget(view_empty);
        toolbar->addWidget(view_login);

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
        QObject::connect(back,&QToolButton::clicked,view,[=](){
            view->close();
            preview->show();
        });
        QObject::connect(font,&QPushButton::clicked,view,[=](){
           bool ok;
           QFont select=QFontDialog::getFont(&ok,view);
           if(ok)
           {

               textedit->setFont(select);
               QPalette textEditPalette = textedit->palette();
               qDebug()<<textEditPalette.color(QPalette::Text).name();
               textEditPalette.setColor(QPalette::Text, QColor(textEditPalette.color(QPalette::Text).name()));

               textedit->setStyleSheet(QString("QTextEdit { ""font-family:'楷体';"
                                       "background-color: rgb(255, 244, 240);"" }"));
               textedit->setPalette(textEditPalette);

           }
        });
        QObject::connect(color, &QToolButton::clicked, view, [=]() {
            QColor select = QColorDialog::getColor(Qt::black, view); // 假设view是QWidget的实例
            if (select.isValid()) {
                textedit->setStyleSheet(QString("QTextEdit {"
                                                  "color: %1;"
                                                  "background-color: rgb(255, 244, 240);"
                                                  "font-family: '楷体';"
                                                  "font-size: %2pt;"
                                                  "}").arg(select.name()).arg(textedit->font().pointSize()));
            }
        });
        QObject::connect(background,&QPushButton::clicked,view,[=](){
            QColor select=QColorDialog::getColor(Qt::blue,view);
            if(select.isValid())
            {
                textedit->setStyleSheet(QString("QTextEdit {"
                                                  "background-color: %1;"
                                                  "font-family: '楷体';"
                                                  "font-size: %2pt;"
                                                  "}").arg(select.name()).arg(textedit->font().pointSize()));


            }
        });



        view->show();
        view->showMaximized();
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
        /*QFont font1;
        font1.setBold(true);
        font1.setPointSize(20);
        textedit->setCurrentFont(font1);*/

        textedit->append(QString("%1").arg(que.value(0).toString()));

        textedit->append("\n");




        /*font1.setBold(false);
        font1.setPointSize(16);
        textedit->setCurrentFont(font1);*/
        textedit->append(q.value(0).toString());
        textedit->setStyleSheet("QTextEdit{""font-size:22pt;"
                                "background-color: rgb(255, 244, 240);"
                                "font-family:'楷体';""}");


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
            QListWidgetItem* it=new QListWidgetItem(lwleft);
            it->setSizeHint(QSize(100,50));

            s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(i);
            que.exec(s);
            que.next();

            lwleft->addItem(it);
            it->setText(QString("%1").arg(que.value(0).toString()));
            it->setData(Qt::UserRole,QString("%1").arg(que.value(0).toString()));
            QFont font;
            font.setPointSize(16);
            it->setFont(font);

        }

        //设置item点按槽函数
        QObject::connect(lwleft,&QListWidget::itemClicked,view,[=](QListWidgetItem* item){
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
            /*QFont font1;
            font.setBold(true);
            font.setPointSize(20);
            textedit->setCurrentFont(font);*/
            textedit->append(QString("%1").arg(que.value(0).toString()));
            textedit->append("\n");

            /*font1.setBold(false);
            font1.setPointSize(16);
            textedit->setCurrentFont(font1);*/

            s=QString("select content from book_content where book_id=%1 and chapter_title='%2'").arg(id).arg(chapter_title);
            que.exec(s);
            que.next();
            textedit->append(que.value(0).toString());
            textedit->verticalScrollBar()->setValue(0);
            textedit->setStyleSheet("QTextEdit{""font-size:22pt;"
                                    "background-color: rgb(255, 244, 240);"
                                    "font-family:'楷体';""}");

            s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(id);
            que.exec(s);
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

            /*QFont font;
            font.setBold(true);
            font.setPointSize(20);
            textedit->setCurrentFont(font);*/
            textedit->append(QString("%1").arg(q.value(0).toString()));
            textedit->append("\n");

            s=QString("select content from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(cnt);
            q.exec(s);
            if(q.next())
            {
                /*font.setBold(false);
                font.setPointSize(16);
                textedit->setCurrentFont(font);*/
                textedit->append(q.value(0).toString());
                textedit->verticalScrollBar()->setValue(0);
                //更新book表的last_browser
                s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(id);
                q.exec(s);
            }
            else {
               qDebug()<<"查询内容失败";
            }
            textedit->setStyleSheet("QTextEdit{""font-size:22pt;"
                                    "background-color: rgb(255, 244, 240);"
                                    "font-family:'楷体';""}");


        });


        //上一章按钮
        QObject::connect(pre,&QToolButton::clicked,view,[=](){
            //获取资源
            qDebug()<<"dsdsaddsfdfdf";
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

            /*QFont font;
            font.setBold(true);
            font.setPointSize(20);
            textedit->setCurrentFont(font);*/
            textedit->append(QString("%1").arg(q.value(0).toString()));
            textedit->append("\n");

            s=QString("select content from book_content where book_id=%1 and book_chapter_id=%2").arg(id).arg(cnt);
            q.exec(s);
            if(q.next())
            {
                /*font.setBold(false);
                font.setPointSize(16);
                textedit->setCurrentFont(font);*/
                textedit->append(q.value(0).toString());
                textedit->verticalScrollBar()->setValue(0);
                //更新book表的last_browser
                s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(id);
                q.exec(s);
            }
            else {
               qDebug()<<"查询内容失败";
            }

            textedit->setStyleSheet("QTextEdit{""font-size:22pt;"
                                    "background-color: rgb(255, 244, 240);"
                                    "font-family:'楷体';""}");


        });

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
void bookshelf_flush(MainWindow* ptr,Ui::MainWindow *ui)
{
    std::bitset<10000>bt;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<3;j++)
        {
            unsigned long long bkid;

            while(1)
            {
               int randomInt = QRandomGenerator::global()->bounded(10000); // 生成一个0到9999的随机整数
               bkid=randomInt%39;
               if(!bt[bkid]&&bkid!=0)
               {
                   bt[bkid]=1;
                   break;
               }

            }
            BookshelfCover* bookshelfcover=new BookshelfCover(ptr);
            bookshelfcover->getui()->label->setFixedSize(QSize(150,200));
            bookshelfcover->getui()->label->setScaledContents(true);
            QSqlQuery query;
            QString s=QString("select title from book where id=%1").arg(bkid);
            query.exec(s);
            query.next();
            bookshelfcover->getui()->toolButton->setText(QString("%1").arg(query.value(0).toString()));
            bookshelfcover->getui()->toolButton->setStyleSheet("QToolButton{font-size:13pt}"
                                                               "QToolButton{font-weight:bold}");
            s=QString("select img from image where book_id=%1").arg(bkid);
            query.exec(s);
            query.next();
            QPixmap pix;
            pix.loadFromData(query.value(0).toByteArray());
            bookshelfcover->getui()->label->setPixmap(pix);
            s=QString("select introduce from book where id=%1").arg(bkid);
            query.exec(s);
            query.next();
            bookshelfcover->getui()->label_2->setText(query.value(0).toString());
            bookshelfcover->getui()->label_2->setWordWrap(true);
            ui->tableWidget->setCellWidget(i,j,bookshelfcover);







            //这是打开view界面的按钮
            QObject::connect(bookshelfcover->getui()->toolButton,&QToolButton::clicked,ptr,[=](){
                ptr->hide();

                View* view1=new View;
                view1->setId(static_cast<int>(bkid));
                //设计view的封面
                //下一章和上一章的按钮
                QToolButton* pre=new QToolButton(view1);
                QToolButton* next=new QToolButton(view1);
                pre->setText("上一章");
                //**********************
                pre->setStyleSheet("QToolButton{font-size: 15pt}"
                                   "QToolButton{font-weight:bold}");
                next->setStyleSheet("QToolButton{font-size: 15pt}"
                                    "QToolButton{font-weight:bold}");
                next->setText("下一章");
                QLabel* v_empty=new QLabel(view1);
                v_empty->setText("                                    ");
                QToolButton* v_login=new QToolButton(view1);
                QObject::connect(v_login,&QToolButton::clicked,view1,[=](){

                });
                v_login->setText("登录");

                v_login->setStyleSheet("QToolButton{""font-size:16pt;"
                                          "font-family:'楷体'""}");
                QLabel* l=new QLabel(view1);
                l->setText("                                  "
                           "                                  "
                           "                                  "
                           "                                  ");


                QToolBar* toolbar=new QToolBar(view1);
                QTextEdit* textedit=new QTextEdit(view1);
                QListWidget* lwleft=new QListWidget(view1);
                QWidget* widgetright=new QWidget(view1);


                //创建到顶和到底按钮
                QToolButton* upbt=new QToolButton(widgetright);
                QToolButton* downbt=new QToolButton(widgetright);
                upbt->setIcon(QIcon(":/up.png"));
                downbt->setIcon(QIcon(":/down.png"));
                upbt->setIconSize(QSize(100,100));
                downbt->setIconSize(QSize(100,100));
                upbt->setGeometry(0,900,100,100);
                downbt->setGeometry(0,1000,100,100);

                QObject::connect(upbt,&QToolButton::clicked,view1,[=](){
                    textedit->verticalScrollBar()->setValue(0);
                });

                QObject::connect(downbt,&QToolButton::clicked,view1,[=](){
                    textedit->verticalScrollBar()->setValue(textedit->verticalScrollBar()->maximum());
                });

                QHBoxLayout* hlayout=new QHBoxLayout(view1);
                view1->getui()->verticalLayout->addWidget(toolbar);
                view1->getui()->verticalLayout->addLayout(hlayout);
                hlayout->addWidget(lwleft);
                hlayout->addWidget(textedit);
                hlayout->addWidget(widgetright);
                hlayout->setStretchFactor(lwleft,1);
                hlayout->setStretchFactor(textedit,4);
                hlayout->setStretchFactor(widgetright,1);
                textedit->verticalScrollBar()->setValue(1);
                textedit->setReadOnly(true);

                QToolButton* font=new QToolButton(view1);
                QToolButton* color=new QToolButton(view1);
                QToolButton* background=new QToolButton(view1);
                QToolButton* eyeprotect=new QToolButton(view1);
                QToolButton* back=new QToolButton(view1);


                toolbar->addWidget(back);
                toolbar->addWidget(font);
                toolbar->addWidget(color);
                toolbar->addWidget(background);
                toolbar->addWidget(eyeprotect);

                toolbar->addWidget(l);
                toolbar->addWidget(pre);
                toolbar->addWidget(next);
                toolbar->addWidget(v_empty);
                toolbar->addWidget(v_login);

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
                QObject::connect(back,&QToolButton::clicked,view1,[=](){
                    view1->close();
                    ptr->show();
                });
                QObject::connect(font,&QPushButton::clicked,view1,[=](){
                   bool ok;
                   QFont select=QFontDialog::getFont(&ok,view1);
                   if(ok)
                   {
                       textedit->setFont(select);
                       QPalette textEditPalette = textedit->palette();
                       qDebug()<<textEditPalette.color(QPalette::Text).name();
                       textEditPalette.setColor(QPalette::Text, QColor(textEditPalette.color(QPalette::Text).name()));

                       textedit->setStyleSheet(QString("QTextEdit { ""font-family:'楷体';"
                                               "background-color: rgb(255, 244, 240);"" }"));
                       textedit->setPalette(textEditPalette);
                   }
                });
                QObject::connect(color,&QToolButton::clicked,view1,[=](){
                    QColor select=QColorDialog::getColor(Qt::black,view1);
                    if(select.isValid())
                    {
                        textedit->setStyleSheet(QString("QTextEdit {"
                                                          "color: %1;"
                                                          "background-color: rgb(255, 244, 240);"
                                                          "font-family: '楷体';"
                                                          "font-size: %2pt;"
                                                          "}").arg(select.name()).arg(textedit->font().pointSize()));
                    }

                });
                QObject::connect(background, &QPushButton::clicked, view1, [=]() {
                    QColor select = QColorDialog::getColor(Qt::blue, view1);
                    if (select.isValid()) {
                        // 修正后的样式表字符串，所有规则都在一个大括号对中
                        textedit->setStyleSheet(QString("QTextEdit {"
                                                          "background-color: %1;"
                                                          "font-family: '楷体';"
                                                          "font-size: %2pt;"
                                                          "}").arg(select.name()).arg(textedit->font().pointSize()));
                    }
                });



                view1->show();
                view1->showMaximized();
                QSqlQuery que;
                QString s;


                //view->setId(bkid);
                s=QString("select last_browser from book where id=%1").arg(bkid);
                que.exec(s);
                que.next();
                int last=que.value(0).toInt();

                textedit->setText("");
                s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(bkid).arg(last);
                que.exec(s);
                que.next();
                qDebug()<<que.value(0).toString();
                /*QFont font1;
                font1.setBold(true);
                font1.setPointSize(20);
                textedit->setCurrentFont(font1);*/

                textedit->append(QString("%1").arg(que.value(0).toString()));

                textedit->append("\n");




                /*font1.setBold(false);
                font1.setPointSize(16);
                textedit->setCurrentFont(font1);*/
                //textedit->append(que.value(0).toString());
                textedit->setStyleSheet("QTextEdit{""font-size:22pt;"
                                        "background-color: rgb(255, 244, 240);"
                                        "font-family:'楷体';""}");
                s=QString("select content from book_content where book_id=%1 and book_chapter_id=%2").arg(bkid).arg(last);
                que.exec(s);
                que.next();
                textedit->append(que.value(0).toString());
                s=QString("select bar_value from book where id=%1").arg(bkid);
                que.exec(s);
                que.next();
                textedit->verticalScrollBar()->setValue(que.value(0).toInt());




                s=QString("select sum_chapter from book where id='%1'").arg(bkid);
                que.exec(s);
                que.next();
                int count=que.value(0).toInt();
                //将目录显示在lwright上
                for(int i=1;i<=count;i++)
                {
                    QListWidgetItem* it=new QListWidgetItem(lwleft);
                    it->setSizeHint(QSize(100,50));

                    s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(bkid).arg(i);
                    que.exec(s);
                    que.next();

                    lwleft->addItem(it);
                    it->setText(QString("%1").arg(que.value(0).toString()));
                    it->setData(Qt::UserRole,QString("%1").arg(que.value(0).toString()));
                    QFont font;
                    font.setPointSize(16);
                    it->setFont(font);

                }

                //设置item点按槽函数
                QObject::connect(lwleft,&QListWidget::itemClicked,view1,[=](QListWidgetItem* item){
                    textedit->setText("");
                    QString chapter_title=item->data(Qt::UserRole).toString();

                    QSqlQuery que;
                    QString s=QString("select book_chapter_id from book_content where book_id=%1 and chapter_title='%2'").arg(bkid).arg(chapter_title);
                    que.exec(s);
                    que.next();
                    int cnt=que.value(0).toInt();

                    s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(bkid).arg(cnt);
                    que.exec(s);
                    que.next();
                    /*QFont font1;
                    font.setBold(true);
                    font.setPointSize(20);
                    textedit->setCurrentFont(font);*/
                    textedit->append(QString("%1").arg(que.value(0).toString()));
                    textedit->append("\n");

                    /*font1.setBold(false);
                    font1.setPointSize(16);
                    textedit->setCurrentFont(font1);*/

                    s=QString("select content from book_content where book_id=%1 and chapter_title='%2'").arg(bkid).arg(chapter_title);
                    que.exec(s);
                    que.next();
                    textedit->append(que.value(0).toString());
                    textedit->verticalScrollBar()->setValue(0);
                    textedit->setStyleSheet("QTextEdit{""font-size:22pt;"
                                            "background-color: rgb(255, 244, 240);"
                                            "font-family:'楷体';""}");
                    s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(bkid);
                    que.exec(s);
                });


                //下一章按钮
                QObject::connect(next,&QToolButton::clicked,view1,[=](){
                    //获取资源
                    textedit->setText("");
                    QSqlQuery q;
                    QString s=QString("select sum_chapter from book where id=%1").arg(bkid);
                    q.exec(s);
                    q.next();
                    int sum=q.value(0).toInt();
                    s=QString("select last_browser from book where id=%1").arg(bkid);
                    q.exec(s);
                    q.next();
                    int cnt=q.value(0).toInt();
                    if(cnt>=sum)qDebug()<<"后面没有了";
                    else cnt+=1;

                    s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(bkid).arg(cnt);
                    q.exec(s);
                    q.next();
                    qDebug()<<q.value(0).toString();

                    /*QFont font;
                    font.setBold(true);
                    font.setPointSize(20);
                    textedit->setCurrentFont(font);*/
                    textedit->append(QString("%1").arg(q.value(0).toString()));
                    textedit->append("\n");

                    s=QString("select content from book_content where book_id=%1 and book_chapter_id=%2").arg(bkid).arg(cnt);
                    q.exec(s);
                    if(q.next())
                    {
                        /*font.setBold(false);
                        font.setPointSize(16);
                        textedit->setCurrentFont(font);*/
                        textedit->append(q.value(0).toString());
                        textedit->verticalScrollBar()->setValue(0);
                        //更新book表的last_browser
                        s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(bkid);
                        q.exec(s);
                    }
                    else {
                       qDebug()<<"查询内容失败";
                    }
                    textedit->setStyleSheet("QTextEdit{""font-size:22pt;"
                                            "background-color: rgb(255, 244, 240);"
                                            "font-family:'楷体';""}");

                });

                //上一章按钮
                QObject::connect(pre,&QToolButton::clicked,view1,[=](){
                    //获取资源
                    qDebug()<<"dsdsaddsfdfdf";
                    textedit->setText("");
                    QSqlQuery q;
                    QString s=QString("select last_browser from book where id=%1").arg(bkid);
                    q.exec(s);
                    q.next();

                    int cnt=q.value(0).toInt();
                    if(cnt>1)cnt-=1;
                    else qDebug()<<"1不能再减1了";

                    s=QString("select chapter_title from book_content where book_id=%1 and book_chapter_id=%2").arg(bkid).arg(cnt);
                    q.exec(s);
                    q.next();

                    /*QFont font;
                    font.setBold(true);
                    font.setPointSize(20);
                    textedit->setCurrentFont(font);*/
                    textedit->append(QString("%1").arg(q.value(0).toString()));
                    textedit->append("\n");

                    s=QString("select content from book_content where book_id=%1 and book_chapter_id=%2").arg(bkid).arg(cnt);
                    q.exec(s);
                    if(q.next())
                    {
                        /*font.setBold(false);
                        font.setPointSize(16);
                        textedit->setCurrentFont(font);*/
                        textedit->append(q.value(0).toString());
                        textedit->verticalScrollBar()->setValue(0);
                        //更新book表的last_browser
                        s=QString("update book set last_browser=%1 where id=%2").arg(cnt).arg(bkid);
                        q.exec(s);
                    }
                    else {
                       qDebug()<<"查询内容失败";
                    }

                    textedit->setStyleSheet("QTextEdit{""font-size:22pt;"
                                            "background-color: rgb(255, 244, 240);"
                                            "font-family:'楷体';""}");
                });
            });


        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db;
    mysqlConnect(db);

    ui->toolButton_3->setParent(ui->widget_2);
    ui->toolButton_3->setFixedSize(QSize(60,55));
    ui->toolButton_3->move(1970,0);

    connect(ui->toolButton_3,&QToolButton::clicked,this,[=](){

    });

    ui->lineEdit->setStyleSheet("QLineEdit { width: 300px; height: 60px; }");
    ui->toolButton->setStyleSheet("QToolButton{width: 60px; height: 60px;}");
    ui->toolButton->setIcon(QIcon(":/search.jpg"));
    ui->toolButton->setIconSize(QSize(60,60));



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
    auto onclicked=[=](){
        QString text=ui->lineEdit->text();
        preview=new Preview;
        if(text=="")return;
        //从数据库书名表中获取按关键字搜索到的书名
        QStringList lsname=key_search(text);

        //给preview设置布局
        preview->setLayout(preview->getui()->layout);
        QToolBar* tb=new QToolBar(preview);
        QLabel* label_empty=new QLabel(preview);
        label_empty->setText("                                                        "
                             "                                                        "
                             "                                                        "
                             "                                                        "
                             "                               ");
        QToolButton* button_login=new QToolButton(preview);
        button_login->setText("登录");
        button_login->setStyleSheet("QToolButton{""font-size:16pt;"
                                    "font-family:'楷体';""}");

        connect(button_login,&QToolButton::clicked,preview,[=](){

        });


        QListView* lv1=new QListView(preview);
        QPushButton* pv_back=new QPushButton(preview);
        QHBoxLayout* pre_hlayout=new QHBoxLayout(preview);
        preview->getui()->layout->addWidget(tb);
        preview->getui()->layout->addLayout(pre_hlayout);
        pre_hlayout->addWidget(lv1);
        pre_hlayout->setStretchFactor(lv1,1);
        QListWidget* lw=new QListWidget(preview);
        pre_hlayout->addWidget(lw);
        pre_hlayout->setStretchFactor(lw,3);
        QListView* lv2=new QListView(preview);
        pre_hlayout->addWidget(lv2);
        pre_hlayout->setStretchFactor(lv2,1);

        pv_back->setText("返回");
        pv_back->setStyleSheet("QPushButton{font-size:13pt}"
                               "QPushButton{font-weight:bold}");
        tb->addWidget(pv_back);
        tb->addWidget(label_empty);
        tb->addWidget(button_login);
        connect(pv_back,&QPushButton::clicked,preview,[=](){
            preview->hide();
            this->show();
        });
        lw->setWordWrap(true);

        for(int i=0;i<lsname.size();i++)
        {
            QString name=lsname[i];
            BookWidget* bookwidget=new BookWidget(preview);


            QListWidgetItem* it=new QListWidgetItem(lw);
            /*if(i<1)
            {
                QWidget* wi=new QWidget(preview);
                BookWidget* rewidget=new BookWidget(wi);
                rewidget=bkcover_create("遮天",rewidget,preview,view);

                wi->show();

            }*/
            bookwidget=bkcover_create(name,bookwidget,preview);
            it->setData(Qt::UserRole,QString("%1").arg(lsname[i]));
            //it->setSizeHint(QSize(800,600));
            it->setSizeHint(bookwidget->sizeHint());
            lw->addItem(it);
            lw->setItemWidget(it,bookwidget);
        }



        this->hide();
        preview->show();
        preview->showMaximized();
    };

    connect(ui->lineEdit,&QLineEdit::returnPressed,this,onclicked);
    connect(ui->toolButton,&QToolButton::clicked,this,onclicked);

    //设置本界面的tablewidget来承载小说书架

    ui->tableWidget->setRowCount(10);//只上三十本小说试试水，然后提供用户点击刷新
    ui->tableWidget->setColumnCount(3);
    for(int i=0;i<10;i++)
    {
        ui->tableWidget->setRowHeight(i,200);//200
        for(int j=0;j<3;j++)
        {
            ui->tableWidget->setColumnWidth(j,657);

        }
    }
    bookshelf_flush(this,ui);
    ui->toolButton_2->setIcon(QIcon(":/flush.jpg"));
    ui->toolButton_2->setIconSize(QSize(50,50));

    connect(ui->toolButton_2,&QToolButton::clicked,this,[=](){
        bookshelf_flush(this,ui);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
