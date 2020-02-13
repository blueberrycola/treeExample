#include "bst.h"
#include <iostream>
#include <queue>
using namespace std;
BinarySearchTree::BinarySearchTree(){
   root = nullptr;



}
bool passedRoot = false;
void BinarySearchTree::insert(const int &key, BinaryNode * & t) {
    if(t == nullptr) {
        t = new BinaryNode;
        t->data = key; 
        t->left=t->right=nullptr;

    } else if( key < t->data) {
        insert(key, t->left);
    } else if( key > t->data) {
        insert(key, t->right);
    }
}

void BinarySearchTree::levelorder(BinaryNode* t) {
    BinaryNode *root_copy = t;
    queue<BinaryNode*> node_queue;
    node_queue.push(t);
    //Display root
    cout << node_queue.front()->data;
    while(node_queue.size() != 0) {
        //Search left and right of front node
        if(node_queue.front()->left != nullptr) {
            node_queue.push(node_queue.front()->left);
        }
        if(node_queue.front()->right != nullptr) {
            node_queue.push(node_queue.front()->left);
        }
        //Pop root
        node_queue.pop();
        



    }
}
void BinarySearchTree::makeEmpty(BinaryNode * &t) {
    while(t == nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    cout << "The tree is empty!" << endl;
    
}