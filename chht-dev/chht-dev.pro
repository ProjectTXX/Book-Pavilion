#-------------------------------------------------
#
# Project created by QtCreator 2024-07-15T09:55:53
#
#-------------------------------------------------
QT       +=serialport

QT       += core gui

QT      +=core gui sql
QT +=multimedia
QT  +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG+=c++11

TARGET = chht-dev
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    signup.cpp \
    smtp.cpp \
    success.cpp \
    window.cpp

HEADERS += \
        widget.h \
    signup.h \
    smtp.h \
    success.h \
    window.h

FORMS += \
        widget.ui \
    signup.ui \
    success.ui \
    window.ui

RESOURCES += \
    picture.qrc \
    picture.qrc

DISTFILES += \
    ../../../picture/2.jpg \
    ../../../picture/3.jpg \
    ../../../picture/4.jpg \
    ../../../picture/5.jpg \
    ../../../picture/7.jpg \
    D:/picture/9563fe5afcea4527baab2a527d322cde.png \
    D:/picture/d080692ca45c4677a618dc6fab1fa747.png \
    D:/picture/e0a07cd80e09495ea59e715ad48eee7a.png \
    D:/picture/e1adffab05134d57a63960da867f80c5.png \
    D:/picture/e494f5a5082948c3bdbf348e1703bcb6.png \
    D:/picture/e8fdcf8afd36452184c1c2e39ec178cf.png
