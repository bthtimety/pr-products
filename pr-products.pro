QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    concreteproducts.cpp \
    delegates.cpp \
    dialogdelete.cpp \
    dialogedit.cpp \
    dialogredaction.cpp \
    main.cpp \
    mainwindow.cpp \
    sorting.cpp \
    tablemodel.cpp

HEADERS += \
    concreteproducts.h \
    delegates.h \
    dialogdelete.h \
    dialogedit.h \
    dialogredaction.h \
    mainwindow.h \
    tablemodel.h

FORMS += \
    dialogdelete.ui \
    dialogedit.ui \
    dialogredaction.ui \
    mainwindow.ui

TRANSLATIONS += tr/pr-products_ru_RU.ts \
                tr/pr-products_en_US.ts \
                tr/pr-products_ko_KR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
