#include "dialogbookself.h"
#include "ui_dialogbookself.h"

DialogBookself::DialogBookself(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBookself)
{
    ui->setupUi(this);
    layout = new QHBoxLayout;
    vlayout = new QVBoxLayout;
    plainTextEdit = new QPlainTextEdit;
    combox = new QComboBox;
    content = new DialogBookcontent;

    QSqlQuery q;
    QString sql="select name from bookname";
    q.exec(sql);
    while(q.next())
    {
        QString s = q.value(0).toString();
        btn = new QPushButton;
        btn->setText(s);
        //connect(btn,SIGNAL(clicked()),this,SLOT(on_show()));
        connect(btn, &QPushButton::clicked, this,[=](){
            this->hide();
            content->show();
            QSqlQuery qq;
            QString sqll="select content from bookname where name='"+s+"'";
            qq.exec(sqll);

            while(qq.next())
            {
                QString ss=qq.value(0).toString();
                //ui->plainTextEdit->setPlainText(ss);
                //plainTextEdit->setPlainText(ss);

                content->getui()->textEdit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
                content->getui()->textEdit->append(ss);
            }

        });
        layout->addWidget(btn);
        combox->addItem(s);
    }
    vlayout->addWidget(combox);
    vlayout->addLayout(layout);
    //vlayout->addWidget(plainTextEdit);
    setLayout(vlayout);
}

DialogBookself::~DialogBookself()
{
    delete ui;

}
