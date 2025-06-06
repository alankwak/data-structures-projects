#pragma once
#include "DoublyLinkedList.h"

template < class T >
class Queue
{
public:
    Queue();
    Queue(const Queue& original);
    void enqueue(const T& elem);
    T dequeue();
    T front();
    int size() const;
    bool isEmpty() const;
private:
    DoublyLinkedList<T> queue;
};
//--------------------------
template <class T>
Queue<T>::Queue() = default;
template <class T>
Queue<T>::Queue(const Queue& original) {
    DoublyLinkedList<T> temp = original.queue;
    while(!temp.isEmpty()) {
        T removed;
        temp.removeFromRear(removed);
        queue.insertAtFront(removed);
    }
}
//--------------------------
template <class T>
void Queue<T>::enqueue(const T& elem) {
    queue.insertAtRear(elem);
}
template <class T>
T Queue<T>::dequeue() {
    T removed;
    queue.removeFromFront(removed);
    return removed;
}
template <class T>
T Queue<T>::front() {
    T start;
    queue.first(start);
    return start;
}
template <class T>
int Queue<T>::size() const {
    return queue.size();
}
template <class T>
bool Queue<T>::isEmpty() const {
    return size() == 0;
}