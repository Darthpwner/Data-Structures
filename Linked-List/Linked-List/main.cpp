//
//  main.cpp
//  Linked-List
//
//  Created by Matthew Allen Lin on 10/30/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Node {
    //Data
    string value;
    
    Node *next;
};

class SinglyLinkedList {
public:
    SinglyLinkedList();
    void addToFront(string v);
    void addToRear(string v);
    void deleteItem(string v);
    bool findItem(string v);
    void printItems();
    ~SinglyLinkedList();
    
    //Additional functions
    void reverse();
    
private:
    Node* head;
};

SinglyLinkedList::SinglyLinkedList() {
    head = nullptr; //Initialize your head to be the first AND last node
}

void SinglyLinkedList::addToFront(string v) {
    
}

void SinglyLinkedList::addToRear(string v) {
    
}

void SinglyLinkedList::deleteItem(string v) {
    
}

bool SinglyLinkedList::findItem(string v) {
    return false;
}

void SinglyLinkedList::printItems() {
    
}

SinglyLinkedList::~SinglyLinkedList() {
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
