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

int insert(BSTree_ptr tree, int element){
	Node *node = createTreeNode(element);
	BSTree sub_tree = createBSTree();

	if(!tree->root){
		tree->root = node;
	}

	if(element < tree->root->data){
		if(tree->root->left){
			sub_tree.root = tree->root->left;
			insert(&sub_tree, element);
		}
		else
			tree->root->left = node;
	}
	
	if(element > tree->root->data){
		if(tree->root->right){
			sub_tree.root = tree->root->right;
			insert(&sub_tree, element);
		}
		else
			tree->root->right = node;
	}
	
	tree->count++;
	return 1;
}

Node_ptr find(BSTree tree, int element){
	BSTree sub_tree = createBSTree();

	if(!tree.root)
		return NULL;

	if(element == tree.root->data)
		return tree.root;

	if(tree.root->right && (element > tree.root->data))
		sub_tree.root = tree.root->right;

	if(tree.root->left && (element < tree.root->data))
		sub_tree.root = tree.root->left;

	return find(sub_tree,element);
}

Node_ptr delete(BSTree_ptr tree, int element){
	BSTree sub_tree = createBSTree();
	Node_ptr node = NULL;

	if(tree->root->right && tree->root->right->data == element){
		node = tree->root->right;
		tree->root->right = NULL;
		free(tree->root->right);
	}
	
	if(tree->root->left && tree->root->left->data == element){
		node = tree->root->left;
		tree->root->left = NULL;
		free(tree->root->left);
	}

	if(node == NULL){
		if(element < tree->root->data){
			sub_tree.root = tree->root->left;
			node = delete(&sub_tree, element);
		}
		if(element > tree->root->data){
			sub_tree.root = tree->root->right;
			node = delete(&sub_tree, element);
		}		 
	}
	return node;
}