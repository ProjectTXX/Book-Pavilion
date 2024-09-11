/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QPushButton *Login;
    QLabel *label_2;
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
    QPushButton *Send;

    void setupUi(QWidget *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName(QString::fromUtf8("Signup"));
        Signup->resize(690, 450);
        Login = new QPushButton(Signup);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setGeometry(QRect(210, 310, 51, 21));
        QFont font;
        font.setPointSize(11);
        Login->setFont(font);
        label_2 = new QLabel(Signup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, -10, 711, 461));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bodoni MT Condensed"));
        label_2->setFont(font1);
        label_2->setPixmap(QPixmap(QString::fromUtf8("D:/ppt\345\233\276\347\211\207/qtpixmas[p/seagull-4795739_1280.jpg")));
        label_4 = new QLabel(Signup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 120, 261, 181));
        label_4->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"color: QColor(0x00,0xff,0x00,0x00);"));
        label_3 = new QLabel(Signup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 80, 221, 31));
        QFont font2;
        font2.setPointSize(21);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        Password = new QLineEdit(Signup);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(300, 180, 113, 20));
        Password->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"background-color: rgba(255, 255, 255, 0.3)"));
        Enroll = new QPushButton(Signup);
        Enroll->setObjectName(QString::fromUtf8("Enroll"));
        Enroll->setGeometry(QRect(300, 330, 81, 21));
        Enroll->setFont(font);
        Enroll->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */"));
        return_2 = new QPushButton(Signup);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(300, 370, 81, 21));
        return_2->setFont(font);
        return_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */"));
        Person = new QLineEdit(Signup);
        Person->setObjectName(QString::fromUtf8("Person"));
        Person->setGeometry(QRect(300, 140, 113, 20));
        Person->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"background-color: rgba(255, 255, 255, 0.3)"));
        label = new QLabel(Signup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 140, 31, 21));
        QFont font3;
        font3.setPointSize(14);
        label->setFont(font3);
        label_7 = new QLabel(Signup);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(260, 180, 31, 21));
        label_7->setFont(font3);
        Mail = new QLineEdit(Signup);
        Mail->setObjectName(QString::fromUtf8("Mail"));
        Mail->setGeometry(QRect(300, 220, 113, 20));
        Mail->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"background-color: rgba(255, 255, 255, 0.3)"));
        Mailverify = new QLineEdit(Signup);
        Mailverify->setObjectName(QString::fromUtf8("Mailverify"));
        Mailverify->setGeometry(QRect(280, 260, 61, 20));
        Mailverify->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"background-color: rgba(255, 255, 255, 0.3)"));
        checkBox = new QCheckBox(Signup);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(420, 180, 61, 21));
        checkBox->setFont(font);
        checkBox->setStyleSheet(QString::fromUtf8("\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
""));
        label_8 = new QLabel(Signup);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 219, 31, 21));
        label_8->setFont(font3);
        Send = new QPushButton(Signup);
        Send->setObjectName(QString::fromUtf8("Send"));
        Send->setGeometry(QRect(350, 260, 71, 21));
        Send->setFont(font);
        Send->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */"));

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QWidget *Signup)
    {
        Signup->setWindowTitle(QApplication::translate("Signup", "Form", nullptr));
        Login->setText(QApplication::translate("Signup", "\347\231\273\345\275\225", nullptr));
        label_2->setText(QString());
        label_4->setText(QString());
        label_3->setText(QApplication::translate("Signup", "Book Pavilion", nullptr));
        Password->setInputMask(QString());
        Password->setText(QString());
        Password->setPlaceholderText(QString());
        Enroll->setText(QApplication::translate("Signup", "\346\263\250\345\206\214", nullptr));
        return_2->setText(QApplication::translate("Signup", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        Person->setInputMask(QString());
        Person->setText(QString());
        label->setText(QApplication::translate("Signup", "\350\264\246\346\210\267", nullptr));
        label_7->setText(QApplication::translate("Signup", "\345\257\206\347\240\201", nullptr));
        checkBox->setText(QApplication::translate("Signup", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        label_8->setText(QApplication::translate("Signup", "\351\202\256\347\256\261", nullptr));
        Send->setText(QApplication::translate("Signup", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
