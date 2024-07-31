#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = 0);
    ~Signup();

private slots:
    void on_Enroll_clicked();

    void on_return_2_clicked();

    void on_checkBox_clicked();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
