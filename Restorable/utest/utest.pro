TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    RrestorableUTest.cpp

LIBS += -lgmock_main -lgtest -lgmock -lpthread
