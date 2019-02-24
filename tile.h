#ifndef TILE_H
#define TILE_H

class Tile
{
private:
    int value;
public:
    Tile(int v = 2):value(v){}
    int get_value();
    void set_value(int v);
};

#endif // TILE_H
