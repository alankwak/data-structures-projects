#pragma once
#include <string>

using namespace std;

class MapException {
public:
    MapException(string m);
    string getError() const;
private:
    string error;
};
