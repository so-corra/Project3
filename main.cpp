#include <iostream>
#include <stdexcept>
using std::runtime_error;
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;

    // Helper functions for recursive operations
    BSTNode* insert(BSTNode* node, int value);
    bool search(BSTNode* node, int value);
    BSTNode* delete(BSTNode* node, int value);
    BSTNode* findMin(BSTNode* node);
    BSTNode* findMax(BSTNode* node);
    void in_order(BSTNode* node) const;
    void pre_order(BSTNode* node) const;
    void post_order(BSTNode* node) const;
    void level_order(BSTNode* node) const;
    int size(BSTNode* node) const;
public:
    BST() : root(nullptr) {}
    ~BST(){};

    // public methods
    void insert(int value); // adds an item to its proper location in a binary search tree. Note that duplicates should not be stored and an error message should be displayed if duplicate value is found in BST. Any invalid data should throw an exception and be handled properly
    bool search(int value); // search for the target value in the BST, returns true if found, false otherwise
    void delete(int value); // remove the node with the target value from the BST if found. The BST should remain connected

    // tree traversals
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;
    void displayLevelOrder() const;

    // additional public functions
    int count() const {return size(root);}; // returns the total number of nodes in the BST
    int height() const; // this method should have no parameters and return an integer representing the height of the tree
    int getMin() const; // returns the node with the minimum value in the BST
    int getMax() const; // returns the node with the maximum value in the BST
    bool isComplete() const; // returns true if the BST is complete, false otherwise
    void display() const; // BONUS
    // this displays the tree in a nicely aligned fashion similar to the tree below. You need the alignment to work correctly only for input of type char. The tree should be nicely aligned up to a height of at least four (the tree below has height h = 2). Note that it is acceptable to have widely-spaced nodes at upper-levels of the tree, even if the height is only one or two

};

/* Issues for Tony:
 * display() is marked as bonus but written as required to be implemented in Specifications and then marked as bonus again in the rubric
 * the tree traversals aren't required in the Specifications but are marked as being worth 20 points in the rubric
 * git repo is a bonus
 */

int main() {






    return 0;
}
