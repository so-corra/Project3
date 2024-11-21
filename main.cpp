/**
 * Assignment: Project3
 * Author(s): Socorra McLaughlin
 * Due Date: 11/20/2024 11:59pm
 * Description: WRITE HERE
 * Comments: WRITE HERE
 * Honor Pledge: I have abided by the Wheaton Honor Code and all work below was performed by Socorra McLaughlin
 */

#include <iostream>
#include <stdexcept>
#include "BST.h"
using std::runtime_error;
using namespace std;


void test_constructor() {

    // explicit call
    BST();

    // creating object
    BST testTree;

}

void test_destructor() {
    // calling destructor on an explicit call and an object
    test_constructor();

    // making another object with same name as deleted object which will be deleted after test func ends
    BST testTree;

    // new object will have contents to test deletion of contents
    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
}

void test_insert() {

    BST testTree;
    testTree.insert(5);
    testTree.displayPostOrder();
    testTree.insert(3);
    testTree.displayPostOrder();
    testTree.insert(4); // leaf
    testTree.displayPostOrder();
    testTree.insert(2); // leaf
    testTree.displayPostOrder();
    testTree.insert(7);
    testTree.displayPostOrder();
    testTree.insert(6); // leaf
    testTree.displayPostOrder();
    testTree.insert(8); // leaf
    testTree.displayPostOrder();
    // 2 4 3 6 8 7 5



    // duplicate test for node
    try {
        testTree.insert(7);
        cout << "uh oh, dupe didn't throw error" << endl;
    }
    catch (runtime_error) {
        cout << "yay, dupe threw error" << endl;
    }

    // duplicate test for leaf node
    try {
        testTree.insert(8);
        cout << "uh oh, dupe didn't throw error" << endl;
    }
    catch (runtime_error) {
        cout << "yay, dupe threw error" << endl;
    }

    // duplicate test for root
    try {
        testTree.insert(5);
        cout << "uh oh, dupe didn't throw error" << endl;
    }
    catch (runtime_error) {
        cout << "yay, dupe threw error" << endl;
    }

    // adding nodes that have been previously removed
    testTree.remove(5);
    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    testTree.displayPostOrder();
    // 2 4 3 6 8 7 5
}

void test_search() {
    BST testTree;

    // empty tree test, should be false
    cout << testTree.search(5) << endl;

    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf

    // successful searches for node, root, and leaf. all true
    cout << testTree.search(7) << endl;
    cout << testTree.search(5) << endl;
    cout << testTree.search(2) << endl;

    // false search for node that isn't there
    cout << testTree.search(10) << endl;

}

void test_remove() {
    BST testTree;

    // empty tree, target will not be found so nothing happens
    testTree.remove(5);

    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    testTree.displayPostOrder();
    // 2 4 3 6 8 7 5

    // remove leaf
    testTree.remove(6);
    testTree.displayPostOrder();
    // 2 4 3 8 7 5

    // remove parent of leaf (which still has another child)
    testTree.remove(7);
    testTree.displayPostOrder();
    // 2 4 3 5

    // remove root
    testTree.remove(5);
    testTree.displayPostOrder();
    // nothing
}

void test_displayInOrder() {}

void test_displayPrOrder() {}

void test_displayPostOrder() {}

void test_displayLevelOrder() {}

void test_count() {}

void test_height() {}

void test_getMin() {}

void test_getMax() {}

void test_isComplete() {}


int main() {

    test_constructor();

    test_destructor();

    test_insert();

    test_search();

    test_remove();

    test_displayInOrder();

    test_displayPrOrder();

    test_displayPostOrder();

    test_displayLevelOrder();

    test_count();

    test_height();

    test_getMin();

    test_getMax();

    test_isComplete();




    return 0;
}
