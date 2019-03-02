#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "subject.h"

class Board;

class Game: public Subject
{
private:
    int score;
    Board* board;
public:
    Game();
    bool won();
    bool isover();
    int get_score();
    void restart();
};

#endif // GAME_H
