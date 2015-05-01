#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T09:44:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProfitCalculation
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    ProfiltCalculation.cpp

HEADERS  += mainwindow.h \
    ProfiltCalculation.h

FORMS    += mainwindow.ui

TRANSLATIONS = app_zh_CN.ts 

RESOURCES += \
    profiltcalculation.qrc

OTHER_FILES= app_zh_CN.ts \
    README.md
