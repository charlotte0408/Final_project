#include "qgameboard.h"
#include "board.h"
#include "game.h"
#include "qtile.h"
#include "tile.h"

#include <QDebug>
#include <QGridLayout>
#include <QKeyEvent>

QGameboard :: QGameboard(QWidget *parent): QWidget(parent)
{
    resize(650,450);
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    game = new Game();
    game->registerObserver(this);

    board_layout = nullptr;
    gui_board.resize(4);
    for (int i = 0; i < 4; ++i)
        gui_board[i].resize(4);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            gui_board[i][j] = nullptr;
    setStyleSheet("QGameBoard { background-color: yellow }");
    drawboard();
}

void QGameboard::drawboard()
{
    delete board_layout;
    board_layout = new QGridLayout();
    for (int i = 0; i <=3; i++)
    {
        for (int j = 0; j <=3; j++)
        {
            delete gui_board[i][j];
            gui_board[i][j] = new QTile(game->get_board()->get_tile(i,j));
            board_layout->addWidget(gui_board[i][j],i,j);
            gui_board[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, board_layout);
}

QGameboard::~QGameboard()
{
    delete game;
}

void QGameboard::notify()
{
    if (game->won())
        wonWindow.show();
    if (game->isover())
        gameOverWindow.show();
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
