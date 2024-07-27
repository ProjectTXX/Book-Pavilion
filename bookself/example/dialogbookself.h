#ifndef DIALOGBOOKSELF_H
#define DIALOGBOOKSELF_H

#include <QDialog>
#include<QPushButton>
#include<QtSql>
#include<dialogbookcontent.h>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPlainTextEdit>
#include<QComboBox>
#include<QScrollArea>
#include<QWidget>
#include<ui_dialogbookcontent.h>
namespace Ui {
class DialogBookself;
}

class DialogBookself : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBookself(QWidget *parent = nullptr);
    ~DialogBookself();
private:
    Ui::DialogBookself *ui;
    DialogBookcontent *content;
    QPushButton *btn;
    QHBoxLayout *layout;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *vlayout;
    QComboBox *combox;
    QScrollArea *scrollArea;
    QWidget *widget;
    QLabel *lab;


};

#endif // DIALOGBOOKSELF_H
