#-------------------------------------------------
#
# Project created by QtCreator 2013-08-16T11:16:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = adheScan
TEMPLATE = app

include(qtsingleapplication/qtsingleapplication.pri)

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QT += sql
QT += mobility
CONFIG += mobility

MOBILITY = multimedia


#sudo apt-get install qtmultimedia5-dev
#sudo apt-get install libpulse-dev
#sudo apt-get install gstreamer1.0-plugins-ugly gstreamer1.0-plugins-bad gstreamer1.0-tools gst123

RESOURCES += \
    ressources.qrc


