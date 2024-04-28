// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList();
    ~LinkedList();

    // Insertion operations
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int val, int position);
    int size();
    Node* get(int position);
    // Deletion operations
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteAtPosition(int position);

    // Traversal
    void display();
};

#endif
