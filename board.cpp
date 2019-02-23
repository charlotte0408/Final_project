#include "board.h"
#include "tile.h"
#include <QVector>

Board::Board(int row, int col)
{
    board.resize(row+1);
    for (int i = 0; i <= row; i++)
        for (int j = 0; j <= col; j++)
        {
            Tile* t = new Tile();
            board[i].push_back(t);
        }
}
