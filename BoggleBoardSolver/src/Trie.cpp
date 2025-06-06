#include "Trie.h"
#include <fstream>
#include <iostream>

Trie::Trie(const string& filepath) {
    ifstream inFile(filepath);

    if(inFile.good()) {
        root = new TrieElement;
        root->nextLetters = new TrieElement*[26];
        for(int i = 0; i < 26; i++) {
            root->nextLetters[i] = nullptr;
        }
        root->isWordComplete = false;
        root->wordSoFar = "";
        string word;
        while(inFile) {
            inFile >> word;
            cleanse(word);
            insertWord(root, word);
        }
        inFile.close();
    }
    else throw "File Read Error";

}
//--
Trie::~Trie() {
    deleteAll(root);
}
void Trie::deleteAll(TrieElement*& p) {
    if(p) {
        for(int i = 0; i < 26; i++) {
            if(p->nextLetters[i]) deleteAll(p->nextLetters[i]);
        }
//        cout<<"deleting array"<<endl;
        delete [] p->nextLetters;
//        cout<<"Deleting trie element"<<endl;
        delete p;
    }
}
//--
string Trie::search(string word) {
    cleanse(word);
    return search(root, word, -1);
}
string Trie::search(TrieElement* p, const string& word, int index) {
    if(!p) return "NOT FOUND";
    if(p->wordSoFar == word) {
        if(p->isWordComplete) return "FOUND";
        return "PARTIAL";
    }
    index++;
    if(isalpha(word[index])) {
        int pos = tolower(word[index]) - 'a';
        return search(p->nextLetters[pos], word, index);
    }
    else throw "Word contains non-alphabetical characters";
}
//--
void Trie::printAllWords() {
    printHelper(root);
}
void Trie::printHelper(TrieElement* p) {
    if(p->isWordComplete) {
        cout << p->wordSoFar << " ";
    }
    for(int i = 0; i < 26; i++) {
        if(p->nextLetters[i]) {
            printHelper(p->nextLetters[i]);
        }
    }
}
//--
void Trie::cleanse(string& s) {
    for(char& c : s) {
        c = (char)tolower(c);
    }
}

void Trie::insertWord(TrieElement*& p, string s) {
    if(s.empty()) return;

    if(isalpha(s[0])) {
        int pos = tolower(s[0]) - 'a';
        if(!p->nextLetters[pos]) {
            TrieElement* t = new TrieElement;
            t->nextLetters = new TrieElement*[26];
            for(int i = 0; i < 26; i++) {
                t->nextLetters[i] = nullptr;
            }
            t->isWordComplete = s.length() == 1;
            t->wordSoFar = p->wordSoFar + s[0];
            p->nextLetters[pos] = t;
            insertWord(t, s.substr(1));
        }
        else {
            insertWord(p->nextLetters[pos], s.substr(1));
        }
    }
    else throw "Word contains non-alpha betical characters";
}