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
    void swap(int& a, int& b);
protected:
    int m_count = 0;
    int m_heap[N];
};

class Minheap: public Heap {
public:
    Minheap();
    virtual void addNode(int v);
    int extractMin();
};

class Maxheap: public Heap {
public:
    Maxheap();
    virtual void addNode(int v);
    int extractMax();
};

int main(int argc, const char * argv[]) {
    Heap h;
    h.addNode(5);
    h.addNode(20);
    h.addNode(9);
    h.addNode(2);
    h.printVal(0);
    
    h.printHeap();
    
    h.printVal(h.leftChildLocator(0));
    h.printVal(h.leftChildLocator(5));
    
    h.printVal(h.rightChildLocator(0));
    
    Minheap mh;
    mh.addNode(5);
    mh.addNode(2);
    mh.addNode(1);
    mh.addNode(4);
    mh.addNode(-2423);
    mh.addNode(12312);
    mh.addNode(69);
    mh.addNode(23423);
    
    mh.printHeap(); //1 2 4 5
    
    mh.extractMin();
    
    mh.printHeap();
    
    Maxheap max;
    max.addNode(2);
    max.addNode(4);
    max.addNode(8);
    max.addNode(16);
    max.addNode(32);
    
    max.printHeap();
    max.extractMax();
    
    max.printHeap();
    
    return 0;
}

Heap::Heap() {
    
}

int Heap::getRootIndex() {
    return 0;
}

int Heap::leftChildLocator(int i) {
    if(i < m_count) {
        return (2 * i + 1);
    } else {
        //cout << "Error: ";
        return -1;
    }
}

int Heap::rightChildLocator(int i) {
    if(i < m_count) {
        return (2 * i + 2);
    } else {
        //cout << "Error: ";
        return -1;
    }
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

void Heap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*Minheap********/
Minheap::Minheap() {
    for(int i = 0; i < N; i++) {
        m_heap[i] = numeric_limits<int>::max();
    }
}

void Minheap::addNode(int v) {
    m_heap[m_count] = v;
    
    int i = m_count;
    while(m_heap[i] < m_heap[parentLocator(i)]) {
        swap(m_heap[i], m_heap[parentLocator(i)]);
        i = parentLocator(i);
    }
    
    m_count++;
}

int Minheap::extractMin() {
    //Extract root
    int extract = m_heap[0];
    
    //Copy bottom-most right-most to root
    m_heap[0] = m_heap[m_count - 1];
    m_heap[m_count - 1] = -1;
    m_count--;
    
    //Compare with children
    int i = 0;
    
    bool compareLeft = m_heap[i] > m_heap[leftChildLocator(i)];
    bool compareRight =  m_heap[i] > m_heap[rightChildLocator(i)];
    
    int left = m_heap[leftChildLocator(i)];
    int right = m_heap[rightChildLocator(i)];
    
    while((compareLeft || compareRight)) {  //FIX THIS SHIT IN THE MORNING
        if(left < right) {
            swap(m_heap[i], m_heap[leftChildLocator(i)]);
            i = leftChildLocator(i);
        } else {    //right < left
            swap(m_heap[i], m_heap[rightChildLocator(i)]);
            i = rightChildLocator(i);
        }
        
        compareLeft = m_heap[i] > m_heap[leftChildLocator(i)];
        compareRight =  m_heap[i] > m_heap[rightChildLocator(i)];
        
        left = m_heap[leftChildLocator(i)];
        right = m_heap[rightChildLocator(i)];
    }
    
    return extract;
}
/****************/

/*Maxheap********/
Maxheap::Maxheap() {
    for(int i = 0; i < N; i++) {
        m_heap[i] = numeric_limits<int>::min();
    }
}

void Maxheap::addNode(int v) {
    m_heap[m_count] = v;
    
    int i = m_count;
    while(m_heap[i] > m_heap[parentLocator(i)]) {
        swap(m_heap[i], m_heap[parentLocator(i)]);
        i = parentLocator(i);
    }
    
    m_count++;
}

int Maxheap::extractMax() {
    //Extract root
    int extract = m_heap[0];
    
    //Copy bottom-most right-most to root
    m_heap[0] = m_heap[m_count - 1];
    m_heap[m_count - 1] = -1;
    m_count--;
    
    //Compare with children
    int i = 0;

    bool compareLeft = m_heap[i] < m_heap[leftChildLocator(i)];
    bool compareRight =  m_heap[i] < m_heap[rightChildLocator(i)];
    
    int left = m_heap[leftChildLocator(i)];
    int right = m_heap[rightChildLocator(i)];
    
    while(compareLeft || compareRight) {    //FIX THIS SHIT IN THE MORNING
        if(left > right) {
            swap(m_heap[i], m_heap[leftChildLocator(i)]);
            i = leftChildLocator(i);
        } else {    //right > left
            swap(m_heap[i], m_heap[rightChildLocator(i)]);
            i = rightChildLocator(i);
        }
        
        compareLeft = m_heap[i] < m_heap[leftChildLocator(i)];
        compareRight =  m_heap[i] < m_heap[rightChildLocator(i)];
        
        left = m_heap[leftChildLocator(i)];
        right = m_heap[rightChildLocator(i)];
    }
    
    return extract;
}
/****************/