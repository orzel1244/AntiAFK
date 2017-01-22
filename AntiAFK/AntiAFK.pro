TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CBot/release/ -lCBot
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CBot/release/ -lCBot

INCLUDEPATH += $$PWD/../CBot/release
DEPENDPATH += $$PWD/../CBot/release
