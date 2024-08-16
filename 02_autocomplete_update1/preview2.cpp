#include "preview2.h"
#include "ui_preview2.h"

Preview2::Preview2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Preview2)
{
    ui->setupUi(this);
}
Ui::Preview2* Preview2::getui()
{
    return ui;
}
Preview2::~Preview2()
{
    delete ui;
}
