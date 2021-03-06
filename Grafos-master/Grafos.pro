TEMPLATE = app

QT += qml quick widgets

SOURCES += edge.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    vertex.cpp \
    Dfs.cpp \
    Bfs.cpp \
    Prim.cpp \
    OrdenacaoTopologica.cpp \
    Dijkstra.cpp \
    Kruskal.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    graph.h \
    vertex.h \
    mainwindow.h \
    edge.h \
    Dfs.h \
    Bfs.h \
    OrdenacaoTopologica.h \
    Dijkstra.h \
    Prim.h \
    Kruskal.h

FORMS += \
    mainwindow.ui
