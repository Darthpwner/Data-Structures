//
//  main.cpp
//  Trees
//
//  Created by Matthew Allen Lin on 1/25/16.
//  Copyright © 2016 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>

const int TREE_SIZE = 100;

struct Tree {
public:
    Tree();
    void insert(Tree tn);
private:
    int item;   //The data in the node
    Tree* x;
};

struct BinaryTree: public Tree {
public:

private:
    Tree* left; //Pointer to the left subtree
    Tree* right;    //Pointer ot the right subtree
};

Tree::Tree() {
    x = new Tree[TREE_SIZE];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Tree tn;

}
