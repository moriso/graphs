#include "Bfs.h"

Bfs::Bfs( Graph *grafo, int verticeInicial, QObject *parent) : QThread(parent) {
    this->grafo = grafo;
    this->verticeInicial = verticeInicial;
}

Bfs::~Bfs () {
    delete grafo;
}

void Bfs::run () {
    metodoBFS();
}

void Bfs:: metodoBFS() {
    QList<Vertex *> lista;
    Vertex *verticeAtual, *vertice;
    Edge *aresta;
    Vertex **ListaVertexs = grafo->getVertex();
    int quantidade = grafo->getVertexCount();
    int i;
    for ( i = 0; i < quantidade; i++ ) {
        ListaVertexs[i]->setFather(NULL);
        ListaVertexs[i]->setColor(Qt::white);
        ListaVertexs[i]->setD(INF);
    }
    ListaVertexs[this->verticeInicial]->setD(0);
    ListaVertexs[this->verticeInicial]->setColor(Qt::gray);
    emit update(grafo);
    sleep(1);

    lista.append(ListaVertexs[this->verticeInicial]);
    while (!lista.empty()) {
        vertice = lista.takeFirst();
        for ( aresta = vertice->getEdges(); aresta; aresta = aresta->getNext() ) {
            verticeAtual = ListaVertexs[aresta->getIdAdj()];
            if ( verticeAtual->getColor() == Qt::white ) {
                verticeAtual->setColor(Qt::gray);

                emit update(grafo);
                sleep(1);

                verticeAtual->setFather(vertice);
                verticeAtual->setD(vertice->getD() + 1 );
                lista.append(verticeAtual);
            }
        }
        vertice->setColor(Qt::black);
        emit update(grafo);
        sleep(1);
    }
}


