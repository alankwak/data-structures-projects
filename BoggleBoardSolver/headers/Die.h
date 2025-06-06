#pragma once
#include <string>

using namespace std;

class Die {
public:
    Die(string* s);
    Die(string& s);
    string getFace();
    void setUsed(bool b);
    bool isUsed();
private:
    bool used = false;
    string faceUp;
};