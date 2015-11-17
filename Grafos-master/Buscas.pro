TEMPLATE = app

QT += qml quick widgets

SOURCES += Edge.cpp \
    Graph.cpp \
    main.cpp \
    interface.cpp \
    Vertex.cpp \
    Dfs.cpp \
    Bfs.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Graph.h \
    Vertex.h \
    interface.h \
    Edge.h \
    Dfs.h \
    Bfs.h


FORMS += \
    interface.ui
