QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ClassPrintOperator.cpp \
        PrintOperatorUnit.cpp \
        classeslang.cpp \
        classesmethod.cpp \
        classunit.cpp \
        fabric.cpp \
        main.cpp \
        methodunit.cpp \
        unit.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ClassPrintOperator.h \
    PrintOperatorUnit.h \
    classeslang.h \
    classesmethod.h \
    classunit.h \
    fabric.h \
    methodunit.h \
    unit.h
