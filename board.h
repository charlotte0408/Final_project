#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <string>
#include "tile.h"
#include "subject.h"

enum Direction{Left, Right, Up, Down};

class Board : public Subject
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
    Board(int row = 3, int col = 3);
    Board(const Board&);
    virtual ~Board();
    void move(Direction d);
    void random();
    bool full();
    bool get_order();
    bool find_2048();
};
#endif // BOARD_H
