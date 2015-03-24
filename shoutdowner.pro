#-------------------------------------------------
#
# Project created by QtCreator 2015-03-09T21:22:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = shoutdowner
TEMPLATE = app
INCLUDEPATH += $(BOOST_ROOT)
LIBS += "-L%BOOST_ROOT%/stage/lib"

SOURCES += main.cpp\
        mainwindow.cpp \
    ccounter.cpp

HEADERS  += mainwindow.h \
    ccounter.h

FORMS    += mainwindow.ui \
    ccounter.ui
