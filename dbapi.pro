QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    DBsource/DBIFilters.cpp \
    DBsource/DBTypes.cpp \
    #DBsource/DBTable.cpp \
    #DBsource/DBDatabase.cpp \
    #DBsource/DBAttribute.cpp \
    Features/Features.cpp


HEADERS += \
    DBsource/DBIFilters.hpp \
    DBsource/DBTypes.hpp \
    DBsource/DBTable.hpp \
    DBsource/DBDatabase.hpp \
    DBsource/DBAttribute.hpp \
    Features/Features.hpp \
    mainwindow.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
