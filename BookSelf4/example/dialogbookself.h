#ifndef DIALOGBOOKSELF_H
#define DIALOGBOOKSELF_H

#include<mainwindow.h>
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
class MainWindow;
class DialogBookcontent;
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
    MainWindow *mainwindow;
    DialogBookcontent *content;
    QPushButton *btn;
    QPushButton *btn2;
    QHBoxLayout *layout;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *vlayout;
    QComboBox *combox;
    QScrollArea *scrollArea;
    QWidget *widget;
    QLabel *lab;


};

#endif // DIALOGBOOKSELF_H
