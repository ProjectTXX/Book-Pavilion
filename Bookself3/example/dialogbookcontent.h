#ifndef DIALOGBOOKCONTENT_H
#define DIALOGBOOKCONTENT_H

#include <QDialog>
#include<QtSql>
#include<QLabel>
#include<QFont>
#include<QFontDialog>
#include<QPalette>
#include<QColorDialog>
#include<QColor>
namespace Ui {
class DialogBookcontent;
}

class DialogBookcontent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBookcontent(QWidget *parent = nullptr);
    ~DialogBookcontent();
    Ui::DialogBookcontent* getui();
private slots:
    void on_btnFont_clicked();

    void on_btnColor_clicked();

    void on_btnNight_clicked();

    void on_btnDay_clicked();

private:
    Ui::DialogBookcontent *ui;
};

#endif // DIALOGBOOKCONTENT_H
