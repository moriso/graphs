/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QWidget *centralWidget;
    QComboBox *cbOrigem;
    QLabel *labelInicial;
    QLabel *labelFinal;
    QComboBox *cbFinal;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QComboBox *metodos;
    QPushButton *start;
    QMenuBar *menuBar;
    QMenu *menuGraphs;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(613, 421);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cbOrigem = new QComboBox(centralWidget);
        cbOrigem->setObjectName(QStringLiteral("cbOrigem"));
        cbOrigem->setGeometry(QRect(160, 20, 191, 22));
        labelInicial = new QLabel(centralWidget);
        labelInicial->setObjectName(QStringLiteral("labelInicial"));
        labelInicial->setGeometry(QRect(50, 20, 101, 16));
        labelFinal = new QLabel(centralWidget);
        labelFinal->setObjectName(QStringLiteral("labelFinal"));
        labelFinal->setGeometry(QRect(50, 80, 121, 16));
        cbFinal = new QComboBox(centralWidget);
        cbFinal->setObjectName(QStringLiteral("cbFinal"));
        cbFinal->setGeometry(QRect(160, 80, 191, 22));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(160, 160, 191, 81));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 260, 131, 23));
        metodos = new QComboBox(centralWidget);
        metodos->setObjectName(QStringLiteral("metodos"));
        metodos->setGeometry(QRect(390, 60, 191, 22));
        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(380, 130, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 613, 21));
        menuGraphs = new QMenu(menuBar);
        menuGraphs->setObjectName(QStringLiteral("menuGraphs"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuGraphs->menuAction());
        menuGraphs->addAction(actionLoad);
        mainToolBar->addAction(actionLoad);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Projeto e Analise de Algoritmos (Ci\303\252ncia da Computa\303\247\303\243o)", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Carregar", 0));
        labelInicial->setText(QApplication::translate("MainWindow", "Select initial node:", 0));
        labelFinal->setText(QApplication::translate("MainWindow", "Select final node:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Mostrar Caminho", 0));
        metodos->clear();
        metodos->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "DFS", 0)
         << QApplication::translate("MainWindow", "BFS", 0)
         << QApplication::translate("MainWindow", "ORDENA\303\207\303\203O TOPOL\303\223GICA", 0)
         << QApplication::translate("MainWindow", "PRIM", 0)
         << QApplication::translate("MainWindow", "KRUSKAL", 0)
         << QApplication::translate("MainWindow", "DIJKSTRA", 0)
         << QApplication::translate("MainWindow", "FORD FUCKERSON", 0)
        );
        start->setText(QApplication::translate("MainWindow", "START", 0));
        menuGraphs->setTitle(QApplication::translate("MainWindow", "Graphs", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
