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
    selectconfig.cpp \
    fetchsource.cpp \
    build.cpp

HEADERS  += mainwindow.h \
    feeds.h \
    selectconfig.h \
    fetchsource.h \
    build.h

FORMS    += mainwindow.ui \
    feeds.ui \
    selectconfig.ui \
    fetchsource.ui \
    build.ui
