#include "Dfs.h"

Dfs::Dfs( Graph *grafo, int indice, QObject *parent ) : QThread(parent) {
    this->grafo = grafo;
    this->indice = indice;
}

Dfs::~Dfs () {
    delete grafo;
}

void Dfs::run () {
    metodoDFS();
}

void Dfs:: metodoDFS() {
    Vertex **ListaVertex = grafo->getVertex();
    int quantidade = grafo->getVertexCount();
    for(int i = this->indice; i < quantidade; i++) {
        ListaVertex[i]->setFather(NULL);
        ListaVertex[i]->setTi(INF);
        ListaVertex[i]->setTo(INF);
        ListaVertex[i]->setColor(Qt::white);
    }
    tempo = 0;
    for(int i = 0; i < quantidade; i++) {
        if(ListaVertex[i]->getColor() == Qt::white) {
            visit(ListaVertex[i]);
        }
    }
}

void Dfs::visit(Vertex *vertice) {
    Edge *aresta; Vertex *verticeAtual;
    vertice->setColor(Qt::gray);
    emit update(grafo);
    sleep(1);
    vertice->setTi(++tempo);
    for(aresta = vertice->getEdges(); aresta; aresta = aresta->getNext()) {
        verticeAtual = grafo->getVertex()[aresta->getIdAdj()];
        if(verticeAtual->getColor() == Qt::white) {
            verticeAtual->setFather(vertice);
            visit(verticeAtual);
        }
    }
    vertice->setTo(++tempo);
    vertice->setColor(Qt::black);
    emit update(grafo);
    sleep(1);
}
