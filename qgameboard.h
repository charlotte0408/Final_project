#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include <QVector>
#include <QWidget>
#include <QGame
class Game;
class QTile;
class QGridLayout;

class QGameboard : public QWidget
{
private:
    QVector<QVector<QTile*>> gui_board;
    Game* game;
    QGridLayout* board_layout;
    QGameOverWindow gameOverWindow
    void drawboard();
public:
    explicit QGameboard(QWidget *parent = nullptr);
    ~QGameboard();
    //void notify();
    void keyPressEvent(QKeyEvent *event);
};

#endif // QGAMEBOARD_H
