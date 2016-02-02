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
    void addItem(string newItem);
    void deleteItem(string v);
    bool findItem(string v);
    void printItems();
    ~SinglyLinkedList();
    
    //Additional functions
    void reverse();
    
protected:
    Node* head;
};

class SinglyLinkedListWithTail: public SinglyLinkedList {   //Derived class of SinglyLinkedList
public:
    SinglyLinkedListWithTail();
    void addToFront(string v);
    void addToRear(string v);
    void deleteItem(string v);
    ~SinglyLinkedListWithTail();
    void reverse();

private:
    Node* tail;
};

class DoublyLinkedList: public SinglyLinkedList {   //Derived class of SinglyLinkedList
        //TODO
};

class DoublyLinkedListWithTail: public SinglyLinkedListWithTail {   //Derived class of SinglyLinkedListWithTail
    
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

void SinglyLinkedList::addItem(string newItem) {
    //If our linked list is empty, use our addToFront code
    if (head == nullptr) {
        addToFront(newItem);
    }
    
    //else if our new node belongs at the top of the list, use addToFront still!
    else if (newItem < head -> value) {
        addToFront(newItem);
    }
 
    //New Node belongs somewhere in the middle of the list
    else {
        //Use a traversal loop to find the node just ABOVE where you want to insert our new item
        Node* p = head; //Start with the first node
        while (p -> next != nullptr) {
            if (newItem >= p -> value && newItem <= p -> next -> value)
                break;
        }
        
        //Allocate and fill our new node with the item
        Node* latest = new Node;
        latest -> value = newItem;
        
        //Link the new node into the list right after the ABOVE node
        latest -> next = p -> next; //Link new node to the node below
        p -> next = latest; //Link above node to our new node
        //Order of above two lines MATTERS
    }
}

void SinglyLinkedList::deleteItem(string v) {
    //If the list is empty, return
    if(head == nullptr) return;
    
    //If the first node holds the item we wish to delete then
    if(head->value == v) {
        //killMe = address of top node
        Node* killMe = head;
        
        //Update head to point to the second node in the list
        head = killMe -> next;
        
        //Delete our target node
        delete killMe;
        
        //Return - we're done
        return;
    }
    
    Node* p = head;
    while (p != nullptr) {
        if (p -> next != nullptr && p -> next -> value == v) {
            break;  //p points to node above
        }
        p = p -> next;
    } if (p != nullptr) {   //We found our value!
        Node* killMe = p -> next;
        p -> next = killMe -> next;
        delete killMe;
    }
}

bool SinglyLinkedList::findItem(string v) {
    Node* p = head;
    while (p != nullptr) {
        if(p -> value == v) //Compare Node's value to the argument v
            return true;
        p = p -> next;  //Iterate to the next Node
    }
    return false;   //Return false if you did not find anything after iterating through the list
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
    Node* p;
    p = head;
    while (p != nullptr) {
        Node* n = p -> next;
        delete p;
        p = n;
    }
}

//Matthew's algorithm for reverse
void SinglyLinkedList::reverse() {
    Node* p;
    Node* temp;
    p = head;
    temp = nullptr;
    
    if(p == nullptr || p -> next == nullptr) {  //Leave a linked list alone if it has 0 or 1 item
        return;
    }
    
    while(p != nullptr) {
        p = p -> next;  //Move p to next node
        head -> next = temp;
        temp = head;
        head = p;
    }
    
    head = temp;    //Reset because it goes out of bounds
}

SinglyLinkedListWithTail::SinglyLinkedListWithTail() {
    head = nullptr; //Initialize your head to be the first AND last node
    tail = head;    //Initialize your tail to head
}

void SinglyLinkedListWithTail::addToFront(string v) {
    SinglyLinkedList::addToFront(v);
    if(head == nullptr) {
        tail = head;
    }
}

void SinglyLinkedListWithTail::addToRear(string v) {
    if(head == nullptr) {
        addToFront(v);
        tail = head;
    } else {
        Node *n = new Node;
        n -> value = v;
        tail -> next = n;
        n -> next = nullptr;
        tail = n;
    }
}

void SinglyLinkedListWithTail::deleteItem(string v) {
    //If the list is empty, return
    if(head == nullptr) return;
    
    //If the first node holds the item we wish to delete then
    if(head->value == v) {
        //killMe = address of top node
        Node* killMe = head;
        
        //Update head to point to the second node in the list
        head = killMe -> next;
        
        if(tail == killMe) {
            tail = tail -> next;
        }
        
        //Delete our target node
        delete killMe;
        
        //Return - we're done
        return;
    }
    
    Node* p = head;
    while (p != tail -> next) {
        if (p -> next != tail -> next && p -> next -> value == v) {
            break;  //p points to node above
        }
        p = p -> next;
    } if (p != tail -> next) {   //We found our value!
        Node* killMe = p -> next;
        p -> next = killMe -> next;
        if(killMe == tail) {
            tail = p;
        }
        delete killMe;
    }
}

SinglyLinkedListWithTail::~SinglyLinkedListWithTail() {
    
}

void SinglyLinkedListWithTail::reverse() {
    Node* p;
    Node* temp;
    p = head;
    tail = head;
    temp = nullptr;
    
    if(p == nullptr || p -> next == nullptr) {  //Leave a linked list alone if it has 0 or 1 item
        return;
    }
    
    while(p != nullptr) {
        p = p -> next;  //Move p to next node
        head -> next = temp;
        temp = head;
        head = p;
    }
    
    head = temp;    //Reset because it goes out of bounds
}



int main(int argc, const char * argv[]) {
    
    SinglyLinkedListWithTail linkedListWithTail;
    
    linkedListWithTail.addToRear("Novak");
    linkedListWithTail.deleteItem("Novak");
    
    linkedListWithTail.addToRear("Roger");
    linkedListWithTail.addToRear("Rafa");
 
    linkedListWithTail.printItems();
    cout << endl;
    
    linkedListWithTail.reverse();
    
    linkedListWithTail.printItems();
    cout << endl;
    
    linkedListWithTail.deleteItem("Rafa");

    SinglyLinkedList orderedLinkedList;
    
    orderedLinkedList.addItem("Wendy");
    orderedLinkedList.addItem("Matthew");
    orderedLinkedList.addItem("Ranee");
    orderedLinkedList.addItem("Amanda");
    orderedLinkedList.addItem("Christine");
    orderedLinkedList.printItems(); //Prints in order
    
    cout << endl;
    
    orderedLinkedList.reverse();
    orderedLinkedList.printItems();
    
    cout << endl;
    
    SinglyLinkedList linkedList;
    linkedList.addToFront("Christine");
    linkedList.addToRear("Matthew");
    linkedList.addToRear("Wendy");
    linkedList.addToFront("Ranee");
    
    linkedList.printItems();
    
    linkedList.addItem("Amanda");
    
    cout << endl;
    
    linkedList.printItems();
//    linkedList.addItem("Mandy");
//    
    cout << endl;
    
    linkedList.reverse();
    linkedList.printItems();
    
    cout << endl;
    
    linkedList.deleteItem("Matthew");
    
    linkedList.printItems();
    
    
    //linkedList.addItem("Kelly");
    //linkedList.addItem("Michelle");
    
    //linkedList.printItems();
    return 0;
}
