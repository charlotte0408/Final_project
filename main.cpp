#include "mainwindow.h"
#include <QApplication>
#include "tile.h"
#include "qtile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tile* t = new Tile;
    QTile t1(t);
    t1.draw();
    //t1.setParent(w);

    return a.exec();
}
