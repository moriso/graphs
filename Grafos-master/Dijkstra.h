#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <QThread>
#include <QDebug>
#include <QString>
#include <QColor>
#include <QMainWindow>

#include "graph.h"


#define INF  100000

class Dijkstra : public QThread {
    Q_OBJECT

public:
    Dijkstra (Graph *g, int index , QMainWindow *qMain, QObject *parent=0 );

    Graph *getGraph();
    Vertex * popMenor();
    void pintar(Vertex **);
    ~Dijkstra () ;

protected:
    void run();

signals:
    void update ( Graph * );

private:
    int index;
    Graph *grafo,*f;
    QList <Vertex*> lista;
    void dijkstra ();
};

#endif // DIJKSTRA_H
