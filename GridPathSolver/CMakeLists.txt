cmake_minimum_required(VERSION 3.27)
project(Assignment2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment2 main.cpp
        DoublyLinkedList.h
        DoublyLinkedListException.cpp
        DoublyLinkedListException.h
        Queue.h
        Stack.h
        Cell.h
        Cell.cpp
        Map.h
        Map.cpp
        MapException.cpp
        MapException.h
        Tracker.h
        Tracker.cpp)
