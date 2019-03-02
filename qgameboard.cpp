#include "qgameboard.h"

QGameboard :: QGameboard(QWidget *parent):QWidget(parent)
{
    game = new Game();
    board_layout = nullptr;
    gui_board.resize(4);
    for (int i = 0; i < 4; ++i)
        gui_board[i].resize(4);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            gui_board[i][j] = nullptr;
    drawboard();
}

void QGameboard::drawboard()
{
    delete board_layout;
    board_layout = new QGridLayout();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gui_board[i][j] = new QTile(game->get_board()->get_tile(i,j));
            board_layout->addWidget(gui_board[i][j],i,j);
            gui_board[i][j]->draw();
    }
}
