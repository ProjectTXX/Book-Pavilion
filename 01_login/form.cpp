#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}
QString Form::getAccount()
{
    return ui->textEdit->toPlainText();
}
QString Form::getPassword()
{
    return ui->textEdit_2->toPlainText();
}
QString Form::getPassword_()
{
    return ui->textEdit_3->toPlainText();
}
Ui::Form* Form::getui()
{
    return ui;
}
Form::~Form()
{
    delete ui;
}
