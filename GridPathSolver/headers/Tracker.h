#pragma once
#include "Cell.h"

class Tracker {
public:
    explicit Tracker(Cell* c);
    bool findPath();
    int findShortestPath();
    bool findPath(int row, int col);
private:
    Cell* p_curr;
};