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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogBookcontent
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QDialog *DialogBookcontent)
    {
        if (DialogBookcontent->objectName().isEmpty())
            DialogBookcontent->setObjectName(QString::fromUtf8("DialogBookcontent"));
        DialogBookcontent->resize(668, 397);
        gridLayout = new QGridLayout(DialogBookcontent);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(DialogBookcontent);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(DialogBookcontent);

        QMetaObject::connectSlotsByName(DialogBookcontent);
    } // setupUi

    void retranslateUi(QDialog *DialogBookcontent)
    {
        DialogBookcontent->setWindowTitle(QApplication::translate("DialogBookcontent", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogBookcontent: public Ui_DialogBookcontent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBOOKCONTENT_H
