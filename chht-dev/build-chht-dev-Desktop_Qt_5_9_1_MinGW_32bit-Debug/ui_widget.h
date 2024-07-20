/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

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

class Ui_Widget
{
public:
    QLabel *label;
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
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(699, 455);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 691, 451));
        label->setPixmap(QPixmap(QString::fromUtf8("D:/ppt\345\233\276\347\211\207/qtpixmas[p/166191-imac_gradient_orange-x750.jpg")));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 100, 341, 231));
        QFont font;
        font.setFamily(QStringLiteral("Bodoni MT Condensed"));
        label_2->setFont(font);
        label_2->setPixmap(QPixmap(QString::fromUtf8("D:/ppt\345\233\276\347\211\207/qtpixmas[p/175519-imac-zong_se-fen_hong_se-pin_hong_se-he_yin_ying_de_se_cai-x750.jpg")));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 120, 111, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 160, 211, 101));
        label_4->setPixmap(QPixmap(QString::fromUtf8("D:/ppt\345\233\276\347\211\207/qtpixmas[p/166191-imac_gradient_orange-x750.jpg")));
        Person = new QLineEdit(Widget);
        Person->setObjectName(QStringLiteral("Person"));
        Person->setGeometry(QRect(290, 170, 113, 20));
        Password = new QLineEdit(Widget);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(290, 210, 113, 20));
        show = new QCheckBox(Widget);
        show->setObjectName(QStringLiteral("show"));
        show->setGeometry(QRect(360, 230, 61, 41));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 170, 41, 20));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        label_5->setFont(font2);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 210, 31, 20));
        label_6->setFont(font2);
        Login = new QPushButton(Widget);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(200, 290, 51, 21));
        exit = new QPushButton(Widget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(400, 290, 51, 21));
        Enroll = new QPushButton(Widget);
        Enroll->setObjectName(QStringLiteral("Enroll"));
        Enroll->setGeometry(QRect(300, 290, 51, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Widget", "Book Pavilion", Q_NULLPTR));
        label_4->setText(QString());
        Person->setInputMask(QString());
        Person->setText(QString());
        Password->setInputMask(QString());
        Password->setText(QString());
        Password->setPlaceholderText(QString());
        show->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\345\257\206\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        Login->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
        exit->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
        Enroll->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
