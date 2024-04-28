#include "LinkedList.h"
#include <deepstate/DeepState.hpp>
#include<iostream>
using namespace deepstate;
using namespace std;
TEST(LinkedList, TestAllScenarios) {
    LinkedList list;

    // Test insertAtBeginning
    for (int val = 1; val <= 10; ++val) {
        list.insertAtBeginning(val);
        CHECK(list.head != nullptr);
        CHECK(list.head->data == val);
    }
    cout<<"Done test1"<<endl;
    // Test insertAtEnd
    for (int val = 11; val <= 20; ++val) {
        list.insertAtEnd(val);
        CHECK(list.tail != nullptr);
        CHECK(list.tail->data == val);
    }
        cout<<"Done test2"<<endl;

    // Test insertAtPosition
    for (int val = 21; val <= 30; ++val) {
        int previous_size = list_size();
        for (int position = 0; position <= previous_size; ++position) {
            list.insertAtPosition(val, position);
            Node* current = list.get(position)
            CHECK(current->data == val);
        }
    }
    cout<<"Done test3"<<endl;

    // Test deleteAtBeginning
    for (int val = 1; val <= 10; ++val) {
        list.deleteAtBeginning();
        CHECK(list.head == nullptr || list.head->data != val);
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
