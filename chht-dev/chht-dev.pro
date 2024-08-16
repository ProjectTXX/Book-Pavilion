#-------------------------------------------------
#
<<<<<<<< HEAD:chht-dev/chht-dev.pro
# Project created by QtCreator 2024-07-15T09:55:53
#
#-------------------------------------------------
QT       +=serialport

QT       += core gui

QT      +=core gui sql

QT  +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG+=c++11

TARGET = chht-dev
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
========
# Project created by QtCreator 2024-07-24T16:16:00
#
#-------------------------------------------------

QT       += core gui
QT+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = example
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
>>>>>>>> 5c58ef6c57187272a2236e20dea890db48e3a54c:Bookself3/example/example.pro
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

<<<<<<<< HEAD:chht-dev/chht-dev.pro

SOURCES += \
        main.cpp \
        widget.cpp \
    signup.cpp \
    smtp.cpp

HEADERS += \
        widget.h \
    signup.h \
    smtp.h

FORMS += \
        widget.ui \
    signup.ui

RESOURCES += \
    picture.qrc
========
CONFIG += c++11

SOURCES += \
        dialogbookcontent.cpp \
        dialogbookself.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        dialogbookcontent.h \
        dialogbookself.h \
        mainwindow.h

FORMS += \
        dialogbookcontent.ui \
        dialogbookself.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
>>>>>>>> 5c58ef6c57187272a2236e20dea890db48e3a54c:Bookself3/example/example.pro
