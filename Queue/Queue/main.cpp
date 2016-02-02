//
//  main.cpp
//  Queue
//
//  Created by Matthew Allen Lin on 2/1/16.
//  Copyright © 2016 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 100;

struct Node {
    //Data
    string value;
    
    Node *next;
};

class Queue {
public:
    
private:
    int x;
    int m_size;
};

class CircularQueue {
public:
    CircularQueue();
    void enqueue(int i);
    int dequeue();
    bool isEmpty();
    int size();
    int getFront();
    
private:
    int m_array[SIZE];
    int m_head;
    int m_tail;
    int m_count;
};

CircularQueue::CircularQueue() {
    m_count = m_head = m_tail = 0;
}

void CircularQueue::enqueue(int i) {
    if(m_count >= SIZE) {
        cout << "Cannot enqueue a full queue\n";
        return;
    }
    
    m_array[m_tail] = i;
    if(m_tail == SIZE - 1) {
        m_tail = 0;
    } else {
        m_tail++;
    }
    
    m_count++;
}

int CircularQueue::dequeue() {
    if(m_count <= 0) {
        cout << "Cannot dequeue an empty queue\n";
        return -1;
    }
    
    int getHead = m_head;
    if(m_head == SIZE - 1) {
        m_head = 0;
    } else {
        m_head++;
    }
    
    m_count--;
    return m_array[getHead];
}

bool CircularQueue::isEmpty() {
    return m_count == 0 ? true : false;
}

int CircularQueue::size() {
    return m_count;
}

int CircularQueue::getFront() {
    return m_array[m_head];
}

int main(int argc, const char * argv[]) {
    CircularQueue circularQueue;
    circularQueue.enqueue(69);
    cout << circularQueue.isEmpty() << endl;
    cout << circularQueue.dequeue() << endl;
    cout << circularQueue.isEmpty() << endl;
    circularQueue.enqueue(32695);
    circularQueue.enqueue(101595);
    circularQueue.enqueue(2190);
    circularQueue.dequeue();
    cout << circularQueue.getFront() << endl;
}
