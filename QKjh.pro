QT += core
QT -= gui
QT += network
QT += sql

CONFIG += c++11

TARGET = QKjh
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    network/netnumber.cpp

DISTFILES += \
    .gitattributes \
    .gitignore

HEADERS += \
    network/netnumber.h
