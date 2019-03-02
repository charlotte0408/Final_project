
#include <QApplication>

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "board.h"
#include "qgameboard.h"

#include "qgameoverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(nullptr));

    QGameboard board;
    board.show();

    return a.exec();
}
