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
    //Allocate a new node
    Node* p;
    p = new Node;
    
    //Put value v in the node
    p -> value = v;
    
    //ORDER OF THESE NEXT TWO STEPS MATTERS A LOT!
    //Link the new Node to the old top Node
    p -> next = head;
    
    //Link the head pointer to our new top Node
    head = p;
    
    //Code works for an empty linked list as well as a linked list with at least one Node
}

void SinglyLinkedList::addToRear(string v) {
    //If our linked list is empty, then use our addToFront() code
    if(head == nullptr) {
        addToFront(v);
    } else {
        //Use a temp variable to traverse to the current last node of the list
        Node* p;
        p = head;   //Start at top Node
        
        while(p -> next != nullptr) {   //Go to current last Node
            p = p -> next;
        }
        
        //Allocate a new node
        Node* n = new Node;
        
        //Put value v in the node
        n -> value = v;
        
        //Link the current last node to our new node
        p -> next = n;
        
        //Link the last node to nullptr
        n -> next = nullptr;
    }
}

void SinglyLinkedList::deleteItem(string v) {
    
}

bool SinglyLinkedList::findItem(string v) {
    return false;
}

void SinglyLinkedList::printItems() {
    Node* p;
    p = head;   //Start the iterator at the head
    
    while(p != nullptr) {
        cout << p->value << endl;
        p = p -> next;  //Traverses to the next Node in the Linked list
    }
}

SinglyLinkedList::~SinglyLinkedList() {
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
