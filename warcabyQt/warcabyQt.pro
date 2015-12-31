#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T11:30:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = warcabyQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filed.cpp \
    piece.cpp \
    pawn.cpp \
    rook.cpp \
    bishop.cpp \
    queen.cpp \
    king.cpp \
    knight.cpp

HEADERS  += mainwindow.h \
    filed.h \
    piece.h \
    pawn.h \
    rook.h \
    bishop.h \
    queen.h \
    king.h \
    knight.h

FORMS    += mainwindow.ui

DISTFILES +=

QMAKE_CXXFLAGS += -std=c++11
