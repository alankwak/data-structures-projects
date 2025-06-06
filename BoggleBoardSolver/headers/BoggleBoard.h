#pragma once
#include "Die.h"
#include "Trie.h"
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class BoggleBoard {
public:
    BoggleBoard(const string& pathToDictionary);
    BoggleBoard(const string& pathToDictionary, const string& pathToCustomBoard);
    ~BoggleBoard();
    void printBoard() const;
    void solve();
private:
    Trie words;
    Die* board[5][5];

    void shuffle(Die** d);
    void solveHelper(int r, int c, string wordSoFar, vector<unordered_set<string>>& found);
};