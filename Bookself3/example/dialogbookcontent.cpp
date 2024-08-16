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


void DialogBookcontent::on_btnFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Consolas",9), this,"设置显示字体");
    ui->textEdit->setFont(font);
}

void DialogBookcontent::on_btnColor_clicked()
{
    QPalette palette = ui->textEdit->palette();
    palette.setColor(QPalette::Text,QColorDialog::getColor());
    ui->textEdit->setPalette(palette);

}

void DialogBookcontent::on_btnNight_clicked()
{
    ui->textEdit->setStyleSheet("background-color: grey;");
    QPalette palette = ui->textEdit->palette();
    palette.setColor(QPalette::Text,Qt::white);
    ui->textEdit->setPalette(palette);
}

void DialogBookcontent::on_btnDay_clicked()
{
    ui->textEdit->setStyleSheet("background-color: white;");
}
