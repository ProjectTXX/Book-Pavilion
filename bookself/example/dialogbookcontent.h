#ifndef DIALOGBOOKCONTENT_H
#define DIALOGBOOKCONTENT_H

#include <QDialog>
#include<QtSql>
#include<QLabel>
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

private:
    Ui::DialogBookcontent *ui;
};

#endif // DIALOGBOOKCONTENT_H
