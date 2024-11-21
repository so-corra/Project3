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

/**
 * recursive helper function of insert() which searches the tree for the correct location for a new node of value and creates new node there
 * throws error if duplicate node found
 * @param node pointer to BSTNode which recursively goes left and right
 * @param value int to become the data of new node
 * @return pointer to previous BSTNode so that all nodes point to each other
 */
BSTNode *BST::insert(BSTNode *node, int value) {
    // base case, we have arrived at an empty spot to put it
    if (node == nullptr) {
        node = new BSTNode(value);
    }
    // duplicate case, throw error
    else if (node->data == value) {
        throw runtime_error("Cannot insert() node that already exists");
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

/**
 * recursive helper function of search() which uses target value to recursively go left and right in the tree until position where target node should be is reached
 * returns true if target is where it should be, false otherwise
 * the line that throws an error should never run but it is there
 * @param node pointer to BSTNode which recursively goes left and right
 * @param value int which should match target's data
 * @return bool true if target found, false otherwise
 */
bool BST::search(BSTNode *node, int value) {
    // root is nullptr or we've found where the value should be and it isn't there
    if (node == nullptr) {
        return false;
    }
    // value found!
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


/**
 * recursive helper function of remove() which uses target value to recursively go left and right in the tree until position where target node should be is reached
 * if target is where it should be its children will be removed recursively using remove() before it is deleted, does nothing if target not found
 * the line that throws an error should never run but it is there
 * @param node pointer to BSTNode which recursively goes left and right
 * @param value int which should match target's data
 * @return a nullptr to previous node which was pointing to a removed node or to signify the recursion can end
 */
BSTNode *BST::remove(BSTNode *node, int value) {
    // root is nullptr, target was found and killed, or target could not be found where it should've been
    if (node == nullptr) {
        return nullptr;
    }
    // value found! KILL
    else if (node->data == value) {
        // before removal, recursively remove all children
        if (node->left != nullptr) {
            remove(node->left, node->data);
        }
        if (node->right != nullptr) {
            remove(node->right, node->data);
        }
        // remove a node
        delete node;
        // set up for base case
        return nullptr;
    }
    // value should be to the left
    else if (node->data > value) {
        return remove(node->left, value);
    }
    // value should be to the right
    else if (node->data < value) {
        return remove(node->right, value);
    }

    // this line should never run but just in case
    throw runtime_error("delete() broke");
}

/**
 * recursive helper function of getMin() which recursively goes as far left as possible to return a pointer to that node, the minimum node
 * @param node pointer to BSTNode which recursively goes left
 * @return pointer to the leftmost node
 */
BSTNode * BST::findMin(BSTNode *node) const {
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

/**
 * recursive helper function of getMax() which recursively goes as far right as possible to return a pointer to that node, the maximum node
 * @param node pointer to BSTNode which recursively goes right
 * @return pointer to the rightmost node
 */
BSTNode * BST::findMax(BSTNode *node) const {
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

/**
 * recursive helper function of displayInOrder() which recursively calls itself left, then prints data, then recursively calls itself right
 * @param node pointer to current BSTNode during traversal
 */
void BST::in_order(BSTNode *node) const {
    if (node != nullptr) {
        in_order(node->left);
        cout << to_string(node->data) << " ";
        in_order(node->right);
    }
}

/**
 * recursive helper function of displayPreOrder() which prints data, then recursively calls itself left, then recursively calls itself right
 * @param node pointer to current BSTNode during traversal
 */
void BST::pre_order(BSTNode *node) const {
    if (node != nullptr) {
        cout << to_string(node->data) << " ";
        in_order(node->left);
        in_order(node->right);
    }
}

/**
 * recursive helper function of displayPostOrder() which recursively calls itself left, then recursively calls itself right, then prints data
 * @param node pointer to current BSTNode during traversal
 */
void BST::post_order(BSTNode *node) const {
    if (node != nullptr) {
        in_order(node->left);
        in_order(node->right);
        cout << to_string(node->data) << " ";
    }
}

/**
 * recursive helper function of count() which will return the size of any subtree stemming from the given node
 * member function count() isn't implemented in this file so this is the only place where I can note that size() is its dependency
 * @param node pointer to BSTNode which recursively goes left and right
 * @return int which recursively increases to represent size of tree
 */
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

/**
 * destructor for Binary Search Tree which calls remove() on the root to recursively delete every node below it
 * dependencies: recursive helper remove()
 */
BST::~BST() {
    // removes all children before root and then root
    remove(root, root->data);
}

/**
 * calls recursive helper insert() on the root to kick off insertion of new node with data matching the value parameter
 * @param value int which is to become the data of a new node
 * dependencies: recursive helper insert() which can throw error
 */
void BST::insert(int value) {
    insert(root, value);
}

/**
 * calls recursive helper search() on the root to kick off search for a node with data matching target value parameter
 * @param value int represents the data of the target node
 * @return bool true if target found, false otherwise
 * dependencies: recursive helper search()
 */
bool BST::search(int value) {
    return search(root, value);
}

/**
 * calls recursive helper remove() on the root to kick off search for a node with data matching target value parameter
 * if found, target node and all of its children will be recursively deleted such that no node points to them and memory is freed
 * @param value int represents the data of the target node
 * dependencies: recursive helper remove()
 */
void BST::remove(int value) {
    remove(root, value);
}

/**
 * calls recursive helper in_order() on the root to kick off in-order printing of the tree
 * dependencies: recursive helper in_order()
 */
void BST::displayInOrder() const {
    in_order(root);
    cout << endl;
}

/**
 * calls recursive helper pre_order() on the root to kick off pre-order printing of the tree
 * dependencies: recursive helper pre_order()
 */
void BST::displayPreOrder() const {
    pre_order(root);
    cout << endl;
}

/**
 * calls recursive helper post_order() on the root to kick off post-order printing of the tree
 * dependencies: recursive helper post_order()
 */
void BST::displayPostOrder() const {
    post_order(root);
    cout << endl;
}

/**
 * iteratively prints the tree in level-order using a queue
 */
void BST::displayLevelOrder() const {
    // check for empty tree, print nothing and end
    if (root == nullptr) {
        cout << endl;
        return;
    }

    // make queue and put root in it
    queue<BSTNode*> nodesQueue;
    nodesQueue.push(root);

    // loop by level
    while (!nodesQueue.empty()) {
        // not empty, there is a level to handle

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
            // print node before removal
            cout << to_string(nodesQueue.front()->data) << " ";
            // remove node
            nodesQueue.pop();
        }
        // put next level on new line
        cout << endl;
    }
}

/**
 * iteratively increments a counter as levels of the tree are traversed in a manner matching the level-order queue-based implementation
 * throws an error if called on an empty tree
 * @return int height of the tree which will be 0 for a tree with only the root and increase by 1 for each level beyond that
 */
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

/**
 * calls recursive helper findMin() to kick off retrieval of a pointer to the min (leftmost) node from which its data is grabbed
 * throws an error if called on an empty tree
 * @return int which is the data of the min node
 * dependencies: recursive helper findMin()
 */
int BST::getMin() const {
    // cannot be run on empty tree, throw error
    if (root == nullptr) {
        throw runtime_error("cannot getMin() on empty tree");
    }

    // otherwise, return data of min
    return findMin(root)->data;
}

/**
 * calls recursive helper findMax() to kick off retrieval of a pointer to the max (rightmost) node from which its data is grabbed
 * throws an error if called on an empty tree
 * @return int which is the data of the max node
 * dependencies: recursive helper findMax()
 */
int BST::getMax() const {
    // cannot be run on empty tree, throw error
    if (root == nullptr) {
        throw runtime_error("cannot getMax() on empty tree");
    }

    // otherwise, return data of max
    return findMax(root)->data;
}

// returns true if the BST is complete, false otherwise

/**
 * iteratively increments a counter as levels of the tree are traversed in a manner matching the level-order queue-based implementation
 * throws an error if called on an empty tree
 * @return int height of the tree which will be 0 for a tree with only the root and increase by 1 for each level beyond that
 */

/**
 * iteratively tracks the absence of left nodes on current level and right nodes on the previous level as levels of the tree are traversed in a manner matching the level-order queue-based implementation
 * these tracked criteria are used to determine if the tree is complete or incomplete
 * @return bool true if tree is complete or empty, false otherwise
 */
bool BST::isComplete() const {
    // check for empty tree
    if (root == nullptr) {
        return true;
    }

    // make queue and put root in it
    queue<BSTNode*> nodesQueue;
    nodesQueue.push(root);
    bool lastLevelMissingRightChild = false;

    // loop by level
    while (!nodesQueue.empty()) {
        // not empty, there is a level to handle

        // handle the level
        // for loop changes size with pop() push() so get it beforehand
        int currentLevelSize = nodesQueue.size();
        // for each node in the current level, add its children and then remove it
        for (int i = 0; i < currentLevelSize; i++) {
            bool currentLevelMissingLeftChild = false;
            // add left child if it exists
            if (nodesQueue.front()->left != nullptr) {
                if (lastLevelMissingRightChild) {
                    return false;
                }
                nodesQueue.push(nodesQueue.front()->left);
            }
            else {
                currentLevelMissingLeftChild = true;
            }

            // add right child if it exists
            if (nodesQueue.front()->right != nullptr) {
                if (currentLevelMissingLeftChild) {
                    return false;
                }
                nodesQueue.push(nodesQueue.front()->right);
            }
            else {
                lastLevelMissingRightChild = true;
            }

            // remove node
            nodesQueue.pop();
        }
    }

    // if we make it through the whole thing without returning false it is true
    return true;
}