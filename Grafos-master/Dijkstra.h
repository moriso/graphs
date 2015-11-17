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
/*
#include <QThread>
#include <QList>
#include "grafo.h"
#include "vertice.h"



class Dijkstra : public QThread
{
    Q_OBJECT
    public:
        void setParameters(Graph * g, int initial, int final) {
            this->grafo = g;
            this->VertexInitial = initial;
            this->VertexFinal = final;
        }

        void run() {
            metodoDijkstra(VertexInitial);
        }
    private:
        int tempo;
        int VertexInitial;
        int VertexFinal;
        Graph *grafo;
        QList<Vertex *> lista;
    signals:
        void sinalDijkstra();

    public:
        void metodoDijkstra( int indexVertexInicial ) {
            qDebug() << "chegou metodoDijkstra";
            Vertex *verticeAtual, *vertice;
            Edge *aresta;
            Vertex **V = grafo->getVertex();

            for ( int i = 0; i < grafo->getVertexCount(); i++ ) {
                V[i]->setColor(Qt::white);
                V[i]->setFather(NULL);
                V[i]->setDistancia(INFINITO);
                qDebug() << "dentro do for";
            }

            V[indexVertexInicial]->setColor(Qt::gray);
            emit sinalDijkstra();
            sleep(1);
            qDebug() << "Pintou cinza";
            V[indexVertexInicial]->setDistancia(0);
            qDebug() << "Vai inserir Lista";
            lista.append(V[indexVertexInicial]);
            while (!lista.empty()) {
                vertice = popMenor();
                vertice->setColor(Qt::black);
                emit sinalDijkstra();
                sleep(1);
                qDebug() << "Pintou Preto";
                for ( aresta = vertice->getEdge(); aresta != NULL; aresta = aresta->getNext() ) {
                    verticeAtual = V[aresta->getIdV2()];
                    if ( ( vertice->getDistancia() + aresta->getW()) < ( verticeAtual->getDistancia() ) ) {
                        verticeAtual->setDistancia( vertice->getDistancia() + aresta->getW() );
                        verticeAtual->setFather(vertice);
                    }
                    if ( verticeAtual->getColor() == Qt::white ) {
                        verticeAtual->setColor(Qt::gray);
                        emit sinalDijkstra();
                        sleep(2);
                        qDebug() << "Pintou Cinza";
                        lista.append(verticeAtual);
                    }
                }
            }
        }

        Vertex* popMenor(){
            int menor = 0;
            for (int i= 0; i < lista.size(); i++ ) {
                if ( lista.at(i)->getDistancia() < lista.at(menor)->getDistancia() ) {
                    menor = i;
                }
            }
            qDebug() << "Menor: " << lista.at(menor)->getNome();
            return lista.takeAt(menor);
        }


};*/

#endif // DIJKSTRA_H
