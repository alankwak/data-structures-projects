#pragma once

class Cell {
public:
    Cell(char& t, int& r, int& c);
    char getType() const;

    Cell* getNorth() const;
    Cell* getSouth() const;
    Cell* getEast() const;
    Cell* getWest() const;
    void setNorth(Cell* &n);
    void setSouth(Cell* &s);
    void setEast(Cell* &e);
    void setWest(Cell* &w);

    bool isOnPath() const;
    void setOnPath(bool v);
    bool isTraversed() const;
    void setTraversed(bool v);

    int getRow() const;
    int getCol() const;
private:
    char type;
    bool onPath = false;
    bool traversed = false;

    int row;
    int col;

    Cell* p_north = nullptr;
    Cell* p_south = nullptr;
    Cell* p_east = nullptr;
    Cell* p_west = nullptr;
};