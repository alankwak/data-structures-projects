#pragma once
#include <iostream>
#include "DoublyLinkedListException.h"

using namespace std;

template <class T>
class DoublyLinkedList {
public:
    DoublyLinkedList(); //creates an empty list
    DoublyLinkedList(const DoublyLinkedList& original); //makes a deep copy of an existing list
    ~DoublyLinkedList(); //frees up the nodes created for the list

    void insertAtFront(const T& elem);
    void insertAtRear(const T& elem);
    bool removeFromFront(T& elem); //true if an item is removed, elem holds that value
    bool removeFromRear(T& elem); //true if an item is removed, elem holds that value
    bool remove(); //remove the element that the current pointer points to
    bool remove(const T& elem); //remove all occurrences of the element that is passed in.
    int size() const;
    bool first(T& elem);
    bool last(T& elem);
    bool next(T& elem);
    bool previous(T& elem);
    bool isEmpty() const;
    bool find(const T& elem); //returns a true/false value indicating if an element is present in the list
    T& at(const int& pos) const; //a method that simulates accessing the list like an array. Throw any exception type if out of bounds.
    T& operator[](const int& pos) const; //call at()
private:
    struct Node {
        Node* p_next = nullptr;
        Node* p_prev = nullptr;
        T data;
    };

    Node* p_head;
    Node* p_tail;
    Node* p_current;
    int numElements;
};
//-----------------------------
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    numElements = 0;
    p_head = nullptr;
    p_tail = nullptr;
    p_current = nullptr;
}
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& original) : DoublyLinkedList() {
    for(int i = 0; i < original.size(); i++) {
        insertAtRear(original[i]);
    }
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* p_delete;
    while(!isEmpty())
    {
        p_delete = p_head;
        p_head = p_head->p_next;
        delete p_delete;
        numElements--;
    }
}
//-----------------------------
template <class T>
void DoublyLinkedList<T>::insertAtFront(const T& elem) {
    Node* p_newNode = new Node;
    p_newNode->data = elem;
    if(size() == 0) {
        p_head = p_newNode;
        p_tail = p_newNode;
    }
    else {
        p_newNode->p_next = p_head;
        p_head->p_prev = p_newNode;
        p_head = p_newNode;
    }
    numElements++;
}
template <class T>
void DoublyLinkedList<T>::insertAtRear(const T& elem) {
    Node* p_newNode = new Node;
    p_newNode->data = elem;
    if(size() == 0) {
        p_head = p_newNode;
        p_tail = p_newNode;
    }
    else {
        p_newNode->p_prev = p_tail;
        p_tail->p_next = p_newNode;
        p_tail = p_newNode;
    }
    numElements++;
}
template <class T>
bool DoublyLinkedList<T>::removeFromFront(T& elem) {
    if(size() == 0) {
        return false;
    }
    else if(size() == 1) {
        elem = p_head->data;
        delete p_head;
        p_head = nullptr;
        p_tail = nullptr;
        numElements--;
        return true;
    }
    else {
        Node* p_delete = p_head;
        p_head = p_head->p_next;
        p_head->p_prev = nullptr;
        elem = p_delete->data;
        delete p_delete;
        numElements--;
        return true;
    }
}
template <class T>
bool DoublyLinkedList<T>::removeFromRear(T& elem) {
    if(size() == 0) {
        return false;
    }
    else if(size() == 1) {
        elem = p_head->data;
        delete p_head;
        p_head = nullptr;
        p_tail = nullptr;
        numElements--;
        return true;
    }
    else {
        Node *p_delete = p_tail;
        p_tail = p_tail->p_prev;
        elem = p_delete->data;
        p_tail->p_next = nullptr;
        delete p_delete;
        numElements--;
        return true;
    }
}
//-----------------------------
template <class T>
bool DoublyLinkedList<T>::remove() {
    if(p_current == p_head) {
        p_current = p_head->p_next;
        T ph;
        return removeFromFront(ph);
    }
    else if(p_current == p_tail) {
        p_current = p_tail->p_prev;
        T ph;
        return removeFromRear(ph);
    }
    else if(size() > 0){
        Node* p_delete = p_current;
        p_current = p_current->p_prev;
        p_delete->p_prev->p_next = p_delete->p_next;
        p_delete->p_next->p_prev = p_delete->p_prev;
        delete p_delete;
        numElements--;
        return true;
    }
    return false;
}
template <class T>
bool DoublyLinkedList<T>::remove(const T& elem) {
    p_current = p_head;
    bool retVal = false;
    while(p_current) {
        if(p_current->data == elem) {
            remove();
            retVal = true;
        }
        else {
            p_current = p_current->p_next;
        }
    }
    return retVal;
}
//-----------------------------
template <class T>
int DoublyLinkedList<T>::size() const {
    return numElements;
}
//-----------------------------
template <class T>
bool DoublyLinkedList<T>::first(T& elem) {
    if(p_head != nullptr) {
        elem = p_head->data;
        p_current = p_head;
        return true;
    }
    return false;
}
template <class T>
bool DoublyLinkedList<T>::last(T& elem) {
    if(p_tail != nullptr) {
        elem = p_tail->data;
        p_current = p_tail;
        return true;
    }
    return false;
}
template <class T>
bool DoublyLinkedList<T>::next(T& elem) {
    if(p_current and p_current->p_next != nullptr) {
        p_current = p_current->p_next;
        elem = p_current->data;
        return true;
    }
    return false;
}
template <class T>
bool DoublyLinkedList<T>::previous(T& elem) {
    if(p_current and p_current->p_prev != nullptr) {
        p_current = p_current->p_prev;
        elem = p_current->data;
        return true;
    }
    return false;
}
//-----------------------------
template <class T>
bool DoublyLinkedList<T>::isEmpty() const {
    return size() == 0;
}
template <class T>
bool DoublyLinkedList<T>::find(const T& elem) {
    p_current = p_head;
    while(p_current != nullptr) {
        if(p_current->data == elem) {
            return true;
        }
        p_current = p_current->p_next;
    }
    return false;
}
template <class T>
T& DoublyLinkedList<T>::at(const int& pos) const {
    if(pos >= numElements or pos < 0) {
        DoublyLinkedListException ex("Out of Bounds Exception");
        throw ex;
    }
    Node* p_curr = p_head;
    for(int i = 0; i < pos; i++) {
        p_curr = p_curr->p_next;
    }
    return p_curr->data;
}
template <class T>
T& DoublyLinkedList<T>::operator[](const int& pos) const {
    return at(pos);
}