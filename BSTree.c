#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node_ptr createTreeNode(int data){
	Node_ptr node;
	node = calloc(sizeof(Node),1);
	node->data = data;
	return node;
}

BSTree createBSTree(void){
	BSTree *tree;
	tree = calloc(sizeof(BSTree),1);
	return *tree;
}

int insert(BSTree *tree, int element){
	Node *node = createTreeNode(element);
	BSTree sub_tree = createBSTree();
	
	if(!tree->root){
		tree->root = node;
	}

	if(element < tree->root->data){
		if(tree->root->left){
			sub_tree.root = tree->root->left;
			insert(&sub_tree,element);
		}
		else
			tree->root->left = node;
	}
	
	if(element > tree->root->data){
		if(tree->root->right){
			sub_tree.root = tree->root->right;
			insert(&sub_tree,element);
		}
		else
			tree->root->right = node;
	}
	
	tree->count++;
	return 1;
}