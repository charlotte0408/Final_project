#ifndef TILE_H
#define TILE_H

class Tile
{
private:
    int value;
public:
    Tile():value(0){}
    Tile(int v):value(v){}
    int get_value();
    void set_value(int v);
};

#endif // TILE_H
