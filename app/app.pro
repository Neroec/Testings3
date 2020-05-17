TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    XCollision.cpp \
    YCollision.cpp \
    ObjectsCollision.cpp \
    CoinsCollision.cpp \
    MarioStatus.cpp \
    ObjectsStorage.cpp

HEADERS += \
    GameManager.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
