#include "board.h"
#include "tile.h"
#include <QVector>

Board::Board(int row, int col):order(false)
{
    board.resize(row+1);
    for (int i = 0; i <= row; i++)
        for (int j = 0; j <= col; j++)
        {
            Tile* t = new Tile();
            board[i].push_back(t);
        }
}

Board::Board(const Board & b)
{
    order = b.order;
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
        {
            Tile* t = new Tile(b.board[i][i]->get_value());
            board[i][j] = t;
        }
}

Board :: ~Board()
{
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <=3; j++)
            delete board[i][j];
}

void Board::move(Direction d)
{
    if (d == Left)
        leftmove();
    if (d == Right)
        rightmove();
    if (d == Up)
        upmove();
    else
        downmove();
}

void Board::leftmove()
{
    order = false;
    for (int i = 0; i <= 3; i++) // loop through rows
        {
            for (int j = 0; j< 3; j++) // start from the most left
            {
                if (board[i][j+1]->get_value() != 0 && board[i][j]->get_value()!= board[i][j+1]->get_value()) // if jth is not equal to its next and its next is not empty, move to the next spot
                    continue;
                if (board[i][j]->get_value() == 0) // if jth is empty, move to the next spot
                    continue;
                for (int k = j+1; k <= 3; k++) // if (j+1)th is empty or jth is equal to its next
                {
                    if (board[i][j]->get_value() == board[i][k]->get_value())
                    {
                        board[i][j]->set_value(2*board[i][j]->get_value());
                        board[i][k]->set_value(0);
                        order = true;
                        break;
                    }
                }

            }
        }
    for (int i = 0; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (board[i][j]->get_value() == 0)
                    continue;
                else
                {
                    int index = left_find_nearest0(i,j);
                    if (index != j){
                        m[i][index] = m[i][j];
                        m[i][j] = 0;
                        order = true;
                    }
                }
            }
         }
}

int Board::left_find_nearest0(int row, int col)
{

}
