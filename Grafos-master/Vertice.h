#ifndef VERTICE_H
#define VERTICE_H

#include <QObject>
#include <QDebug>
#include <QColor>
#include <QPainter>

#include "Edge.h"

class Vertex : public QObject {
    Q_OBJECT

public:
    Vertex ( int, QString, QPoint, QObject *parent=0 );
     ~Vertex();

    QString getSET ();
    int     getIndiceVertex  ();
    QString getNome ();
    QColor  getColor();
    Edge   *getEdges ();
    Vertex  *getPai();
    int     getD ();
    int     getTempoEntrada ();
    int     getTempoSaida ();
    QPoint  getPonto ();
    //int     getY ();

    void setSET ( QString );
    void acrescentar ( int, int, QColor color );
    void setFather ( Vertex * );
    void setD ( int );
    void setTi ( int  );
    void setTo ( int  );
    void setColor ( QColor  ) ;

    Vertex *clonar ();
    void pintar ( QPainter & );

protected:
    QString nome;
    int indiceVertex;         // Index do vértice no vetor
    int peso;          // tempo de entrada | distância | peso
    int tempoEntrada; // tempo de entrada
    int tempoSaida;          // tempo de saida
    Vertex *pai; // pai do vértice
    QColor  cor;  // cor do vértice

    QString set;

    Edge   *arestas;

    QPoint ponto;
    int cordenadaX;  // coordenada para desenho
    int cordenadaY;  // coordenada para desenho
};

#endif // VERTICE_H
