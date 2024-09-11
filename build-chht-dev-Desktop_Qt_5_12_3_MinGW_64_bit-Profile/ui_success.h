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
    QLabel *label;
    QPushButton *btnadd;
    QSlider *vVolume;
    QListWidget *listWidget;
    QSlider *hprogress;
    QPushButton *btnNext;
    QPushButton *btnPre;
    QLabel *lblmusictime;
    QPushButton *btnvolume;
    QLabel *lblplaytime;
    QPushButton *playinandpasue;

    void setupUi(QWidget *Success)
    {
        if (Success->objectName().isEmpty())
            Success->setObjectName(QString::fromUtf8("Success"));
        Success->resize(720, 378);
        Success->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Success);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 721, 381));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/picture/2.jpg);"));
        btnadd = new QPushButton(Success);
        btnadd->setObjectName(QString::fromUtf8("btnadd"));
        btnadd->setGeometry(QRect(170, 170, 21, 21));
        btnadd->setStyleSheet(QString::fromUtf8("border-image: url(:/D:/picture/e1adffab05134d57a63960da867f80c5.png);"));
        vVolume = new QSlider(Success);
        vVolume->setObjectName(QString::fromUtf8("vVolume"));
        vVolume->setGeometry(QRect(590, 60, 16, 160));
        vVolume->setOrientation(Qt::Vertical);
        listWidget = new QListWidget(Success);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(190, 170, 271, 181));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        hprogress = new QSlider(Success);
        hprogress->setObjectName(QString::fromUtf8("hprogress"));
        hprogress->setGeometry(QRect(250, 140, 160, 16));
        hprogress->setOrientation(Qt::Horizontal);
        btnNext = new QPushButton(Success);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(430, 60, 51, 41));
        btnNext->setStyleSheet(QString::fromUtf8("border-image: url(:/D:/picture/9563fe5afcea4527baab2a527d322cde.png);"));
        btnPre = new QPushButton(Success);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));
        btnPre->setGeometry(QRect(210, 60, 51, 41));
        btnPre->setStyleSheet(QString::fromUtf8("border-image: url(:/D:/picture/d080692ca45c4677a618dc6fab1fa747.png);"));
        lblmusictime = new QLabel(Success);
        lblmusictime->setObjectName(QString::fromUtf8("lblmusictime"));
        lblmusictime->setGeometry(QRect(200, 140, 41, 16));
        btnvolume = new QPushButton(Success);
        btnvolume->setObjectName(QString::fromUtf8("btnvolume"));
        btnvolume->setGeometry(QRect(550, 60, 41, 41));
        btnvolume->setStyleSheet(QString::fromUtf8("border-image: url(:/D:/picture/e494f5a5082948c3bdbf348e1703bcb6.png);"));
        lblplaytime = new QLabel(Success);
        lblplaytime->setObjectName(QString::fromUtf8("lblplaytime"));
        lblplaytime->setGeometry(QRect(410, 140, 41, 16));
        playinandpasue = new QPushButton(Success);
        playinandpasue->setObjectName(QString::fromUtf8("playinandpasue"));
        playinandpasue->setGeometry(QRect(330, 60, 51, 41));

        retranslateUi(Success);

        QMetaObject::connectSlotsByName(Success);
    } // setupUi

    void retranslateUi(QWidget *Success)
    {
        Success->setWindowTitle(QApplication::translate("Success", "Form", nullptr));
        label->setText(QString());
        btnadd->setText(QString());
        btnNext->setText(QString());
        btnPre->setText(QString());
        lblmusictime->setText(QString());
        btnvolume->setText(QString());
        lblplaytime->setText(QString());
        playinandpasue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Success: public Ui_Success {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESS_H
