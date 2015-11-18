#include "edge.h"

#define PERCENT1 0.9
#define PERCENT2 1.1

Edge::Edge ( int id, int idAdj, int w, QColor color, QObject *parent ) : QObject(parent) {
    this->id    = id;    // source of edges
    this->idAdj = idAdj; // adjacent of edges
    this->w     = w;

    this->next  = NULL;
    this->color = color;
}

void Edge::setColor ( QColor value ) {
    this->color = value;
}

void Edge::paint(QPoint p1, QPoint p2, QPainter &painter ) {
    int dx = p2.x()-p1.x();
    int dy = p2.y()-p1.y();
    int x = p1.x() + dx/2;
    int y = p1.y() + dy/2;
    int xl = p1.x() + dx/3;
    int yl = p1.y() + dy/3;

    painter.setPen( color );

    QPainterPath myPath;
    myPath.moveTo(p1);
    if (p1.x()<p2.x()) {
        if (p1.y()<p2.y())
            myPath.cubicTo ( p1, QPoint(x*PERCENT1,y), p2);
        else
            myPath.cubicTo ( p1, QPoint(x,y*PERCENT2), p2);
    } else
        if (p1.y()>p2.y())
            myPath.cubicTo ( p1, QPoint(x,y*PERCENT2), p2);
        else
            myPath.cubicTo ( p1, QPoint(x*PERCENT1,y), p2);

    painter.drawPath( myPath );
    painter.drawText (QRect(xl,yl,xl,yl), QString::number(w) );
}

int Edge::getW ()  {
    return this->w;
}

int Edge::getId() {
    return this->id;
}
int Edge::getIdAdj() {
    return this->idAdj;
}

QColor Edge::getColor ( ) {
    return this->color;
}

Edge *Edge::getNext() {
    return this->next;
}

void Edge::append ( Edge **e, int id, int idAdj, int w, QColor color ) {
    if (*e==NULL)
        *e = new Edge ( id, idAdj, w, color );
    else
        append( &(*e)->next, id, idAdj, w, color );
}

Edge* Edge::removeLeast ( Edge **e, Edge *m ) {
    if (*e) {
        if (!m) m=*e;

        if ((*e)->getW()<m->getW())
            m = removeLeast( &(*e)->next,*e);
        else
            m = removeLeast( &(*e)->next,m);

        if (m==*e) {
            *e = m->getNext();
            m->next = NULL;
        }
    }
    return m;
}

Edge* Edge::clone ( Edge *e ) {
    if (e) {
        Edge *h = new Edge(e->getId(), e->getIdAdj(),e->getW(), e->getColor() );
        h->next = clone(e->next);
        return h;
    }
    return NULL;
}

Edge::~Edge() {
    qDebug() << "Excluindo aresta (" << id <<","<<idAdj<<"," << w << ")";
    if (this->next!=NULL)
        delete this->next;
}

