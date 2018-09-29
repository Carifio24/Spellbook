#-------------------------------------------------
#
# Project created by QtCreator 2018-09-14T23:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spellbook
TEMPLATE = app


SOURCES += main.cpp\
        spellbook.cpp \
    Parse.cpp \
    Filter.cpp \
    Sort.cpp \
    Parse.tpp \
    Sort.tpp \
    jstring.cpp \
    jsoncpp/jsoncpp.cpp

HEADERS  += spellbook.h \
    Sort.h \
    Parse.h \
    Filter.h \
    Classes.h \
    ui_spellbook.h \
    jsoncpp/json/json.h \
    jsoncpp/json/json-forwards.h \
    jstring.h

FORMS    += spellbook.ui

CONFIG    += c++11

DISTFILES += \
    Spells.json
