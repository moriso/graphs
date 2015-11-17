#include "Graph.h"

#include <QFile>

Graph::Graph ( int n, QMainWindow *main, QWidget *pai ) : QWidget (pai)  {
    this->main    = main;
    this->arestas   = NULL;
    this->vertice  = NULL;
    this->max     = n;
    this->quantidadeVertexs   = 0;

    resize(n);
}

void Graph::pintar () {

    QPainter pintor(main);

    // Pintar primeiramente as arestas
    for (Edge *aresta=arestas; aresta; aresta= aresta->getNext() ) {
        aresta->pintar( getVertexAt(aresta->getIndice())->getPonto(),
                 getVertexAt(aresta->getIdAdj())->getPonto(),
                 pintor );
    }

    for (int i=0; i<quantidadeVertexs; i++) {
        getVertexAt(i)->pintar(pintor);
    }
}

void Graph::resize ( int n ) {
    dispose();
    this->max    = n;
    this->quantidadeVertexs  = 0;
    this->vertice = new Vertex*[max];
    for (int i=0; i<max; i++) {
        vertice[i] = NULL;
    }
}

int Graph::getVertexIndice ( QString nome ) {
    for (int i=0; i<quantidadeVertexs; i++)
        if ((vertice[i]!=NULL) && (vertice[i]->getNome()==nome.toUpper()))
            return i;
    return -1;
}

Vertex* Graph::getVertexAt ( int indice ) {
    return (indice<quantidadeVertexs)? vertice[indice] : NULL;
}

void Graph::adicionarVertex ( QString nome, QPoint ponto ) {
    if (quantidadeVertexs<max) {
        qDebug() << "Adicionando vértice " << nome;
        vertice[quantidadeVertexs] = new Vertex(quantidadeVertexs, nome.toUpper(), ponto );
        quantidadeVertexs++;
    } else
        qDebug() << "Número de vértices maior que o informado!";
}

bool Graph::adicionarEdge ( QString origem, QString destino, int peso, QColor cor ) {
    int verticeOrigem = getVertexIndice(origem.toUpper());
    int verticeDestino = getVertexIndice(destino.toUpper());
    if ((verticeOrigem==-1) || (verticeDestino==-1)) {
        qDebug() << "Vértice de [origem|destino] não encontrado: " << origem << ", " << destino;
        return false;
    }
    Edge::acrescentar( &arestas, verticeOrigem, verticeDestino, peso, cor ); //adiciona a lista de arestas

    vertice[verticeOrigem]->acrescentar( verticeDestino, peso, cor );
    return true;
}

QString Graph::getCaminho( QString nome ) {
    QString s = "";
    Vertex *vertice = this->vertice [ getVertexIndice( nome ) ];
    while (vertice!=NULL) {
        s += vertice->getNome()+ ",";
        vertice = vertice->getPai();
    }
    return s;
}

Edge *Graph::getEdges() {
    return this->arestas;
}

Vertex **Graph::getVertex ()    {
    return this->vertice;
}

int Graph::getVertexCount()  {
    return this->quantidadeVertexs;
}

QString Graph::carregarDoArquivo( QString nomeArquivo ) {
    QString v="", c="";

    QFile arquivo( nomeArquivo );
    if(!arquivo.open(QIODevice::ReadOnly)) {
        qDebug() << "error " << arquivo.errorString();
        QMessageBox::critical(this, "Lendo arquivo", "Erro na leitura do arquivo selecionado");
        return "";
    }
    QTextStream in(&arquivo);

    QString line;
    QStringList sl;

    int n = in.readLine().toInt();
    resize(n);
    while(!in.atEnd() && n) {
        line = in.readLine();
        //line = 1,100,100 ==> nome vértice, coordenada x, coordenada y
        sl = line.split(",");
        if (sl.count()==3) {
            adicionarVertex ( sl[0], QPoint(sl[1].toInt(), sl[2].toInt()));
            v  += c + sl[0];  c   = ";";
        } else {
            QMessageBox::critical(this,"Carregar vértices", "Erro na estrutura do arquivo - nós [node, coord. x, coord. y]!");
            return "";
        }
        n--;
    }
    while(!in.atEnd() && !line.isEmpty()) {
        line = in.readLine();   // line = (1,2,5)
        line = line.mid(1, line.length() -2 );  // line = 1,2,5
        sl = line.split(",");
        if (sl.count()==3)
            adicionarEdge(sl[0], sl[1], sl[2].toInt() );
        else {
            QMessageBox::critical(this,"Carregar arestas", "Erro na estrutura do arquivo - nós [node, coord. x, coord. y]!");
            return "";
        }
    }

    qDebug() << "Carregado com sucesso!";
    arquivo.close();

    return v;
}

void Graph::dispose () {
    for (int i=0; i<quantidadeVertexs; i++)
        delete vertice[i];
    if (vertice)
        delete [] vertice;
}

Graph::~Graph ( ) {
    qDebug() << "Eliminando o Graph";
    dispose();
}
