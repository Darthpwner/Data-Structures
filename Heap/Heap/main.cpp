//
//  main.cpp
//  Heap
//
//  Created by Matthew Allen Lin on 12/15/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>

using namespace std;

#define N 1000

class Heap {
public:
    Heap();
    int getRootIndex();
    int leftChildLocator(int i);
    int rightChildLocator(int i);
    int parentLocator(int i);
    void printVal(int i);
    void printHeap();
    void addNode(int v);
private:
    int m_count = 0;
    int m_heap[N];
};

int main(int argc, const char * argv[]) {
    Heap h;
    h.addNode(5);
    h.addNode(20);
    h.addNode(9);
    h.addNode(2);
    h.printVal(0);
    
    h.printHeap();
    
    return 0;
}

Heap::Heap() {
    
}

int Heap::getRootIndex() {
    return 0;
}

int Heap::leftChildLocator(int i) {
    return (2 * i + 1);
}

int Heap::rightChildLocator(int i) {
    return (2 * i + 2);
}

int Heap::parentLocator(int i) {
    return ((i - 1)/2);
}

void Heap::printVal(int i) {
    cout << m_heap[i] << endl;
}

void Heap::printHeap() {
    for(int i = 0; i < m_count; i++) {
        cout << m_heap[i] << " ";
    }
    cout << endl;
}

void Heap::addNode(int v) {
    m_heap[m_count] = v;
    m_count++;
}