//
// Created by polyt on 11/19/2024.
//

#include <iostream>
#include <stdexcept>
#include <queue>
#include "BST.h"
using std::runtime_error;
using namespace std;
/* =====================================================================
            RECURSIVE HELPERS
===================================================================== */

// adds an item to its proper location in a binary search tree. Note that duplicates should not be stored and an error message should be displayed if duplicate value is found in BST. Any invalid data should throw an exception and be handled properly
BSTNode *BST::insert(BSTNode *node, int value) {
    // base case, we have arrived at an empty spot to put it
    if (node == nullptr) {
        node = new BSTNode(value);
    }
    // duplicate case, do nothing and end early
    else if (node->data == value) {
        return node; // does not alter pointer to this dupe node
    }
    // go left, current node is greater than new node
    else if (node->data > value) {
        node->left = insert(node->left, value);
    }
    // go right, current node is lesser than new node
    else if (node->data < value) {
        node->right = insert(node->right, value);
    }

    // if we have reached this point we have created a new node using base case
    // thus we need to have previous node point to it
    return node;
}

// search for the target value in the BST, returns true if found, false otherwise
bool BST::search(BSTNode *node, int value) {
    // root is nullptr or we've found where the value should be and it isn't there
    if (node == nullptr) {
        return false;
    }
    // base case, value found!
    else if (node->data == value) {
        return true;
    }
    // value should be to the left
    else if (node->data > value) {
        return search(node->left, value);
    }
    // value should be to the right
    else if (node->data < value) {
        return search(node->right, value);
    }

    // this line should never run but just in case
    throw runtime_error("search() broke");
}

// remove the node with the target value from the BST if found. The BST should remain connected
// DELETE GOES HERE

// returns the node with the minimum value in the BST
BSTNode *BST::findMin(BSTNode *node) {
    // in a sorted BST the min is the leftmost node

    // base case, end of the line
    if (node->left == nullptr) {
        return node;
    }
    // there is a node to the left, continue
    else {
        return findMin(node->left);
    }
}

// returns the node with the maximum value in the BST
BSTNode *BST::findMax(BSTNode *node) {
    // in a sorted BST the min is the rightmost node

    // base case, end of the line
    if (node->right == nullptr) {
        return node;
    }
    // there is a node to the right, continue
    else {
        return findMax(node->right);
    }
}

void BST::in_order(BSTNode *node) const {

}

void BST::pre_order(BSTNode *node) const {

}

void BST::post_order(BSTNode *node) const {

}

void BST::level_order(BSTNode *node) const {
    // LITERALLY NOT POSSIBLE
}

// returns the total number of nodes in the BST
int BST::size(BSTNode *node) const {
    // dead ends are zeros
    if (node == nullptr) {
        return 0;
    }

    // if we aren't a dead end, add one
    // size = allLeft + allRight + me
    return (size(node->left) + size(node->right) + 1);
}


/* =====================================================================
            PUBLIC METHODS
===================================================================== */
// adds an item to its proper location in a binary search tree. Note that duplicates should not be stored and an error message should be displayed if duplicate value is found in BST. Any invalid data should throw an exception and be handled properly
void BST::insert(int value) {
    insert(root, value);
}

// search for the target value in the BST, returns true if found, false otherwise
bool BST::search(int value) {
    return search(root, value);
}

// remove the node with the target value from the BST if found. The BST should remain connected
// DELETE GOES HERE

void BST::displayInOrder() const {

}

void BST::displayPreOrder() const {

}

void BST::displayPostOrder() const {

}

void BST::displayLevelOrder() const {

}

// this method should have no parameters and return an integer representing the height of the tree
int BST::height() const {
    // check for empty tree
    if (root == nullptr) {
        throw runtime_error("Cannot check height() of empty tree");
    }

    // start at -1 because there is at least a root node therefore while loop will always add 1 for a height of 0 when there is only one node
    int heightToReturn = -1;
    // make queue and put root in it
    queue<BSTNode*> nodesQueue;
    nodesQueue.push(root);

    // loop by level
    while (!nodesQueue.empty()) {
        // not empty, there is a level to handle
        heightToReturn++;

        // handle the level
        // for loop changes size with pop() push() so get it beforehand
        int currentLevelSize = nodesQueue.size();
        // for each node in the current level, add its children and then remove it
        for (int i = 0; i < currentLevelSize; i++) {
            // add left child if it exists
            if (nodesQueue.front()->left != nullptr) {
                nodesQueue.push(nodesQueue.front()->left);
            }
            // add right child if it exists
            if (nodesQueue.front()->right != nullptr) {
                nodesQueue.push(nodesQueue.front()->right);
            }
            // remove node
            nodesQueue.pop();
        }
    }

    return heightToReturn;
}

// returns the node with the minimum value in the BST
int BST::getMin() const {
    // cannot be run on empty tree, throw error
    if (root == nullptr) {
        throw runtime_error("cannot getMin() on empty tree");
    }

    // otherwise, return data of min
    return findMin(root)->value;
}

// returns the node with the maximum value in the BST
int BST::getMax() const {
    // cannot be run on empty tree, throw error
    if (root == nullptr) {
        throw runtime_error("cannot getMax() on empty tree");
    }

    // otherwise, return data of max
    return findMax(root)->value;
}

// returns true if the BST is complete, false otherwise
bool BST::isComplete() const {
    // get height
    // calculate max nodes using height
    // compare to existing number of nodes using size
    return false;
}

// this displays the tree in a nicely aligned fashion similar to the tree below. You need the alignment to work correctly only for input of type char. The tree should be nicely aligned up to a height of at least four (the tree below has height h = 2). Note that it is acceptable to have widely-spaced nodes at upper-levels of the tree, even if the height is only one or two
void BST::display() const {

}
