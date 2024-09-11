/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(664, 344);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        Window->setFont(font);
        Window->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 681, 351));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/7.jpg);"));
        label_2 = new QLabel(Window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 30, 191, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"color: QColor(0x00,0xff,0x00,0x00);"));
        label_3 = new QLabel(Window);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 140, 41, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"Forte\";\n"
"color: rgb(255, 255, 255);\n"
"font: 16pt \"Agency FB\";\n"
"border: 1px solid black;\n"
"border-radius: 4px;\n"
"color: QColor(0x00,0xff,0x00,0x00);"));
        pushButton = new QPushButton(Window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 80, 51, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/D:/picture/e8fdcf8afd36452184c1c2e39ec178cf.png);"));

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Window", "Book-Pavilion", nullptr));
        label_3->setText(QApplication::translate("Window", "Music", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
