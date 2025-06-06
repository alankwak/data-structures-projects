#pragma once
#include <string>

using namespace std;

class DoublyLinkedListException {
public:
    DoublyLinkedListException(const string& m);
    string getError();
private:
    string message;
};
