/********************************************************************************
** Form generated from reading UI file 'success.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESS_H
#define UI_SUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Success
{
public:
    QPushButton *btnPre;
    QPushButton *playinandpasue;
    QPushButton *btnNext;
    QSlider *hprogress;
    QSlider *vVolume;
    QPushButton *btnadd;
    QPushButton *btnvolume;
    QListWidget *listWidget;
    QLabel *lblplaytime;
    QLabel *lblmusictime;

    void setupUi(QWidget *Success)
    {
        if (Success->objectName().isEmpty())
            Success->setObjectName(QString::fromUtf8("Success"));
        Success->resize(847, 378);
        btnPre = new QPushButton(Success);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));
        btnPre->setGeometry(QRect(120, 60, 61, 41));
        playinandpasue = new QPushButton(Success);
        playinandpasue->setObjectName(QString::fromUtf8("playinandpasue"));
        playinandpasue->setGeometry(QRect(290, 60, 61, 41));
        btnNext = new QPushButton(Success);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(440, 60, 51, 41));
        hprogress = new QSlider(Success);
        hprogress->setObjectName(QString::fromUtf8("hprogress"));
        hprogress->setGeometry(QRect(240, 140, 160, 16));
        hprogress->setOrientation(Qt::Horizontal);
        vVolume = new QSlider(Success);
        vVolume->setObjectName(QString::fromUtf8("vVolume"));
        vVolume->setGeometry(QRect(580, 60, 16, 160));
        vVolume->setOrientation(Qt::Vertical);
        btnadd = new QPushButton(Success);
        btnadd->setObjectName(QString::fromUtf8("btnadd"));
        btnadd->setGeometry(QRect(80, 150, 61, 51));
        btnvolume = new QPushButton(Success);
        btnvolume->setObjectName(QString::fromUtf8("btnvolume"));
        btnvolume->setGeometry(QRect(450, 140, 80, 51));
        listWidget = new QListWidget(Success);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(200, 190, 256, 192));
        lblplaytime = new QLabel(Success);
        lblplaytime->setObjectName(QString::fromUtf8("lblplaytime"));
        lblplaytime->setGeometry(QRect(400, 140, 41, 9));
        lblmusictime = new QLabel(Success);
        lblmusictime->setObjectName(QString::fromUtf8("lblmusictime"));
        lblmusictime->setGeometry(QRect(190, 140, 41, 9));

        retranslateUi(Success);

        QMetaObject::connectSlotsByName(Success);
    } // setupUi

    void retranslateUi(QWidget *Success)
    {
        Success->setWindowTitle(QApplication::translate("Success", "Form", nullptr));
        btnPre->setText(QApplication::translate("Success", "\345\220\216\351\200\200", nullptr));
        playinandpasue->setText(QApplication::translate("Success", "\345\201\234\346\255\242", nullptr));
        btnNext->setText(QApplication::translate("Success", "\345\211\215\350\277\233", nullptr));
        btnadd->setText(QApplication::translate("Success", "ADD", nullptr));
        btnvolume->setText(QApplication::translate("Success", "\351\237\263\351\207\217", nullptr));
        lblplaytime->setText(QString());
        lblmusictime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Success: public Ui_Success {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESS_H
