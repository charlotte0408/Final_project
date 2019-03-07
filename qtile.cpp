#include "tile.h"
#include "qtile.h"
#include <QString>

QTile::QTile(Tile* t)
{
    setAlignment(Qt::AlignCenter);
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
        setText(QString::number(tile->get_value()));
        this -> setStyleSheet("QLabel { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 60pt; }");

    }


}
