TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    trackpoint.cpp \
    lap.cpp \
    course.cpp

HEADERS += \
    lap.hpp \
    trackpoint.hpp \
    course.hpp \
    BadTrackpoint.hpp

OTHER_FILES += \
    HomeSD_Modified.xml \
    HomeSD_Untouched.tcx

