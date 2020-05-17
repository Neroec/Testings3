TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0
QMAKE_CXXFLAGS += -std=c++11

SUBDIRS = app tests

CONFIG += ordered
