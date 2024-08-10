#include "preview.h"
#include "ui_preview.h"

Preview::Preview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Preview)
{
    ui->setupUi(this);
}
Ui::Preview* Preview::getui()
{
    return ui;
}
Preview::~Preview()
{
    delete ui;
}
