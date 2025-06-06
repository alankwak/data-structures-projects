#pragma once
#include "MapException.h"
#include "Cell.h"

class Map {
public:
    Map(const string& pathToMapFile);
    ~Map();
    Cell* getStartCell();
    void printMap();
    void printPathThroughMap();

private:
    int dimension;
    Cell* p_topLeftCell = nullptr;
    Cell* p_startCell = nullptr;
};