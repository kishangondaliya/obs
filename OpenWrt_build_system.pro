#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T16:55:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenWrt_build_system
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    feeds.cpp

HEADERS  += mainwindow.h \
    feeds.h

FORMS    += mainwindow.ui \
    feeds.ui
