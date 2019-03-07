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

        switch (tile->get_value()) {
        case 0: {
            setStyleSheet("QLabel { background: rgb(204,192,179); border-radius: 10px; }");
            setText("");
            break;
        }
        case 2:{
            setStyleSheet("QLabel { background: rgb(238,228,218); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 4:{
            setStyleSheet("QLabel { background: rgb(237,229,210); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 8:{
            setStyleSheet("QLabel { background: rgb(239,193,141); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 16:{
            setStyleSheet("QLabel { background: rgb(239,167,111); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 32:{
            setStyleSheet("QLabel { background: rgb(237,146,116); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
     }


}



