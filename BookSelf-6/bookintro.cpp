#include "bookintro.h"
#include "ui_bookintro.h"

Bookintro::Bookintro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bookintro)
{
    ui->setupUi(this);
}

Bookintro::~Bookintro()
{
    delete ui;
}

Ui::Bookintro *Bookintro::geiUi()
{
    return ui;
}
