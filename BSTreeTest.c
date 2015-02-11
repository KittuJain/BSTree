#include "expr_assert.h"
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

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

void test_insert_inserts_given_element_at_root_if_tree_is_empty (){
	BSTree tree = createBSTree();
	int data = 12;
	assertEqual(insert(&tree, data),1);
	assertEqual(tree.root->data, 12);
	assertEqual(tree.count,1);
}

void test_insert_inserts_given_element_at_left_if_root_is_greater_than_element (){
	BSTree tree = createBSTree();
	int data1 = 12, data2 = 9;
	assertEqual(insert(&tree, data1),1);
	assertEqual(insert(&tree, data2),1);
	assertEqual(tree.root->data, 12);
	assertEqual(tree.root->left->data, 9);
	assertEqual(tree.count,2);
}

void test_insert_inserts_given_element_at_right_if_root_is_smaller_than_element (){
	BSTree tree = createBSTree();
	int data1 = 12, data2 = 17;
	assertEqual(insert(&tree, data1),1);
	assertEqual(insert(&tree, data2),1);
	assertEqual(tree.root->data, 12);
	assertEqual(tree.root->right->data, 17);
	assertEqual(tree.count,2);
}

void test_insert_inserts_the_value_in_next_row_if_the_element_is_smaller_than_the_root_and_no_space_in_first_level(){
	BSTree tree = createBSTree();
	int data1 = 8, data2 = 7, data3 = 10, data4 = 6;
	assertEqual(insert(&tree,data1),1);
	assertEqual(insert(&tree,data2),1);
	assertEqual(insert(&tree,data3),1);
	assertEqual(insert(&tree,data4),1);
	assertEqual(tree.count,4);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->left->data,7);
	assertEqual(tree.root->right->data,10);
	assertEqual(tree.root->left->left->data,6);
}