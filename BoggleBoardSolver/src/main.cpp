#include <iostream>
#include <ctime>
#include "BoggleBoard.h"

using namespace std;

int main() {
    //comment this out while debugging to get the same board over and over again
    srand(time(0));
    BoggleBoard bb("C:/Users/kwak3/Downloads/bigDictionary.txt");

    // If you wanted to input a custom 5x5 grid instead of random dice:
//    BoggleBoard bb("C:/Users/kwak3/Downloads/bigDictionary.txt", "C:/CLionProjects/Data Structures/Assignment3/custombb.txt");

    bb.printBoard();
    bb.solve();

    return 0;
}