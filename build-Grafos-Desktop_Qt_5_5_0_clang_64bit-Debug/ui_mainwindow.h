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
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *start;
    QComboBox *cbFinal;
    QComboBox *metodos;
    QComboBox *cbOrigem;
    QTextEdit *textEdit;
    QLabel *labelFinal;
    QLabel *labelInicial;
    QMenuBar *menuBar;
    QMenu *menuGraphs;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(578, 422);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));

        horizontalLayout->addWidget(start);

        cbFinal = new QComboBox(centralWidget);
        cbFinal->setObjectName(QStringLiteral("cbFinal"));

        horizontalLayout->addWidget(cbFinal);

        metodos = new QComboBox(centralWidget);
        metodos->setObjectName(QStringLiteral("metodos"));

        horizontalLayout->addWidget(metodos);

        cbOrigem = new QComboBox(centralWidget);
        cbOrigem->setObjectName(QStringLiteral("cbOrigem"));

        horizontalLayout->addWidget(cbOrigem);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout->addWidget(textEdit);

        labelFinal = new QLabel(centralWidget);
        labelFinal->setObjectName(QStringLiteral("labelFinal"));

        horizontalLayout->addWidget(labelFinal);

        labelInicial = new QLabel(centralWidget);
        labelInicial->setObjectName(QStringLiteral("labelInicial"));

        horizontalLayout->addWidget(labelInicial);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 578, 22));
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
        pushButton->setText(QApplication::translate("MainWindow", "Mostrar Caminho", 0));
        start->setText(QApplication::translate("MainWindow", "Iniciar", 0));
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
        labelFinal->setText(QApplication::translate("MainWindow", "N\303\263 final", 0));
        labelInicial->setText(QApplication::translate("MainWindow", "N\303\263 inicial", 0));
        menuGraphs->setTitle(QApplication::translate("MainWindow", "Graphs", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
