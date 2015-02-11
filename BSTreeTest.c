#include "expr_assert.h"
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_createTreeNode_creates_a_TreeNode_with_given_data (){
	int data = 5;
	Node *node = createTreeNode(data);
	assert(node->data == 5);
	assert(node->left == 0);
	assert(node->right == 0);
}

void test_createTreeNode_creates_a_TreeNode_with_two_digit_data (){
	int data = 23;
	Node *node = createTreeNode(data);
	assert(node->data == 23);
	assert(node->left == 0);
	assert(node->right == 0);
}

void test_createBSTree_creates_an_empty_tree (){
	BSTree tree = createBSTree();
	assert(tree.root == 0);
	assert(tree.count == 0);
}