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
    void preOrder(BinaryTree* cur);
    void inOrder(BinaryTree* cur);
    void postOrder(BinaryTree* cur);
    
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

void BinaryTree::preOrder(BinaryTree* cur) {
    if(cur == NULL) {   //If empty, return
        return;
    }
    
    cout << cur -> item << endl;    //Process the current node
    
    preOrder(cur -> left);  //Process nodes in left-subtree
    preOrder(cur -> right); //Process nodes in right-subtree
}

void BinaryTree::inOrder(BinaryTree* cur) {
    if(cur == NULL) {   //If empty, return
        return;
    }
    
    inOrder(cur -> left);   //Process nodes in left sub-tree
    
    cout << cur -> item << endl;    //Process the current node
    
    inOrder(cur -> right);  //Process nodes in right sub-tree
}

void BinaryTree::postOrder(BinaryTree* cur) {
    if(cur == NULL) {   //If empty, return
        return;
    }
    
    postOrder(cur -> left); //Process nodes in left sub-tree
    
    postOrder(cur -> right);    //Process nodes in right sub-tree
    
    cout << cur -> item << endl;    //Process the current node
}

int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTree bt(5);
    
    
    bt.insert(bt.root, 7);
    bt.insert(bt.root, 9);
    bt.insert(bt.root, 11); //Should display error
    
    bt.preOrder(bt.root);
    cout << endl;
    
    bt.inOrder(bt.root);
    cout << endl;
    
    bt.postOrder(bt.root);
    cout << endl;
}
