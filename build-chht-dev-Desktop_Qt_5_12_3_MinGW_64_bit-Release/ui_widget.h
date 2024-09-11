/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Person;
    QLineEdit *Password;
    QCheckBox *show;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *Login;
    QPushButton *exit;
    QPushButton *Enroll;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(701, 396);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-50, -10, 751, 511));
        QFont font;
        font.setFamily(QString::fromUtf8("Bodoni MT Condensed"));
        label_2->setFont(font);
        label_2->setPixmap(QPixmap(QString::fromUtf8("D:/ppt\345\233\276\347\211\207/qtpixmas[p/seagull-3802232_1280.jpg")));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 40, 201, 31));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 90, 381, 181));
        label_4->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"color: QColor(0x00,0xff,0x00,0x00);"));
        Person = new QLineEdit(Widget);
        Person->setObjectName(QString::fromUtf8("Person"));
        Person->setGeometry(QRect(270, 130, 113, 20));
        Person->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"background-color: rgba(255, 255, 255, 0.3)\n"
""));
        Person->setCursorPosition(0);
        Password = new QLineEdit(Widget);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(270, 200, 113, 20));
        Password->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"background-color: rgba(255, 255, 255, 0.3)"));
        show = new QCheckBox(Widget);
        show->setObjectName(QString::fromUtf8("show"));
        show->setGeometry(QRect(410, 190, 71, 41));
        QFont font2;
        font2.setPointSize(13);
        show->setFont(font2);
        show->setStyleSheet(QString::fromUtf8("\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 130, 71, 20));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setWeight(50);
        label_5->setFont(font3);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(190, 200, 61, 20));
        label_6->setFont(font3);
        Login = new QPushButton(Widget);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setGeometry(QRect(130, 300, 61, 21));
        Login->setFont(font2);
        Login->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */"));
        exit = new QPushButton(Widget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(450, 300, 61, 21));
        exit->setFont(font2);
        exit->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */"));
        Enroll = new QPushButton(Widget);
        Enroll->setObjectName(QString::fromUtf8("Enroll"));
        Enroll->setGeometry(QRect(290, 300, 61, 21));
        Enroll->setFont(font2);
        Enroll->setStyleSheet(QString::fromUtf8("border: 1px solid gray; /* \350\276\271\346\241\206 */\n"
"	border-radius: 4px;     /* \350\276\271\346\241\206\345\234\206\350\247\222 */"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Widget", "Book Pavilion", nullptr));
        label_4->setText(QString());
        Person->setInputMask(QString());
        Person->setText(QString());
        Password->setInputMask(QString());
        Password->setText(QString());
        Password->setPlaceholderText(QString());
        show->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        label_5->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", nullptr));
        Login->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        exit->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        Enroll->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
