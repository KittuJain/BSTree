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