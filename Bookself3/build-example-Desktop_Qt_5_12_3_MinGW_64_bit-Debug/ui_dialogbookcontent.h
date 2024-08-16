/********************************************************************************
** Form generated from reading UI file 'dialogbookcontent.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBOOKCONTENT_H
#define UI_DIALOGBOOKCONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogBookcontent
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnFont;
    QPushButton *btnColor;
    QPushButton *btnDay;
    QPushButton *btnNight;
    QTextEdit *textEdit;

    void setupUi(QDialog *DialogBookcontent)
    {
        if (DialogBookcontent->objectName().isEmpty())
            DialogBookcontent->setObjectName(QString::fromUtf8("DialogBookcontent"));
        DialogBookcontent->resize(668, 397);
        gridLayout_2 = new QGridLayout(DialogBookcontent);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(DialogBookcontent);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnFont = new QPushButton(groupBox);
        btnFont->setObjectName(QString::fromUtf8("btnFont"));

        gridLayout->addWidget(btnFont, 0, 0, 1, 1);

        btnColor = new QPushButton(groupBox);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));

        gridLayout->addWidget(btnColor, 0, 1, 1, 1);

        btnDay = new QPushButton(groupBox);
        btnDay->setObjectName(QString::fromUtf8("btnDay"));

        gridLayout->addWidget(btnDay, 0, 2, 1, 1);

        btnNight = new QPushButton(groupBox);
        btnNight->setObjectName(QString::fromUtf8("btnNight"));

        gridLayout->addWidget(btnNight, 0, 3, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        textEdit = new QTextEdit(DialogBookcontent);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 1);


        retranslateUi(DialogBookcontent);

        QMetaObject::connectSlotsByName(DialogBookcontent);
    } // setupUi

    void retranslateUi(QDialog *DialogBookcontent)
    {
        DialogBookcontent->setWindowTitle(QApplication::translate("DialogBookcontent", "Dialog", nullptr));
        groupBox->setTitle(QString());
        btnFont->setText(QApplication::translate("DialogBookcontent", "\350\256\276\347\275\256\345\255\227\344\275\223", nullptr));
        btnColor->setText(QApplication::translate("DialogBookcontent", "\350\256\276\347\275\256\351\242\234\350\211\262", nullptr));
        btnDay->setText(QApplication::translate("DialogBookcontent", "\347\231\275\345\244\251\346\250\241\345\274\217", nullptr));
        btnNight->setText(QApplication::translate("DialogBookcontent", "\345\244\234\351\227\264\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogBookcontent: public Ui_DialogBookcontent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBOOKCONTENT_H
