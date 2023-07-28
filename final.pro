QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    win0.cpp \
    win1.cpp \
    win2.cpp \
    win3.cpp \
    win4.cpp \
    win5.cpp \
    win6.cpp \
    win7.cpp


HEADERS += \
    mainwindow.h \
    win0.h \
    win1.h \
    win2.h \
    win3.h \
    win4.h \
    win5.h \
    win6.h \
    win7.h


FORMS += \
    mainwindow.ui \
    win0.ui \
    win1.ui \
    win2.ui \
    win3.ui \
    win4.ui \
    win5.ui \
    win6.ui \
    win7.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Next.qml \
    NextForm.ui.qml

RESOURCES += \
    images.qrc
