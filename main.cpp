/**
 * Assignment: Project3
 * Author(s): Socorra McLaughlin
 * Due Date: 11/20/2024 11:59pm
 * Description: A main driver in main.cpp which has test functions for all public methods of BST. A BST class with declarations in BST.h and definitions in BST.cpp. A README.txt file detailing the project date, authors project, date, authors, honor pledge, list of files, and dependencies, test plans for each test function, time complexities for each member function, and all major commits of my git log
 * Comments: Errors should be all accounted for in the form of detecting them and throwing them (always runtime errors)
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

void test_displayInOrder() {
    BST testTree;

    testTree.displayInOrder();
    // nothing it's empty

    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    testTree.displayInOrder();
    // 2 3 4 5 6 7 8

    // after changes made
    testTree.remove(7);
    testTree.displayInOrder();
    // 2 3 4 5
}

void test_displayPreOrder() {
    BST testTree;

    testTree.displayPreOrder();
    // nothing it's empty

    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    testTree.displayPreOrder();
    // 5 3 2 4 7 6 8

    // after changes made
    testTree.remove(7);
    testTree.displayPreOrder();
    // 5 3 2 4
}

void test_displayPostOrder() {
    BST testTree;

    testTree.displayPostOrder();
    // nothing it's empty

    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    testTree.displayPostOrder();
    // 2 4 3 6 8 7 5

    // after changes made
    testTree.remove(7);
    testTree.displayPostOrder();
    // 2 4 3 5
}

void test_displayLevelOrder() {
    BST testTree;

    testTree.displayLevelOrder();
    // nothing it's empty

    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    testTree.displayLevelOrder();
    // 5
    // 3 7
    // 2 4 6 8

    // after changes made
    testTree.remove(7);
    testTree.displayLevelOrder();
    // 5
    // 3
    // 2 4
}

void test_count() {
    BST testTree;

    cout << testTree.count() << endl;
    // 0

    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    cout << testTree.count() << endl;
    // 7

    // after changes made
    testTree.remove(7);
    cout << testTree.count() << endl;
    // 4
}

void test_height() {
    BST testTree;

    // error from calling on empty tree
    try {
        cout << testTree.height() << endl;
        cout << "uh oh, empty height() didn't throw error" << endl;
    }
    catch (runtime_error) {
        cout << "yay, empty height() threw error" << endl;
    }

    // one level
    testTree.insert(5);
    cout << testTree.height() << endl;
    // 0

    // two levels
    testTree.insert(3);
    cout << testTree.height() << endl;
    // 1

    // three levels
    testTree.insert(4); // leaf
    // 2

    // same number of levels but with more nodes and branches
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    cout << testTree.height() << endl;
    // 2

    // two levels removed
    testTree.remove(7);
    testTree.remove(3);
    cout << testTree.height() << endl;
    // 0
}

void test_getMin() {
    BST testTree;

    // error from calling on empty tree
    try {
        cout << testTree.getMin() << endl;
        cout << "uh oh, empty getMin() didn't throw error" << endl;
    }
    catch (runtime_error) {
        cout << "yay, empty getMin() threw error" << endl;
    }

    // one node, it is the min
    testTree.insert(5);
    cout << testTree.getMin() << endl;
    // 5

    // new node which is the new min
    testTree.insert(3);
    cout << testTree.getMin() << endl;
    // 3

    // new node which is not a new min
    testTree.insert(4); // leaf
    cout << testTree.getMin() << endl;
    // 3

    // tons of new nodes with one being a new min
    testTree.insert(2); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    cout << testTree.getMin() << endl;
    // 2

    // previous min removed
    testTree.remove(2);
    cout << testTree.getMin() << endl;
    // 3
}

void test_getMax() {
    BST testTree;

    // error from calling on empty tree
    try {
        cout << testTree.getMax() << endl;
        cout << "uh oh, empty getMax() didn't throw error" << endl;
    }
    catch (runtime_error) {
        cout << "yay, empty getMax() threw error" << endl;
    }

    // one node, it is the max
    testTree.insert(5);
    cout << testTree.getMax() << endl;
    // 5

    // new node which is not the new max
    testTree.insert(3);
    cout << testTree.getMax() << endl;
    // 5

    // new node which is the new max
    testTree.insert(7);
    cout << testTree.getMax() << endl;
    // 7

    // tons of new nodes with one being a new max
    testTree.insert(2); // leaf
    testTree.insert(4); // leaf
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    cout << testTree.getMax() << endl;
    // 8

    // previous max removed
    testTree.remove(8);
    cout << testTree.getMax() << endl;
    // 7
}

void test_isComplete() {
    BST testTree;

    // true bc it is on an empty tree
    cout << testTree.isComplete() << endl;
    // 1

    // creating an incomplete tree with 3 levels
    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4); // leaf
    testTree.insert(7);
    testTree.insert(6); // leaf
    testTree.insert(8); // leaf
    cout << testTree.isComplete() << endl;
    // 0

    // completing the tree
    testTree.insert(2); // leaf
    cout << testTree.isComplete() << endl;
    // 1

    // making it no longer complete
    testTree.remove(4);
    cout << testTree.isComplete() << endl;
    // 0
}


int main() {

    test_constructor();

    test_destructor();

    test_insert();

    test_search();

    test_remove();

    test_displayInOrder();

    test_displayPreOrder();

    test_displayPostOrder();

    test_displayLevelOrder();

    test_count();

    test_height();

    test_getMin();

    test_getMax();

    test_isComplete();




    return 0;
}
