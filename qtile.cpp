#include "tile.h"
#include "qtile.h"

QTile::QTile(Tile* t)
{
    tile = t;
}

void QTile::draw()
{
    if (tile == nullptr)
    {
        setText("");
        setStyleSheet("QTile {background- color: yellow, border-width: 10px;}");
    }
    this -> show();

}
