/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QLabel *label_5;
    QPushButton *Login;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *Password;
    QPushButton *Enroll;
    QPushButton *return_2;
    QLineEdit *Person;
    QLabel *label;
    QLabel *label_7;
    QLineEdit *Mail;
    QLineEdit *Mailverify;
    QCheckBox *checkBox;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName(QStringLiteral("Signup"));
        Signup->resize(620, 448);
        label_5 = new QLabel(Signup);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 200, 41, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        label_5->setFont(font);
        Login = new QPushButton(Signup);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(210, 310, 51, 21));
        QFont font1;
        font1.setPointSize(11);
        Login->setFont(font1);
        label_2 = new QLabel(Signup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 70, 341, 311));
        QFont font2;
        font2.setFamily(QStringLiteral("Bodoni MT Condensed"));
        label_2->setFont(font2);
        label_2->setPixmap(QPixmap(QString::fromUtf8("D:/ppt\345\233\276\347\211\207/qtpixmas[p/175519-imac-zong_se-fen_hong_se-pin_hong_se-he_yin_ying_de_se_cai-x750.jpg")));
        label_6 = new QLabel(Signup);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 230, 31, 20));
        label_6->setFont(font);
        label_4 = new QLabel(Signup);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 130, 211, 161));
        label_4->setPixmap(QPixmap(QString::fromUtf8("D:/ppt\345\233\276\347\211\207/qtpixmas[p/166191-imac_gradient_orange-x750.jpg")));
        label_3 = new QLabel(Signup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 80, 111, 31));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        Password = new QLineEdit(Signup);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(300, 180, 113, 20));
        Enroll = new QPushButton(Signup);
        Enroll->setObjectName(QStringLiteral("Enroll"));
        Enroll->setGeometry(QRect(300, 310, 61, 21));
        Enroll->setFont(font1);
        return_2 = new QPushButton(Signup);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setGeometry(QRect(300, 340, 61, 21));
        return_2->setFont(font1);
        Person = new QLineEdit(Signup);
        Person->setObjectName(QStringLiteral("Person"));
        Person->setGeometry(QRect(300, 140, 113, 20));
        label = new QLabel(Signup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 140, 31, 21));
        QFont font4;
        font4.setPointSize(14);
        label->setFont(font4);
        label_7 = new QLabel(Signup);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 180, 31, 21));
        label_7->setFont(font4);
        Mail = new QLineEdit(Signup);
        Mail->setObjectName(QStringLiteral("Mail"));
        Mail->setGeometry(QRect(300, 220, 113, 20));
        Mailverify = new QLineEdit(Signup);
        Mailverify->setObjectName(QStringLiteral("Mailverify"));
        Mailverify->setGeometry(QRect(300, 260, 113, 20));
        checkBox = new QCheckBox(Signup);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(420, 180, 16, 21));
        label_8 = new QLabel(Signup);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(260, 219, 31, 21));
        label_8->setFont(font4);
        label_9 = new QLabel(Signup);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(250, 260, 41, 21));
        label_9->setFont(font4);

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QWidget *Signup)
    {
        Signup->setWindowTitle(QApplication::translate("Signup", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("Signup", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        Login->setText(QApplication::translate("Signup", "\347\231\273\345\275\225", Q_NULLPTR));
        label_2->setText(QString());
        label_6->setText(QApplication::translate("Signup", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QString());
        label_3->setText(QApplication::translate("Signup", "Book Pavilion", Q_NULLPTR));
        Password->setInputMask(QString());
        Password->setText(QString());
        Password->setPlaceholderText(QString());
        Enroll->setText(QApplication::translate("Signup", "\346\263\250\345\206\214", Q_NULLPTR));
        return_2->setText(QApplication::translate("Signup", "\350\277\224\345\233\236\347\231\273\345\275\225", Q_NULLPTR));
        Person->setInputMask(QString());
        Person->setText(QString());
        label->setText(QApplication::translate("Signup", "\350\264\246\346\210\267", Q_NULLPTR));
        label_7->setText(QApplication::translate("Signup", "\345\257\206\347\240\201", Q_NULLPTR));
        checkBox->setText(QString());
        label_8->setText(QApplication::translate("Signup", "\351\202\256\347\256\261", Q_NULLPTR));
        label_9->setText(QApplication::translate("Signup", "\351\252\214\350\257\201\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
