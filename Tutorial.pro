QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    dialog.cpp \
    enemy.cpp \
    gameover.cpp \
    main.cpp \
    player.cpp

HEADERS += \
    bullet.h \
    dialog.h \
    enemy.h \
    gameover.h \
    player.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    dialog.ui \
    gameover.ui

RESOURCES += \
    images.qrc
