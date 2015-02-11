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