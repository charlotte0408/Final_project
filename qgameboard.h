#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include <QWidget>
#include <QGridLayout>
#include "board.h"
#include "game.h"
#include "qtile.h"
class QGameboard : public QWidget
{
private:
    QVector<QVector<QTile*>> gui_board;
    Game* game;
    QGridLayout* board_layout;
    void draw();
public:
    QGameboard(QWidget *parent = nullptr);
};

#endif // QGAMEBOARD_H
