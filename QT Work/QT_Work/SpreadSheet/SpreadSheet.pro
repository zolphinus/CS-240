#-------------------------------------------------
#
# Project created by QtCreator 2014-05-13T14:33:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpreadSheet
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    Find/finddialog.cpp \
    spreadsheet.cpp

HEADERS  += mainwindow.h \
    Find/finddialog.h \
    spreadsheet.h

FORMS    += mainwindow.ui \
    GoToCell/gotocelldialog.ui \
    Sort/sortdialog.ui

RESOURCES = spreadsheet.qrc
