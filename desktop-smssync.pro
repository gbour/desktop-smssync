TEMPLATE = app

CONFIG += \
    c++11

QT += qml quick widgets
DEFINES += QMQTT_LIBRARY

HEADERS += \
    src/network.h \
    src/contact.h \
    src/message.h

SOURCES += \
    src/main.cpp \
    src/systray.cpp \
    src/network.cpp \
    src/contact.cpp \
    src/message.cpp

RESOURCES += qml.qrc

OTHER_FILES = \
    desktop-smssync.conf

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
include(src/qmqtt/qmqtt.pri)
INCLUDEPATH += $$PWD/src/qmqtt

HEADERS += \
    src/systray.h

DISTFILES += \
    desktop-smssync.conf

