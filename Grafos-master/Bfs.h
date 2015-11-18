#ifndef BFS_H
#define BFS_H


#include <QThread>
#include <QDebug>
#include <QString>
#include <QColor>
#include <QMainWindow>

#include "Graph.h"

#define INF  100000

class Bfs : public QThread {
    Q_OBJECT

public:
    Bfs ( Graph *grafo, int verticeOrigem, QObject *parent=0 );

    ~Bfs () ;

protected:
    void run();

signals:
    void update ( Graph * );

private:
    Graph *grafo;
    int verticeInicial;
    void metodoBFS ();

};

#endif // BFS_H
