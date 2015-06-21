#-------------------------------------------------
#
# Project created by QtCreator 2015-06-01T19:35:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BodyPartSpilt
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    SettingDialog.cpp \
    Model/BasicHelper.cpp \
    Model/SpiltRectangleModel.cpp \
    View/ImageLabel.cpp

HEADERS  += MainWindow.h \
    SettingDialog.h \
    Model/BasicHelper.h \
    Model/SpiltRectangleModel.h \
    View/ImageLabel.h

FORMS    += MainWindow.ui \
    SettingDialog.ui

INCLUDEPATH +=  /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so.2.4.9 \
        /usr/local/lib/libopencv_core.so.2.4.9    \
        /usr/local/lib/libopencv_imgproc.so.2.4.9 \
        /usr/local/lib/libopencv_contrib.so.2.4.9 \
        /usr/local/lib/libopencv_video.so.2.4.9   \
        /usr/local/lib/libopencv_ml.so.2.4.9
