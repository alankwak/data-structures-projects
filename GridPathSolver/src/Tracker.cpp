#include "Tracker.h"
#include "Stack.h"
#include "Queue.h"
#include <unordered_map>

Tracker::Tracker(Cell* c) {
    p_curr = c;
}
bool Tracker::findPath() {
    Stack<Cell*> onPath;
    
    while(p_curr->getType() != 'E') {
        Cell* north = p_curr->getNorth();
        Cell* south = p_curr->getSouth();
        Cell* east = p_curr->getEast();
        Cell* west = p_curr->getWest();

        p_curr->setTraversed(true);
        p_curr->setOnPath(true);
        if(north && !north->isTraversed() && north->getType() != 'B') {
            cout<<"Going North X: "<<north->getCol()<<" Y: "<<north->getRow()<<" Type: "<<north->getType()<<endl;
            onPath.push(p_curr);
            p_curr = north;
        }
        else if(east && !east->isTraversed() && east->getType() != 'B') {
            cout<<"Going East X: "<<east->getCol()<<" Y: "<<east->getRow()<<" Type: "<<east->getType()<<endl;
            onPath.push(p_curr);
            p_curr = east;
        }
        else if(south && !south->isTraversed() && south->getType() != 'B') {
            cout<<"Going South X: "<<south->getCol()<<" Y: "<<south->getRow()<<" Type: "<<south->getType()<<endl;
            onPath.push(p_curr);
            p_curr = south;
        }
        else if(west && !west->isTraversed() && west->getType() != 'B') {
            cout<<"Going West X: "<<west->getCol()<<" Y: "<<west->getRow()<<" Type: "<<west->getType()<<endl;
            onPath.push(p_curr);
            p_curr = west;
        }
        else {
            p_curr->setOnPath(false);
            if(onPath.isEmpty()) {
                return false;
            }
            cout<<"Backtracking from X: "<<p_curr->getCol()<<" Y: "<<p_curr->getRow()<<" Type: "<<p_curr->getType();
            p_curr = onPath.pop();
            cout<<" to X: "<<p_curr->getCol()<<" Y: "<<p_curr->getRow()<<" Type: "<<p_curr->getType()<<endl;
        }
    }

    p_curr->setOnPath(true);

    return true;
}

int Tracker::findShortestPath() {
    Queue<Cell*> q;
    unordered_map<Cell*, Cell*> prevNodes;
    q.enqueue(p_curr);
    
    while(p_curr->getType() != 'E' && !q.isEmpty()) {
        Cell* north = p_curr->getNorth();
        Cell* south = p_curr->getSouth();
        Cell* east = p_curr->getEast();
        Cell* west = p_curr->getWest();
        if(north && !north->isTraversed() && north->getType() != 'B') {
            q.enqueue(north);
            prevNodes[north] = p_curr;
        }
        if(south && !south->isTraversed() && south->getType() != 'B') {
            q.enqueue(south);
            prevNodes[south] = p_curr;
        }
        if(east && !east->isTraversed() && east->getType() != 'B') {
            q.enqueue(east);
            prevNodes[east] = p_curr;
        }
        if(west && !west->isTraversed() && west->getType() != 'B') {
            q.enqueue(west);
            prevNodes[west] = p_curr;
        }

        p_curr->setTraversed(true);
        p_curr = q.dequeue();
    }
    if(p_curr->getType() == 'E') {
        int count = 1;
        while(p_curr->getType() != 'S') {
            p_curr->setOnPath(true);
            p_curr = prevNodes[p_curr];
            count++;
        }
        p_curr->setOnPath(true);
        return count;
    }
    return -1;
}

// I added a method to specify a starting cell for fun
bool Tracker::findPath(int row, int col) {
    while(p_curr && p_curr->getRow() < row) {
        p_curr = p_curr->getSouth();
    }
    while(p_curr && p_curr->getRow() > row) {
        p_curr = p_curr->getNorth();
    }
    while(p_curr && p_curr->getCol() < col) {
        p_curr = p_curr->getEast();
    }
    while(p_curr && p_curr->getCol() > col) {
        p_curr = p_curr->getWest();
    }

    if(!p_curr || p_curr->getType() == 'B') {
        return false;
    }
    return findPath();
}