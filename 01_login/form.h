#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    QString getAccount();
    QString getPassword();
    QString getPassword_();
    Ui::Form* getui();
private:
    Ui::Form *ui;
};

#endif // FORM_H
