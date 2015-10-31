//
//  main.cpp
//  Stack
//
//  Created by Matthew Allen Lin on 10/31/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;

class Stack {   //Stack of ints
public:
    Stack();    //c'tor
    ~Stack();   //d'tor
    void push(int i);
    int pop();
    bool is_empty() const;
    int top() const;
private:
    int m_stack[SIZE];
    int m_top;
};

Stack::Stack() {
    m_top = 0;
}

Stack::~Stack() {
    
}

void Stack::push(int i) {
    if (m_top >= SIZE) return;  //Overflow
    m_stack[m_top] = i;
    m_top++;
}

int Stack::pop() {
    if(m_top == 0) return -1;   //Underflow
    m_top--;
    return m_stack[m_top];
}

bool Stack::is_empty() const {
    if(m_top == 0) return true;
    return false;
}

int Stack::top() const {
    return m_stack[m_top];
}

void printTop(const Stack& c) {
    cout << c.top() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Stack s;
    s.push(1);
    printTop(s);
    
    s.push(2);
    printTop(s);
    
    s.push(3);
    printTop(s);
    
    return 0;
}
