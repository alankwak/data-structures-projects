#include "Die.h"

Die::Die(string* s) {
    int i = rand() % 6;
    faceUp = s[i];
}

Die::Die(string& s) {
    faceUp = s;
}

string Die::getFace() {
    return faceUp;
}
void Die::setUsed(bool b) {
    used = b;
}
bool Die::isUsed() {
    return used;
}