#include "BoggleBoard.h"
#include <iostream>
#include <fstream>

BoggleBoard::BoggleBoard(const string& pathToDictionary) : words(pathToDictionary) {
    string dice[25][6] = {
            { "N", "S", "C", "T", "E", "C" },
            { "A", "E", "A", "E", "E", "E" },
            { "H", "H", "L", "R", "O", "D" },
            { "O", "R", "W", "V", "G", "R" },
            { "S", "P", "R", "I", "Y", "Y" },
            { "S", "U", "E", "N", "S", "S" },
            { "M", "E", "A", "U", "E", "G" },
            { "S", "E", "P", "T", "I", "C" },
            { "D", "H", "H", "O", "W", "N" },
            { "L", "E", "P", "T", "I", "S" },
            { "S", "T", "L", "I", "E", "I" },
            { "A", "R", "S", "I", "Y", "F" },
            { "T", "E", "T", "I", "I", "I" },
            { "O", "T", "T", "T", "M", "E" },
            { "N", "M", "N", "E", "G", "A" },
            { "N", "N", "E", "N", "A", "D" },
            { "O", "U", "O", "T", "T", "O" },
            { "B", "Z", "J", "B", "X", "K" },
            { "A", "A", "F", "A", "S", "R" },
            { "T", "O", "O", "U", "W", "N" },
            { "O", "T", "H", "D", "D", "N" },
            { "R", "A", "A", "S", "F", "I" },
            { "H", "O", "D", "R", "L", "N" },
            { "E", "E", "E", "E", "A", "M" },
            { "He", "Qu", "Th", "In", "Er", "An" }
    };
    Die* allDice[25];
    for(int i = 0; i < 25; i++) {
        Die* d = new Die(dice[i]);
        allDice[i] = d;
    }

    shuffle(allDice);

    for(int i = 0; i < 25; i++) {
        board[i/5][i%5] = allDice[i];
    }
}

BoggleBoard::BoggleBoard(const string& pathToDictionary, const string& pathToCustomBoard) : words(pathToDictionary){
    ifstream inFile(pathToCustomBoard);

    if(inFile.good()) {
        string s;
        for(int i = 0; i < 25; i++) {
            if(inFile.good()) {
                inFile >> s;
                Die* d = new Die(s);
                board[i/5][i%5] = d;
            }
        }
        inFile.close();
    }
    else throw "File Read Error";
}

BoggleBoard::~BoggleBoard() {
    for(auto& v : board) {
        for(auto& die : v) {
            delete die;
        }
    }
}
//--
void BoggleBoard::printBoard() const {
    for(const auto& v : board) {
        for(const auto& die : v) {
            die->getFace().length() == 1 ? cout<<die->getFace()<<"  " : cout<<die->getFace()<<" ";
        }
        cout<<endl;
    }
}
void BoggleBoard::solve() {
    vector<unordered_set<string>> found(22);
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            solveHelper(i, j, "", found);
        }
    }
    cout<<"All possible values from longest to shortest"<<endl;
    for(int i = 21; i >= 0; i--) {
        if(!found[i].empty()) {
            cout<<"Length: "<<i+4<<" letters"<<endl;
            for(const string &s : found[i]) {
                cout<<s<<" ";
            }
            cout<<endl;
        }
    }
}
void BoggleBoard::solveHelper(int r, int c, string wordSoFar, vector<unordered_set<string>>& found) {
    if(r < 0 || c < 0 || r > 4 || c > 4 || board[r][c]->isUsed()) {
        return;
    }

    wordSoFar += board[r][c]->getFace();
    string status = words.search(wordSoFar);

    if(status == "NOT FOUND") {
        return;
    }
    else {
        board[r][c]->setUsed(true);
        if(wordSoFar.length() > 3 && status == "FOUND") {
            found[wordSoFar.length()-4].insert(wordSoFar);
        }
        solveHelper(r-1, c-1, wordSoFar, found);
        solveHelper(r-1, c, wordSoFar, found);
        solveHelper(r-1, c+1, wordSoFar, found);
        solveHelper(r, c-1, wordSoFar, found);
        solveHelper(r, c+1, wordSoFar, found);
        solveHelper(r+1, c-1, wordSoFar, found);
        solveHelper(r+1, c, wordSoFar, found);
        solveHelper(r+1, c+1, wordSoFar, found);
        board[r][c]->setUsed(false);
    }

}
void BoggleBoard::shuffle(Die** d) {
    for(int i = 0; i < 25; i++) {
        int randPos = rand() % 25;
        Die* temp = d[i];
        d[i] = d[randPos];
        d[randPos] = temp;
    }
}
