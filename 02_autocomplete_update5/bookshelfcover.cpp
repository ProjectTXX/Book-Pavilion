#include "bookshelfcover.h"
#include "ui_bookshelfcover.h"

BookshelfCover::BookshelfCover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookshelfCover)
{
    ui->setupUi(this);
}
Ui::BookshelfCover * BookshelfCover::getui()
{
    return ui;
}
BookshelfCover::~BookshelfCover()
{
    delete ui;
}
