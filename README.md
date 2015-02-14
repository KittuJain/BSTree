# BSTree
# version 1
----BSTree createBSTree(void);
creates a Binary Search Tree 

----int insert(BSTree *, int);
inserts the given element into the search tree.

----Node * find(BSTree, int);
Given a key(integer), find a node with that key is present in the tree. If not, return NULL.

# version 2
----Node * delete(BSTree *, int);
Delete should accept a reference to a tree and an integer as a key. Upon deletion it should return a reference to the deleted node. If deletion fails for whatever reason(key not found for ex), it should return a NULL.

# version 3
----void traverse(BSTree, void (*)(int));
Traverse function takes a BSTree and performs an in-order traversal. The traverse function also takes a second argument which is a function pointer to a function that accepts an integer as a parameter and returns void. This function pointer is used by the traverse function for every element that it traverses to.