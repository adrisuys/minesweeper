#include(../defaults.pri)
TEMPLATE = app
QT += core gui
greaterThan(QT_MAJOR_VERSION,4): QT += widgets
CONFIG += console c++14
CONFIG -= app_bundle
#CONFIG -= qt

INCLUDEPATH += $$PWD/Application

SRC_DIR = $$PWD

QMAKE_CXXFLAGS += -pedantic-errors

SOURCES += main.cpp \
    board.cpp \
    case.cpp \
    controller.cpp \
    game.cpp \
    halloffame.cpp \
    score.cpp \
    top.cpp \
    guiscreen.cpp \
    square.cpp \
    guiboard.cpp

HEADERS += \
    board.h \
    case.h \
    controller.h \
    game.h \
    halloffame.h \
    score.h \
    structure.h \
    top.h \
    guiscreen.h \
    square.h \
    guiboard.h

FORMS += \
    guiscreen.ui

DISTFILES += \
    img_cases/1.png \
    img_cases/2.png \
    img_cases/3.png \
    img_cases/4.png \
    img_cases/5.png \
    img_cases/6.png \
    img_cases/7.png \
    img_cases/8.png \
    img_cases/bomb.png \
    img_cases/bombSet.png \
    img_cases/title.png \
    img_cases/veiled.png \
    img_cases/flag.png \
    img_cases/0.png \
    img_cases/help.png
