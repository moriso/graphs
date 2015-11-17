#ifndef DFS_H
#define DFS_H

#define INFINITO 1000000
#include <QThread>
#include <QDebug>
#include <QString>
#include <QColor>
#include <QMainWindow>

#include "Graph.h"


#define INF  100000

class Dfs : public QThread {
    Q_OBJECT

public:
    Dfs ( Graph *grafo, int indice, QObject *parent=0 );

    Graph *getGraph();

    ~Dfs () ;

protected:
    void run();

signals:
    void update ( Graph * );

private:
    Graph *grafo;
    int tempo;
    int indice;
    void metodoDFS ();

    void visit (Vertex *);

    //void createNewGraph ( int );
};

#endif // DFS_H
