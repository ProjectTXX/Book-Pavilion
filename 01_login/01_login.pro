#-------------------------------------------------
#
<<<<<<<< HEAD:BookSelf4/example/example.pro
# Project created by QtCreator 2024-07-24T16:16:00
#
#-------------------------------------------------

QT       += core gui
QT+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = example
========
# Project created by QtCreator 2024-07-22T19:48:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_login
>>>>>>>> 310094bd6647d1478f633434dad098a515ec5a55:01_login/01_login.pro
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

<<<<<<<< HEAD:BookSelf4/example/example.pro
CONFIG += c++11

SOURCES += \
        dialogbookcontent.cpp \
        dialogbookself.cpp \
========
CONFIG += c++17

SOURCES += \
        form.cpp \
>>>>>>>> 310094bd6647d1478f633434dad098a515ec5a55:01_login/01_login.pro
        main.cpp \
        mainwindow.cpp

HEADERS += \
<<<<<<<< HEAD:BookSelf4/example/example.pro
        dialogbookcontent.h \
        dialogbookself.h \
        mainwindow.h

FORMS += \
        dialogbookcontent.ui \
        dialogbookself.ui \
========
        form.h \
        mainwindow.h

FORMS += \
        form.ui \
>>>>>>>> 310094bd6647d1478f633434dad098a515ec5a55:01_login/01_login.pro
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
