#pragma once
#include <string>

using namespace std;
class Trie {
public:
    Trie(const string& filepath);
    ~Trie();
    string search(string word);
    void printAllWords();
private:
    struct TrieElement {
        TrieElement** nextLetters;
        bool isWordComplete;
        string wordSoFar;
    };
    TrieElement* root;

    void insertWord(TrieElement*& p, string s);
    void deleteAll(TrieElement*& p);
    void cleanse(string& word);

    string search(TrieElement* p, const string& word, int index);
    void printHelper(TrieElement* p);
};