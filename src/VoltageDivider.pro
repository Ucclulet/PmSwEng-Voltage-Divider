#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T12:35:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VoltageDivider
TEMPLATE = app

SOURCES += main.cpp\
    ESeriesTest.cpp \
    UserInputValidator.cpp \
    VoltageDivider.cpp \
    VoltageDividerWidget.cpp \
    EResistor.cpp \
    ESeries.cpp \
    ESeriesType.cpp

LIBS += -lgtest

HEADERS  += \
    UserInputValidator.h \
    VoltageDivider.h \
    VoltageDividerWidget.h \
    EResistor.h \
    ESeries.h \
    IESeries.h

#GCOV Settings
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LDFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

FORMS    += \
    voltagedividerwidget.ui

DISTFILES +=

RESOURCES += \
    ../images/images.qrc
