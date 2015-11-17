#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>

#include "Graph.h"

#include "Dfs.h"
#include "Bfs.h"

#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class Interface;
}

class Interface : public QMainWindow {
    Q_OBJECT

signals:
    void mostrar ( Graph *);

public:
    explicit Interface(QWidget *parent = 0);
     void mostrarLista(QList<Vertex *> lista);
     void getCaminho (QString metodo);
    ~Interface();

public slots:
    void mostrarGraph ( Graph * );


private slots:
    void on_actionLoad_triggered();

    void on_start_clicked();
    void on_pushButton_clicked();

private:
    Ui::Interface *interface;
    Graph *grafo, *tmp;
    QThread *algoritmo;
    int idmostrar;
    int metodo;
    void executarAlgoritmo ( int i );


protected:
    virtual void paintEvent(QPaintEvent *);
};

#endif // INTERFACE_H
