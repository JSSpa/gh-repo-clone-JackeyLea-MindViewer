QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

#临时编译文件路径
OBJECTS_DIR = .obj
RCC_DIR = .rcc
UI_DIR = .ui
MOC_DIR = .moc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#Windows平台配置
#将qwt库文件和头文件路径添加到此处
win32:{
    INCLUDEPATH += $$PWD/qwt/include
    LIBS += -L$$PWD/qwt/lib -lqwt
}

#Linux下头文件以及库文件
unix:{
    INCLUDEPATH += /usr/include/qwt

    LIBS += -lqwt-qt5
}

SOURCES += \
    curves.cpp \
    curvescommon.cpp \
    generator.cpp \
    main.cpp \
    mainwindow.cpp \
    retriver.cpp

HEADERS += \
    common.h \
    curves.h \
    curvescommon.h \
    generator.h \
    mainwindow.h \
    retriver.h

FORMS += \
    curves.ui \
    curvescommon.ui \
    mainwindow.ui \
    retriver.ui

RESOURCES += \
    resources.qrc
