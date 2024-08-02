#include "view.h"
#include "ui_view.h"
#include<QDebug>
#include<QTextEdit>
#include<QScrollBar>
#include<QSqlQuery>
View::View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
}

int View::setId(int id)
{
    this->id=id;
}
int View::getId()
{
    return id;
}
void View::closeEvent(QCloseEvent *event)
{
    QTextEdit* textedit=this->findChild<QTextEdit *>();
    if(textedit)
    {
        int value=textedit->verticalScrollBar()->value();
        QSqlQuery que;
        QString s=QString("update book set bar_value=%1 where id=%2").arg(value).arg(getId());
        que.exec(s);
    }
    QWidget::closeEvent(event);
}

View::~View()
{
    delete ui;
}
Ui::View* View::getui()
{
    return ui;
}
