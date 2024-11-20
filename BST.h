//
// Created by polyt on 11/19/2024.
//

#ifndef PROJECT3_BST_H
#define PROJECT3_BST_H


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
    BSTNode* remove(BSTNode* node, int value);
    BSTNode * findMin(BSTNode* node) const;
    BSTNode * findMax(BSTNode* node) const;
    void in_order(BSTNode* node) const;
    void pre_order(BSTNode* node) const;
    void post_order(BSTNode* node) const;
    int size(BSTNode* node) const;
public:
    BST() : root(nullptr) {}
    ~BST(){};

    // public methods
    void insert(int value);
    bool search(int value);
    void remove(int value);

    // tree traversals
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;
    void displayLevelOrder() const;

    // additional public functions
    int count() const {return size(root);};
    int height() const;
    int getMin() const;
    int getMax() const;
    bool isComplete() const;

};

#endif //PROJECT3_BST_H
