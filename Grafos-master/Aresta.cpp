#include "Edge.h"

Edge::Edge ( int indice, int indiceAdj, int peso, QColor cor, QObject *pai ) : QObject(pai) {
    this->indice    = indice;    // source of edges
    this->indiceAdj = indiceAdj; // adjacent of edges
    this->peso     = peso;

    this->proximo = NULL;
    this->cor = cor;
}

void Edge::setColor ( QColor valor ) {
    this->cor = valor;
}

void Edge::pintar(QPoint ponto1, QPoint ponto2, QPainter &pintor ) {
    pintor.setPen( cor );
    pintor.drawLine ( ponto1, ponto2 );

    int x = (ponto1.x()+ponto2.x())/2;
    int y = (ponto1.y()+ponto2.y())/2;
    QRect rect ( x-4,  y, x,  y );
    pintor.drawText ( rect, QString::number(peso) );
}

int Edge::getD()  {
    return this->peso;
}

int Edge::getIndice() {
    return this->indice;
}

int Edge::getIdAdj() {
    return this->indiceAdj;
}

QColor Edge::getColor () {
    return this->cor;
}

Edge *Edge::getNext() {
    return this->proximo;
}

void Edge::acrescentar( Edge **aresta, int indice, int indiceAdj, int peso, QColor cor ) {
    if (*aresta==NULL)
        *aresta = new Edge ( indice, indiceAdj, peso, cor );
    else
        acrescentar( &(*aresta)->proximo, indice, indiceAdj, peso, cor );
}

Edge* Edge::removeMenor( Edge **arestas, Edge *aresta ) {
    if (*arestas) {
        if (!aresta) aresta=*arestas;

        if ((*arestas)->getD() < aresta->getD())
            aresta = removeMenor( &(*arestas)->proximo,*arestas);
        else
            aresta = removeMenor( &(*arestas)->proximo,aresta);

        if (aresta==*arestas) {
            *arestas = aresta->getNext();
            aresta->proximo = NULL;
        }
    }
    return aresta;
}

Edge* Edge::clonar ( Edge *aresta ) {
    if (aresta) {
        Edge *arestaClone = new Edge(aresta->getIndice(), aresta->getIdAdj(),aresta->getD(), aresta->getColor() );
        arestaClone->proximo = clonar(aresta->proximo);
        return arestaClone;
    }
    return NULL;
}

Edge::~Edge() {
    qDebug() << "Excluindo aresta (" << indice <<","<<indiceAdj<<"," << peso << ")";
    if (this->proximo!=NULL)
        delete this->proximo;
}

