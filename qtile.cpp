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
        switch (tile->get_value()) {
        case 2:{
            setStyleSheet("QLabel { background: rgb(237,233,225); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 4:{
            setStyleSheet("QLabel { background: rgb(237,229,210); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 8:{
            setStyleSheet("QLabel { background: rgb(239,193,141); color: black; font: bold; border-radius: 10px; font: 60pt; }");
            break;
        }
        case 16:{
            setStyleSheet("QLabel { background: rgb(239,167,111); color: black; font: bold; border-radius: 10px; font: 60pt; }");
            break;
        }
        case 32:{
            setStyleSheet("QLabel { background: rgb(237,146,116); color: black; font: bold; border-radius: 10px; font: 60pt; }");
            break;
        }
        case 0: {
            setStyleSheet("QTile { background: rgb(238,228,218); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        }
        setText(QString::number(tile->get_value()));

    }


}
