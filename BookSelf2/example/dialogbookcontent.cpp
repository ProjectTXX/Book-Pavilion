#include "dialogbookcontent.h"
#include "ui_dialogbookcontent.h"

DialogBookcontent::DialogBookcontent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBookcontent)
{
    ui->setupUi(this);
}

DialogBookcontent::~DialogBookcontent()
{
    delete ui;
}

Ui::DialogBookcontent* DialogBookcontent::getui()
{
    return ui;
}
