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
    feeds.cpp \
    fetch_source.cpp

HEADERS  += mainwindow.h \
    feeds.h \
    fetch_source.h

FORMS    += mainwindow.ui \
    feeds.ui \
    fetch_source.ui
