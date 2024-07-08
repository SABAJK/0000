QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Plant.cpp \
    Score.cpp \
    Sun.cpp \
    Zombie.cpp \
    client.cpp \
    game.cpp \
    logindialog.cpp \
    loginmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    resetpassworddialog.cpp \
    server.cpp \
    signup.cpp \
    signupdialog.cpp

HEADERS += \
    Bullet.h \
    Plant.h \
    Score.h \
    Sun.h \
    Zombie.h \
    client.h \
    client.h \
    game.h \
    logindialog.h \
    loginmanager.h \
    mainwindow.h \
    resetpassworddialog.h \
    server.h \
    server.h \
    signup.h \
    signupdialog.h

FORMS += \
    game.ui \
    logindialog.ui \
    mainwindow.ui \
    resetpassworddialog.ui \
    signupdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    Bucket head zombie.jpg \
    astronaut zombie.jpg \
    boomerang.jpg \
    field.jpg \
    jalapino.jpg \
    leaf hair zombie.jpg \
    pea shooter.jpg \
    plum mine.jpg \
    purple hair zombie.jpg \
    regular zombie.jpg \
    tall zombie.jpg \
    two_peashooter.jpg \
    walnut.jpg
