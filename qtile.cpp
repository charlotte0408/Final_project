#include "tile.h"
#include "qtile.h"
#include <QString>

QTile::QTile(Tile* t)
{
    this -> tile = t;
}

void QTile::draw()
{
    if (tile == nullptr)
    {
        setText("");
        setStyleSheet("QTile {background- color: yellow, border-width: 10px;}");
    }
    else {
        setStyleSheet("QTile {background- color: yellow, border-width: 10px;}");
        setText(QString::number(tile->get_value()));
    }


}
