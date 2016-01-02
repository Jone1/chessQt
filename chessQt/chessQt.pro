#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T11:30:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chessQt
TEMPLATE = app


SOURCES += main.cpp\
        views/mainwindow.cpp \
    views/filed.cpp \
    pieces/piece.cpp \
    pieces/pawn.cpp \
    pieces/rook.cpp \
    pieces/bishop.cpp \
    pieces/queen.cpp \
    pieces/king.cpp \
    pieces/knight.cpp \
    pieces/whitepawn.cpp \
    pieces/blackpawn.cpp

HEADERS  += views/mainwindow.h \
    views/filed.h \
    pieces/piece.h \
    pieces/pawn.h \
    pieces/rook.h \
    pieces/bishop.h \
    pieces/queen.h \
    pieces/king.h \
    pieces/knight.h \
    pieces/whitepawn.h \
    pieces/blackpawn.h

FORMS    += ui/mainwindow.ui

DISTFILES +=

QMAKE_CXXFLAGS += -std=c++11
