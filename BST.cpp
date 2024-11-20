//
// Created by polyt on 11/19/2024.
//

#include "BST.h"

/* =====================================================================
            RECURSIVE HELPERS
===================================================================== */

// adds an item to its proper location in a binary search tree. Note that duplicates should not be stored and an error message should be displayed if duplicate value is found in BST. Any invalid data should throw an exception and be handled properly
BSTNode *BST::insert(BSTNode *node, int value) {
    return nullptr;
}

// search for the target value in the BST, returns true if found, false otherwise
bool BST::search(BSTNode *node, int value) {
    return false;
}

// remove the node with the target value from the BST if found. The BST should remain connected
// DELETE GOES HERE

// returns the node with the minimum value in the BST
BSTNode *BST::findMin(BSTNode *node) {
    return nullptr;
}

// returns the node with the maximum value in the BST
BSTNode *BST::findMax(BSTNode *node) {
    return nullptr;
}

void BST::in_order(BSTNode *node) const {

}

void BST::pre_order(BSTNode *node) const {

}

void BST::post_order(BSTNode *node) const {

}

void BST::level_order(BSTNode *node) const {

}

// returns the total number of nodes in the BST
int BST::size(BSTNode *node) const {
    return 0;
}


/* =====================================================================
            PUBLIC METHODS
===================================================================== */
// adds an item to its proper location in a binary search tree. Note that duplicates should not be stored and an error message should be displayed if duplicate value is found in BST. Any invalid data should throw an exception and be handled properly
void BST::insert(int value) {

}

// search for the target value in the BST, returns true if found, false otherwise
bool BST::search(int value) {
    return false;
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
    return 0;
}

// returns the node with the minimum value in the BST
int BST::getMin() const {
    return 0;
}

// returns the node with the maximum value in the BST
int BST::getMax() const {
    return 0;
}

// returns true if the BST is complete, false otherwise
bool BST::isComplete() const {
    return false;
}

// this displays the tree in a nicely aligned fashion similar to the tree below. You need the alignment to work correctly only for input of type char. The tree should be nicely aligned up to a height of at least four (the tree below has height h = 2). Note that it is acceptable to have widely-spaced nodes at upper-levels of the tree, even if the height is only one or two
void BST::display() const {

}
