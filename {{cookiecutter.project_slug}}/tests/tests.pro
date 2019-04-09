QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

include(../3rdparty/catch/catch.pri)
include(../3rdparty/trompeloeil/trompeloeil.pri)

PROJECT_DIR = $$PWD/../app/src

PROJECT_SOURCES = \
    $$PROJECT_DIR/calculator.cpp

PROJECT_HEADERS = \
    $$PROJECT_DIR/calculator.h

INCLUDEPATH += $$PROJECT_DIR

SOURCES +=  \
    main.cpp \
    $$PROJECT_SOURCES \
    tst_calculator.cpp

HEADERS += \
    $$PROJECT_HEADERS
