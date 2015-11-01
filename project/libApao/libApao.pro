TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    APAO.cpp \
    quantity.cpp \
    operator.cpp \
    expressionnode.cpp

HEADERS += \
    APAO.h \
    quantity.h \
    operator.h \
    expressionnode.h

DISTFILES += \
    Introduction.md

