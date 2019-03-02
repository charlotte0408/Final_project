#include "qgameboard.h"
#include "board.h"
#include "game.h"
#include "qtile.h"
#include "tile.h"

#include <QGridLayout>
#include <QKeyEvent>

QGameboard :: QGameboard(QWidget *parent): QWidget(parent)
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
            delete gui_board[i][j];
            gui_board[i][j] = new QTile(game->get_board()->get_tile(i,j));
            board_layout->addWidget(gui_board[i][j],i,j);
            gui_board[i][j]->draw();
        }
    }
}

QGameboard::~QGameboard()
{
    delete game;
}

void QGameboard::notify()
{
    if (game->won())
        score->setText(QString("You hit 2048, congratulations! Keep playing to increase your score.\t\t SCORE: %1").arg(game->getScore()));
    if (game->isover())

    drawboard();
}

void QGameboard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W:
        game->move(Up);
        break;
    case Qt::Key_A:
        game->move(Left);
        break;
    case Qt::Key_S:
        game->move(Down);
        break;
    case Qt::Key_D:
        game->move(Right);
        break;
    }
}
