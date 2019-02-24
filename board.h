#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <string>
#include "tile.h"

enum Direction{Left, Right, Up, Down};

class Board
{
private:
    QVector<QVector<Tile*>> board;
    bool order;
    void leftmove();
    void rightmove();
    void upmove();
    void downmove();
    Board rotate_clock();
    Board rotate_counterclock();
    int left_find_nearest0(int row, int col);
    int right_find_nearest0(int row, int col);
public:
    Board(int row, int col);
    Board(const Board&);
    virtual ~Board();
    void move(Direction d);
};
#endif // BOARD_H
