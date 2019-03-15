#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include <QVector>
#include <QWidget>
#include "qgameoverwindow.h"
#include <QVBoxLayout>
#include "observer.h"
class Game;
class QTile;
class QGridLayout;

class QGameboard : public QWidget, public Observer
{
private:
    QVector<QVector<QTile*>> gui_board;
    Game* game;
    QVBoxLayout* mainLayout;
    QGridLayout* board_layout;
    QGameOverWindow gameOverWindow;
    QGameOverWindow wonWindow;
    void drawboard();
public:
    explicit QGameboard(QWidget *parent = nullptr);
    ~QGameboard();
    void notify();
    void keyPressEvent(QKeyEvent *event);
};

#endif // QGAMEBOARD_H
