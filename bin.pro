#-------------------------------------------------
#
# Project created by QtCreator 2015-04-19T20:39:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bin.cpp \
    package.cpp \
    bindrawer.cpp \
    packagedrawer.cpp

HEADERS  += mainwindow.h \
    bin.h \
    package.h \
    bindrawer.h \
    packagedrawer.h

FORMS    += mainwindow.ui
