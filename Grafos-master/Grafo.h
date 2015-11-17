#ifndef GRAFO_H
#define GRAFO_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QString>
#include <QColor>
#include <QMessageBox>
#include <QMainWindow>

#include <QPainter>

#include "Vertex.h"
#include "Edge.h"

#define INF  100000

class Graph : public QWidget {
    Q_OBJECT

public:
    Graph ( int n, QMainWindow *m, QWidget *pai=0 );


    void adicionarVertex ( QString, QPoint );
    bool adicionarEdge ( QString, QString, int, QColor cor=Qt::black );

    Edge    *getEdges();
    Vertex  **getVertex () ;
    Vertex  *getVertexAt ( int );
    int     getVertexCount();
    int     getVertexIndice ( QString  );
    QString getCaminho ( QString );
    QString carregarDoArquivo( QString );

    void pintar ();

    void resize ( int );
    void dispose ();
    ~Graph ( ) ;

signals:
    void update ( Graph * );

private:
    QMainWindow *main;
    Vertex      **vertice;
    Edge        *arestas;

    int max;
    int quantidadeVertexs;
};



#endif // GRAFO_H
