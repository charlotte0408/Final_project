#include "board.h"
#include "tile.h"
#include <QVector>

Board& Board::operator=(const Board&b)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != b.board[i][j])
            {
                delete board[i][j];
                board[i][j] = new Tile(*(b.board[i][j]));
            }
        }
    return *this;
}

bool Board::get_order()
{
    return order;
}

bool Board::find_2048()
{
    for (int i = 0 ; i <= 3; i++)
            for (int j = 0 ; j <= 3; j++)
            {
                if (board[i][j]->get_value() == 2048)
                    return true;
            }
        return false;
}

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
            if (b.board[i][j] == nullptr)
                board[i][j] = nullptr;
            else {
                board[i][j] = new Tile(*(b.board[i][j]));
            }
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
    if (order == true)
        random();
    notifyObservers();
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
                        board[i][index]->set_value(board[i][j]->get_value());
                        board[i][j]->set_value(0);
                        order = true;
                    }
                }
            }
         }
}

void Board::rightmove()
{
    order = false;
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 3; j >= 1; j--) // start from the right most
            {
                if (board[i][j]->get_value() != board[i][j-1]->get_value() && board[i][j-1]->get_value() != 0) // next two are nonempty and not the same
                    continue;
                if (board[i][j]->get_value() == 0)
                    continue;
                for (int k = j-1; k >= 0; k--)
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
                for (int j = 2; j >= 0; j--)
                {
                    if (board[i][j]->get_value() == 0)
                        continue;
                    else
                    {
                        int index = right_find_nearest0(i,j);
                        if (index != j){
                            board[i][index]->set_value(board[i][j]->get_value());
                            board[i][j]->set_value(0) ;
                            order = true;
                        }
                    }
                }
            }

}

void Board::upmove()
{
    Board A = this -> rotate_counterclock();
    A.leftmove();
    *this = A.rotate_clock();
}

void Board::downmove()
{
    Board A = this -> rotate_counterclock();
    A.rightmove();
    *this = A.rotate_clock();
}

Board Board::rotate_clock()
{
    for (int i = 0; i <= 3; i++)
        {
            for (int j = i; j <= 3; j++)
            {
                int tmp = board[j][i]->get_value();
                board[j][i]->set_value(board[i][j]->get_value());
                board[i][j]->set_value(tmp);
            }
        }
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                int copy = board[i][3-j]->get_value();
                board[i][3-j]->set_value(board[i][j]->get_value());
                board[i][j]->set_value(copy);
            }
        }
        return *this;
}

Board Board::rotate_counterclock()
{
    for (int i = 0; i <= 3; i++)
        {
            for (int j = i; j <= 3; j++)
            {
                int tmp = board[j][i]->get_value();
                board[j][i]->set_value( board[i][j]->get_value());
                board[i][j]->set_value(tmp);
            }
        }
        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                int tmp = board[3-i][j]->get_value();
                board[3-i][j]->set_value(board[i][j]->get_value());
                board[i][j]->set_value(tmp);
            }
        }
        return *this;
}

int Board::left_find_nearest0(int row, int col)
{
    int index = col;
       int i = col - 1;
       while (i >= 0 && board[row][i]->get_value() == 0){
           index = i;
           i--;
       }
       return index;
}

int Board::right_find_nearest0(int row, int col)
{
    int index = col;
        int i = col + 1;
        while (i <= 3 && board[row][i]->get_value() == 0){
            index = i;
            i++;
        }
        return index;
}

void Board::random()
{
    Board check (1,15);
        int count = 0;
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                if (board[i][j]->get_value() == 0)
                {
                    check.board[0][count]->set_value(i);
                    check.board[1][count]->set_value(j);
                    count ++;
                }
            }
        }
        int position = rand() % (count - 1);
        int rn = rand() % 9;
        int next = 0;
        if (rn <= 8)
            next = 2;
        else
            next = 4;
        int i = check.board[0][position]->get_value();
        int j = check.board[1][position]->get_value();
        board[i][j]->set_value(next);
}

bool Board::full()
{
    for (int i = 0 ; i <= 3; i++)
            for (int j = 0 ; j <= 3; j++)
            {
                if (board[i][j]->get_value() == 0)
                    return false;
            }
        return true;
}

Tile* Board::get_tile(int col, int row)
{
    return board[col][row];
}
