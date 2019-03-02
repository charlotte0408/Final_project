#include "board.h"
#include "tile.h"
#include "game.h"
#include <QVector>

void Game::move(Direction dir)
{
    board->move(dir);
    notifyObservers();
}
Game::Game()
{
    board = new Board();
    score = 0;
}

bool Game::isover()
{
    return board->full();
}

bool Game::won()
{
    return board->find_2048();
}

int Game::get_score()
{
    return score;
}

void Game::restart()
{
    delete board;
    board = new Board();
    score = 0;
}

Board* Game::get_board()
{
    return board;
}

Game::~Game()
{
    delete board;
}
