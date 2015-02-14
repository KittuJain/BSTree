#define STRING char*
typedef struct bsTree BSTree;
typedef struct node Node;
typedef struct node* Node_ptr;
typedef struct bsTree* BSTree_ptr;

struct node{
	int data;
	Node_ptr left;
	Node_ptr right;
};

struct bsTree{
	Node_ptr root;
	int count;
};

Node_ptr createTreeNode(int);
BSTree createBSTree(void);
int insert(BSTree_ptr, int);
Node_ptr find(BSTree, int);
Node_ptr delete(BSTree_ptr, int);
void traverse(BSTree, void (*)(int));