#include "LinkedList.h"
#include <deepstate/DeepState.hpp>
#include<iostream>
using namespace deepstate;
using namespace std;
TEST(LinkedList, TestAllScenarios) {
    LinkedList list;

    // Test insertAtBeginning
    for (int val = 1; val <= 10; ++val) {
        int value = DeepState_IntInRange(1, 10);
        list.insertAtBeginning(value);
        CHECK(list.head != nullptr);
        CHECK(list.head->data == value);
    }
    cout<<"Done test1"<<endl;
    // Test insertAtEnd
    for (int val = 11; val <= 20; ++val) {
         int value = DeepState_IntInRange(11, 20);
        list.insertAtEnd(value);
        CHECK(list.tail != nullptr);
        CHECK(list.tail->data == value);
    }
        cout<<"Done test2"<<endl;

    // Test insertAtPosition
    for (int val = 21; val <= 30; ++val) {
        int value = DeepState_IntInRange(21, 30);
        int previous_size = list_size();
        for (int position = 0; position <= previous_size; ++position) {
            list.insertAtPosition(value, position);
            Node* current = list.get(position)
            CHECK(current->data == value);
        }
    }
    cout<<"Done test3"<<endl;

    // Test deleteAtBeginning
    for (int val = 1; val <= 10; ++val) {
        Node* previous = list.head;
        list.deleteAtBeginning();
        CHECK(list.head == nullptr || list.head->data != previous->data);
    }
    cout<<"Done test4"<<endl;

    // Test deleteAtEnd
    for (int val = 11; val <= 20; ++val) {
        Node* current = list.tail;
        list.deleteAtEnd();
        CHECK(list.tail->data != current->data);
    }
    cout<<"Done test5"<<endl;

    // Test deleteAtPosition
    for (int val = 21; val <= 30; ++val) {
        int previous_size = list.size();
        for (int position = 0; position <= previous_size; ++position) {
            Node* previous = list.get(position);
            list.deleteAtPosition(position);
            Node* current = list.get(position);
            int previous_size = list.size();
            if(position < previous_size){
                current = list.get(position);
                CHECK(current != nullptr || current->data != previous->data);
            }
        }
    }
    cout<<"Done test6"<<endl;

    // Test empty list
    CHECK(list.head == nullptr);
    CHECK(list.tail == nullptr);
        cout<<"Done test7"<<endl;

}
