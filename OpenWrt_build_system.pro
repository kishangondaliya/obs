#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T16:55:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenWrt_build_system
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/feeds.cpp \
    src/selectconfig.cpp \
    src/fetchsource.cpp \
    src/build.cpp \
    src/selectrouter.cpp

HEADERS  += include/mainwindow.h \
    include/feeds.h \
    include/selectconfig.h \
    include/fetchsource.h \
    include/build.h \
    include/selectrouter.h

FORMS    += ui/mainwindow.ui \
    ui/feeds.ui \
    ui/selectconfig.ui \
    ui/fetchsource.ui \
    ui/build.ui \
    ui/selectrouter.ui
