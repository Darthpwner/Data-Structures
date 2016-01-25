//
//  main.cpp
//  Trees
//
//  Created by Matthew Allen Lin on 1/25/16.
//  Copyright © 2016 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>

using namespace std;

const int TREE_SIZE = 100;

struct Tree {
public:
    Tree();
    void insert(Tree tn);
private:
    int item;   //Node
    Tree* x;
};

struct BinaryTree: public Tree {
public:
    BinaryTree();
    BinaryTree(int value);
    void insert(BinaryTree* parent, int value);
    
    int item;   //Node
    BinaryTree* root;
    BinaryTree* left; //Pointer to the left subtree
    BinaryTree* right;    //Pointer ot the right subtree
};

Tree::Tree() {
//    x = new Tree[TREE_SIZE];
}

BinaryTree::BinaryTree() {
    
}

BinaryTree::BinaryTree(int value) {
    root = new BinaryTree;
    root -> item = value;
    root -> left = NULL;
    root -> right = NULL;
}

//BinaryTree by default is left child oriented
void BinaryTree::insert(BinaryTree* parent, int value) {
    if(parent -> left != NULL && parent -> right != NULL) {
        cout << "Could not insert a child\n";
        return;
    }
    
    BinaryTree *child;
    child = new BinaryTree;
    child -> item = value;
    child -> left = NULL;
    child -> right = NULL;
    
    if (parent -> left == NULL) {
        parent -> left = child;
    } else {
        parent -> right = child;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTree bt(5);
    
    bt.insert(bt.root, 7);
    bt.insert(bt.root, 9);
    bt.insert(bt.root, 11); //Should display error
}
