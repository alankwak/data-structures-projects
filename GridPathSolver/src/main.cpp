#include <iostream>
#include "Map.h"
#include "Tracker.h"

int main() {
    Map m(""); // path to your graph

    //create a tracker capable of traversing through a map
    Tracker tracker(m.getStartCell());

    //send the tracker to find a path through the map, print length of shortest path
    cout<<tracker.findShortestPath()<<endl;

    //print the original cells from the file
    m.printMap();
    cout<<endl;

    //print an X/O map from the start to the end
    m.printPathThroughMap();

    return 0;
}
