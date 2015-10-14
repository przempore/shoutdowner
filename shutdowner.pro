#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T13:11:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = shutdowner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ccounter.cpp

HEADERS  += mainwindow.h \
    ccounter.h

FORMS    += mainwindow.ui \
    ccounter.ui

win32 {
    INCLUDEPATH += C:/Biblioteki/boost_1_57_0
    LIBS += -LC:/Biblioteki/boost_1_57_0/lib
}
