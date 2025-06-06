#include "Map.h"
#include "Queue.h"
#include <fstream>
#include <iostream>
#include <cmath>

Map::Map(const string& pathToMapFile) {
    ifstream inFile;
    inFile.open(pathToMapFile);

    if(inFile.good()) {
        Queue<char> q;

        while(inFile) {
            char c;
            inFile >> c;
            q.enqueue(c);
        }

        int n = q.size()-1;
        dimension = (int)sqrt(n);

        Cell** cells = new Cell*[n];
        for(int i = 0; i < n; i++) {
            char type = q.dequeue();
            int row = i / dimension;
            int col = i % dimension;
            Cell* c = new Cell(type, row, col);
            cells[i] = c;
            if(type == 'S') {
                if(p_startCell != nullptr) {
                    throw MapException("More Than One Starting Cell");;
                }
                p_startCell = c;
            }
        }

        p_topLeftCell = cells[0];

        for(int i = 0; i < n; i++) {
            Cell* curr = cells[i];
            if(i % dimension != 0) {
                curr->setWest(cells[i-1]);
            }
            if(i % dimension != dimension-1) {
                curr->setEast(cells[i+1]);
            }
            if(i >= dimension) {
                curr->setNorth(cells[i-dimension]);
            }
            if(i < n - dimension) {
                curr->setSouth(cells[i+dimension]);
            }
        }

        delete [] cells;
    }
    else {
        throw MapException("File Read Error");
    }
}

Map::~Map() {
    Cell* p_left = p_topLeftCell;
    while(p_left != nullptr) {
        Cell* p_temp = p_left->getEast();
        while(p_temp != nullptr) {
            Cell* p_delete = p_temp;
            p_temp = p_temp->getEast();
            delete p_delete;
        }
        p_temp = p_left;
        p_left = p_left->getSouth();
        delete p_temp;
    }

}

Cell* Map::getStartCell() {
    return p_startCell;
}
void Map::printMap() {
    Cell* p_left = p_topLeftCell;
    while(p_left != nullptr) {
        Cell* p_cell = p_left;
        while(p_cell != nullptr) {
            cout<<p_cell->getType()<<" ";
            p_cell = p_cell->getEast();
        }
        cout<<endl;
        p_left = p_left->getSouth();
    }
}
void Map::printPathThroughMap() {
    Cell* p_left = p_topLeftCell;
    while(p_left != nullptr) {
        Cell* p_cell = p_left;
        while(p_cell != nullptr) {
            p_cell->isOnPath() ? cout<<"O " : cout<<"X ";
            p_cell = p_cell->getEast();
        }
        cout<<endl;
        p_left = p_left->getSouth();
    }
}
