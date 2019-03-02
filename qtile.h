#ifndef QTILE_H
#define QTILE_H

#include <QLabel>

class Tile;

class QTile : public QLabel
{
public:
    QTile(const QString & text);
    QTile(Tile* tile);
    void draw();
private:
    Tile* tile;
};


#endif // QTILE_H
