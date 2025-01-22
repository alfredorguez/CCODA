TEMPLATE = app

QT += core gui

CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/third_party/rapidcsv

SOURCES += \
        BinaryNode.cpp \
        decisiontree.cpp \
        testBinaryNode.cpp \
        testDecisionTree.cpp

HEADERS += \
    BinaryNode.h \
    decisiontree.h
