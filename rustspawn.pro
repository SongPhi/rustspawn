#-------------------------------------------------
#
# Project created by QtCreator 2014-10-12T11:13:00
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rustspawn
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    base/cliwrapper.cpp \
    rustspawn.cpp \
    tabs/editors/texteditortab.cpp

HEADERS  += mainwindow.h \
    base/cliwrapper.h \
    rustspawn.h \
    tabs/editors/texteditortab.h

FORMS    += mainwindow.ui

RESOURCES += \
    rustspawn.qrc

vendor.path = $$OUT_PWD
vendor.files = vendor

resources.path = $$OUT_PWD
resources.files = res

html.path = $$OUT_PWD
html.files = html

INSTALLS += \
    vendor \
    resources \
    html
