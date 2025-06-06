#pragma once
#include "DoublyLinkedList.h"

template < class T >
class Stack
{
public:
    Stack();
    Stack(const Stack& original);
    void push(const T& elem);
    T pop();
    T top();
    int size() const;
    bool isEmpty() const;
private:
    DoublyLinkedList<T> stack;
};
//--------------------------
template <class T>
Stack<T>::Stack() = default;
template <class T>
Stack<T>::Stack(const Stack& original) {
    DoublyLinkedList<T> temp = original.stack;
    while(!temp.isEmpty()) {
        T removed;
        temp.removeFromRear(removed);
        stack.insertAtFront(removed);
    }
}
//--------------------------
template <class T>
void Stack<T>::push(const T& elem) {
    stack.insertAtRear(elem);
}
template <class T>
T Stack<T>::pop() {
    T removed;
    stack.removeFromRear(removed);
    return removed;
}
template <class T>
T Stack<T>::top() {
    T end;
    stack.last(end);
    return end;
}
template <class T>
int Stack<T>::size() const {
    return stack.size();
}
template <class T>
bool Stack<T>::isEmpty() const {
    return size() == 0;
}