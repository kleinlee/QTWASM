QT += quick widgets
CONFIG += c++17
SOURCES += main.cpp \
    humanassets.cpp \
    mainwidget.cpp

wasm:QMAKE_LFLAGS += -s EXTRA_EXPORTED_RUNTIME_METHODS=[\"UTF16ToString\",\"stringToUTF16\",\"ccall\"]
#wasm:QMAKE_LFLAGS += -s EXPORTED_FUNCTIONS=[\"_malloc\",\"_free\"]

HEADERS += \
    humanassets.h \
    mainwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
