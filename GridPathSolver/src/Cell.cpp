#include "Cell.h"

Cell::Cell(char& t, int& r, int& c) {
    type = t;
    row = r;
    col = c;
}
char Cell::getType() const {
    return type;
}

Cell* Cell::getNorth() const {
    return p_north;
}
Cell* Cell::getSouth() const {
    return p_south;
}
Cell* Cell::getEast() const {
    return p_east;
}
Cell* Cell::getWest() const {
    return p_west;
}
void Cell::setNorth(Cell* &n) {
    p_north = n;
}
void Cell::setSouth(Cell* &s) {
    p_south = s;
}
void Cell::setEast(Cell* &e) {
    p_east = e;
}
void Cell::setWest(Cell* &w) {
    p_west = w;
}

bool Cell::isOnPath() const {
    return onPath;
}
void Cell::setOnPath(bool v) {
    onPath = v;
}
bool Cell::isTraversed() const {
    return traversed;
}
void Cell::setTraversed(bool v) {
    traversed = v;
}

int Cell::getRow() const {
    return row;
}
int Cell::getCol() const {
    return col;
}
