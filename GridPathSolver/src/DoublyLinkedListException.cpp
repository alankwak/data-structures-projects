#include "DoublyLinkedListException.h"

DoublyLinkedListException::DoublyLinkedListException(const string& m) {
    message = m;
}

string DoublyLinkedListException::getError() {
    return message;
}