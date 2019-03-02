#include "mainwindow.h"
#include "qgameboard.h"

class QGameBoard;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    gameBoard = new QGameboard(this);
    setCentralWidget(gameBoard);
}

MainWindow::~MainWindow()
{
  //  delete ui;
}
