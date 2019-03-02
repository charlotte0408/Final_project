#include "qgameoverwindow.h"
#include <QVBoxLayout>
#include <QLabel>

QGameOverWindow::QGameOverWindow(QWidget *parent):QWidget(parent)
{
    setStyleSheet("QGameOverWindow { background: rgb(237,224,200); }");
    setFixedSize(425,205);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    QLabel* gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40pt; font: bold;} ");
    layout->insertWidget(0,gameover,0,Qt::AlignCenter);
}

