/********************************************************************************
** Form generated from reading UI file 'dialogbookself.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBOOKSELF_H
#define UI_DIALOGBOOKSELF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DialogBookself
{
public:

    void setupUi(QDialog *DialogBookself)
    {
        if (DialogBookself->objectName().isEmpty())
            DialogBookself->setObjectName(QString::fromUtf8("DialogBookself"));
        DialogBookself->resize(641, 378);

        retranslateUi(DialogBookself);

        QMetaObject::connectSlotsByName(DialogBookself);
    } // setupUi

    void retranslateUi(QDialog *DialogBookself)
    {
        DialogBookself->setWindowTitle(QApplication::translate("DialogBookself", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogBookself: public Ui_DialogBookself {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBOOKSELF_H
