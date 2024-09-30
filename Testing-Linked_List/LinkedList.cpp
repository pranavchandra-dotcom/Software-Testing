#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int LinkedList::size() {
    int count = 0;
    Node* current = head;
    while (current!= nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

Node* LinkedList::get(int position) {
    Node* current = head;
    for (int i = 0; i < position && current!= nullptr; i++) {
        current = current->next;
    }
    return current;
}

void LinkedList::insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode; // Update tail
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode; // Update tail
    }
}

void LinkedList::insertAtPosition(int val, int position) {
    if (position < 0) return;

    if (position == 0) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode = new Node(val);
    Node* current = head;
    Node* prev = nullptr;
    for (int i = 0; i < position && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        // Position is beyond the end of the list
        if (prev != nullptr) {
            prev->next = newNode; // Insert at the end
            tail = newNode; // Update tail
        } else {
            head = newNode; // Update head if list is empty
            tail = newNode; // Update tail
        }
        return;
    }

    newNode->next = current;
    if (prev != nullptr) {
        prev->next = newNode;
    } else {
        head = newNode; // Update head if inserting at the beginning
    }
}

void LinkedList::deleteAtBeginning() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) // If list is empty after deletion
        tail = nullptr; // Update tail
}

void LinkedList::deleteAtEnd() {
    if (head == nullptr) return;

    // If there's only one node in the list
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr; // Update tail
        return;
    }

    // Traverse to the second-to-last node
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    // Delete the last node
    delete current->next;
    current->next = nullptr;
    tail = current; // Update tail
}

void LinkedList::deleteAtPosition(int position) {
    if (position < 0 || head == nullptr) return;

    if (position == 0) {
        deleteAtBeginning();
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    for (int i = 0; i < position && current->next != nullptr; i++) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) return;

    if (prev != nullptr) {
        prev->next = current->next;
    } else {
        head = current->next; // Update head if deleting the first node
    }
    delete current;

    if (prev == nullptr) // If head was deleted
        tail = nullptr;
    else if (prev->next == nullptr) // If tail was deleted
        tail = prev;
}