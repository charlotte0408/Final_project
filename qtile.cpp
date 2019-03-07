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
        case 64:{
            setStyleSheet("QLabel { background: rgb(236,120,81); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 128:{
            setStyleSheet("QLabel { background: rgb(233,214,120); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 256:{
            setStyleSheet("QLabel { background: rgb(234,213,120); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 512:{
            setStyleSheet("QLabel { background: rgb(234,214,119); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 1024:{
            setStyleSheet("QLabel { background: rgb(233,214,119); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }
        case 2048:{
            setStyleSheet("QLabel { background: rgb(233,106,73); color: black; font: bold; border-radius: 10px; font: 40pt; }");
            setText(QString::number(tile->get_value()));
            break;
        }

     }


}



