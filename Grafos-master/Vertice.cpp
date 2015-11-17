#include "Vertex.h"


Vertex::Vertex ( int indiceVertex, QString nome, QPoint ponto, QObject *pai ) : QObject(pai) {
    this->indiceVertex = indiceVertex;
    this->nome   = nome;
    this->peso   = 0;

    this->tempoEntrada = 0;
    this->tempoSaida = 0;
    this->ponto = ponto;
    this->cor  = Qt::white;
    this->pai = NULL;
    this->arestas  = NULL;
    this->set    = QString::number(indiceVertex);
}

QString Vertex::getSET () {
    return this->set;
}

int Vertex::getIndiceVertex() {
    return this->indiceVertex;
}

QString Vertex::getNome() {
    return this->nome;
}

QColor Vertex::getColor() {
    return this->cor;
}

Edge *Vertex::getEdges() {
    return this->arestas;
}

Vertex *Vertex::getPai() {
    return this->pai;
}

int Vertex::getD() {
    return this->peso;
}

int Vertex::getTempoEntrada() {
    return this->tempoEntrada;
}

int Vertex::getTempoSaida() {
    return this->tempoSaida;
}

QPoint Vertex::getPonto () {
    return this->ponto;
}

void Vertex::setSET ( QString newSet ) {
    this->set = newSet;
}

void Vertex::acrescentar( int indiceAdj, int peso, QColor cor )  {
    Edge::acrescentar( &arestas, indiceVertex, indiceAdj, peso, cor );
}

void Vertex::setFather( Vertex *pai ) {
    this->pai = pai;
}

void Vertex::setD ( int peso) {
    this->peso = peso;
}

void Vertex::setTi ( int tempoEntrada ) {
    this->tempoEntrada  = tempoEntrada;
}

void Vertex::setTo ( int tempoSaida ) {
    this->tempoSaida = tempoSaida;
}

void Vertex::setColor ( QColor cor ) {
    this->cor = cor;
}

Vertex *Vertex::clonar () {
    return new Vertex (indiceVertex, nome, ponto, this->parent() );
}

void Vertex::pintar ( QPainter &pintor ) {
    pintor.setBrush ( cor );
    pintor.setPen( (cor==Qt::white)? Qt::black : Qt::white );
    pintor.drawEllipse( ponto.x()-20,  ponto.y()-20, 40, 40 );

    QRect rect ( ponto.x()-4,  ponto.y()-8, ponto.x()+4,  ponto.y()+8 );
    pintor.drawText( rect, nome );


    // colocar peso?
    // setar o pai?
}

Vertex::~Vertex() {
    qDebug() << "Excluindo vertice " << nome;
    if (this->arestas!=NULL)
        delete this->arestas;
}

