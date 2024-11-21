/**
 * Assignment: Project3
 * Author(s): Socorra McLaughlin
 * Due Date: 11/20/2024 11:59pm
 * Description: A main driver in main.cpp which has test functions for all public methods of BST. A BST class with declarations in BST.h and definitions in BST.cpp. A README.txt file detailing the project date, authors project, date, authors, honor pledge, list of files, and dependencies, test plans for each test function, time complexities for each member function, and all major commits of my git log
 * Comments: Errors should be all accounted for in the form of detecting them and throwing them (always runtime errors)
 * Honor Pledge: I have abided by the Wheaton Honor Code and all work below was performed by Socorra McLaughlin
 */
 
MEMBER FUNCTIONS (test cases and time complexities)

the BST() constructor is O(1)
test_constructor() has two test cases
1) an explicit constructor call where the expected and actual behaviour is not crashing
2) creating an object of BST called testTree to call the constructor where the expected and actual behaviour is not crashing

the ~BST() destructor is O(N)
test_destructor() has four test cases
1 & 2) test_constructor() is called so that its explicitly (1) and object created (2) trees have their destructors called where the expected and actual behaviour is not crashing
3 & 4) creates another object of BST sharing the name of the recently deleted object (3) which is then filled with various contents (4) needing to be deleted where the expected and actual behaviour is a lack of both crash and memory leak

the insert() func's worst case is a straight line with O(N)
test_insert() has five test cases
1) involves tons of insertions to fill out a tree, displaying the contents after each new node and observing that expected and actual outputs are consistent. While this could technically be counted as 7 test cases, I will describe it as an insertion of 5, 3, 4, 2, 7, 6, and 8 resulting in a correct post-order display of 2 4 3 6 8 7 5
2-4) three tests which should throw errors due to trying to add a node that already exists. I tried a value which was node with children, a value which was a leaf node, and the value of the root, all which threw errors as expected.
5) I cleared out the tree and then added all the nodes back using insert(), essentially repeating the first test case on a recently emptied tree resulting in the same expected and observed outputs

search() worst case is the same as insert, so O(N)
test_search() it has five test cases
1) searching a node that does not exist, 5, because the tree is empty, expected and observed result was false
2-4) after adding many nodes to the three, these three test cases searched for a value which was node with children, a value which was a leaf node, and the value of the root, all which returned true as expected
5) a non-empty tree where a value which is not in the tree, 10, is searched for, resulting in false as expected

remove() worst case is the same as the destructor because you can be removing the root and thus all nodes
test_remove() has four test cases
1) tries to remove a value, 5, which is not in the tree, resulting in no change, as expected
2) tries to remove a leaf, 6, which the post-order display demonstrates was successful when 2 4 3 6 8 7 5 becomes 2 4 3 8 7 5.
3) tries to remove the parent, 7, of that leaf which still has another child, 8, both of which are shown by post-order to be delete as expected with the print now being 2 4 3 5
4) tries to remove the root, 5, which post-order shows was successful when an empty line prints showing the whole tree is deleted, as expected

displayInOrder() is O(N)
test_displayInOrder() has three test cases
1) running on an empty tree prints an empty line
2) running on a tree where the inserts were 5, 3, 4, 2, 7, 6, 9 prints 2 3 4 5 6 7 8 as expected
3) running on the same tree after 7 (and thus its children) is deleted prints 2 3 4 5 as expected

displayPreOrder() is O(N)
test_displayPreOrder() has three test cases
1) running on an empty tree prints an empty line
2) running on a tree where the inserts were 5, 3, 4, 2, 7, 6, 9 prints 5 3 2 4 7 6 8 as expected
3) running on the same tree after 7 (and thus its children) is deleted prints 5 3 2 4 as expected


displayPostOrder() is O(N)
test_displayPostOrder() has three test cases
1) running on an empty tree prints an empty line
2) running on a tree where the inserts were 5, 3, 4, 2, 7, 6, 9 prints 2 4 3 6 8 7 5 as expected
3) running on the same tree after 7 (and thus its children) is deleted prints 2 4 3 5 as expected

displayLevelOrder() is O(N)
test_displayLevelOrder() has three test cases
1) running on an empty tree prints an empty line
2) running on a tree where the inserts were 5, 3, 4, 2, 7, 6, 9 prints 5 then 3 7 then 2 4 6 8 (so three lines) as expected
3) running on the same tree after 7 (and thus its children) is deleted prints 5 then 3 then 2 4 as expected

count() is O(N)
test_count() has three test cases
1) when run on an empty tree it returns 0 as expected
2) when run on a tree where the inserts were 5, 3, 4, 2, 7, 6, 9 it reports 7 nodes as expected
3) after removing a node with two children, the count drops to 4 as expected

height() is O(N)
test_height() has six test cases
1) calling on an empty tree should throw an error and which is what occurs
2) after inserting a 5 there is now one level and the returned height is 0, as expected
3) after inserting a 3 there is now two levels and the returned height is 1, as expected
4) after inserting a 4 there is now three levels and the returned height is 2, as expected
5) after inserting 2, 7, 6, and 8 the number of levels is unchanged so returned height is 2 as expected
6) removing 7 and 3 results in the loss of two levels, resulting in a returned height of 0 as expected

getMin() is O(N)
test_getMin() has six test cases
1) calling on an empty tree should throw an error and which is what occurs
2) after inserting a 5 there is one node so it must be the min which is reflected in 5 being returned, as expected
3) after inserting a 3 the new min should be 3, which is what gets returned, as expected
4) after inserting a 4 the min is unchanged, so 3 is still returned, as expected
5) after inserting 2, 7, 6, and 8 the min has changed to 2, which is what gets returned, as expected
6) removing 2 reverts the min back to 3, which is what gets returned, as expected

getMax() is O(N)
test_getMax() has six test cases
1) calling on an empty tree should throw an error and which is what occurs
2) after inserting a 5 there is one node so it must be the max which is reflected in 5 being returned, as expected
3) after inserting a 3 the max is unchanged, so 5 is still returned, as expected
4) after inserting a 7 the max should now be 7, which is returned, as expected
5) after inserting 2, 4, 6, and 8 the max has changed to 8, which is what gets returned, as expected
6) removing 8 reverts the min back to 7, which is what gets returned, as expected

isCompleted() is O(N)
test_isComplete() has four test cases
1) running it on an empty tree should result in true, which is what gets returned, as expected
2) after inserting 5, 3, 4, 7, 6, and 8 the tree has 3 levels but is incomplete, resulting in the expected false being returned
3) once 2 is inserted the tree is completed, resulting in the expected true being returned
4) remmoving 4 makes the tree incomplete again, resulting in the expected result of false being returned


COMMIT 1
BST files
made BST.cpp and BST.h properly. also updated gitignore (likely to continue happening, I will stop mentioning it). I am now ready to start

COMMIT 2
blank tests, insert, search, min, max
creates blank test functions which will be made later and implemented insert, search, min, and max functions

COMMIT 3
size, height, and dead ends
size() is done which means count() is too, height is also done(), I tried to do level_order() but there are no instructions so I cannot do it

COMMIT 4
fixed min and max, did levelOrder
Following feedback in class, findMin() and findMax() have become const so they work and level-order has been implemented iteratively. level-order recursive helper deleted

COMMIT 5
housekeeping commit
delete() changed to remove() in .h and blank definitions added to .cpp. display() removed everywhere as I don't intend on doing it. blank test functions now match changes

COMMIT 6
remove() implemented
did an incredibly clever implementation of remove()

COMMIT 7
destructor implemented
changed destructor from default one that calls remove() on the root

COMMIT 8
added README
will fill it out once project is complete

COMMIT 9
isComplete() finished
did the implementation, very similar to level order

COMMIT 10
in, pre, post order traversals
Implemented recursive helpers and public methods for in order, pre order, and post order

COMMIT 11
BST function comments
added a comment before each function of BST which describes its purpose, implementation, parameters, return values, dependencies, and possible errors. Also changed insert() to throw an error for duplicate

COMMIT 12
tests, bug fixes for traversal, insert, remove
pre and post order recursive helpers had simple errors caused by copy pasting, insert and remove helpers worked but public versions never updated root, destructor is now safe on empty trees
tests made for constructor, destructor, and insert

COMMIT 13
HUGE fix for remove()
comments still describe it but it now doesn't nullptr the whole tree because I forgot to return nodes that weren't deleted

COMMIT 14
last of the test functions
all other test functions made without issue. These are: all traversals, count, height, get min, get max, is complete

COMMIT 15
descriptions and README
description and comment sections of main.cpp beginning comment are completed. README.txt also now has all which is required of it, including a list of major commits