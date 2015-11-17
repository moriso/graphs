#ifndef ARESTA_H
#define ARESTA_H

#include <QDebug>
#include <QPainter>
#include <QColor>

class Edge : public QObject {
    Q_OBJECT

public:
    Edge ( int , int, int, QColor, QObject *pai=0 );
    ~Edge();

    static Edge* clonar ( Edge * );
    static void  acrescentar ( Edge **, int, int, int, QColor cor );
    static Edge* removeMenor ( Edge **, Edge *m=0 );

    int    getD ();
    int    getIndice();
    int    getIdAdj();
    QColor getColor();
    Edge   *getNext();


    void setColor ( QColor );
    void pintar( QPoint ponto1, QPoint ponto2, QPainter & );

private:    
    int    indice;
    int    indiceAdj;
    int    peso;
    QColor cor;
    Edge   *proximo;
};

#endif // EDGE_H
