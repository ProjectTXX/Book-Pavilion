#include "bookwidget.h"
#include "ui_bookwidget.h"

BookWidget::BookWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookWidget)
{
    ui->setupUi(this);
}

BookWidget::~BookWidget()
{
    delete ui;
}
