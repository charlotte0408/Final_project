#ifndef QTILE_H
#define QTILE_H

#include "tile.h"
#include <QLabel>

class Tile;

class QTile : public QLabel
{
    Q_OBJECT
public:
    QTile(const QString & text);
    QTile(Tile* tile);
    void draw();
private:
    Tile* tile;
};


#endif // QTILE_H
