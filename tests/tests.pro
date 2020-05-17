include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS += \
    ../app/GameManager.h \
    XCollision.h \
    YCollision.h \
    ObjectsCollision.h \
    CoinsCollision.h \
    MarioStatus.h \
    ObjectsStorage.h

SOURCES += \
    main.cpp \
    ../app/XCollision.cpp \
    ../app/YCollision.cpp \
    ../app/ObjectsCollision.cpp \
    ../app/CoinsCollision.cpp \
    ../app/MarioStatus.cpp \
    ../app/ObjectsStorage.cpp

INCLUDEPATH += \
    ../app
