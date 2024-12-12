#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//Data structure
#define TREE_MAX_SIZE 1000
#define IS_EMPTY(ptr) (!ptr)

typedef struct tree_node {
	int data;
	struct tree_node* left_ptr, * right_ptr;
}tree_node;
typedef tree_node* tree_ptr;


//udf
tree_ptr search(tree_ptr tree, int key);
tree_ptr modified_search(tree_ptr tree, int key);
void insert(tree_ptr node, int num);


int main(void) {
	//Tree
	tree_ptr tree[9];
	for (int i = 0; i < 9; i++)
		tree[i] = (tree_node*)malloc(sizeof(tree_node));
	tree[0]->data = 8;
	tree[0]->left_ptr = tree[1];
	tree[0]->right_ptr = tree[2];

	tree[1]->data = 3;
	tree[1]->left_ptr = tree[3];
	tree[1]->right_ptr = tree[4];

	tree[2]->data = 10;
	tree[2]->left_ptr = NULL;
	tree[2]->right_ptr = tree[5];

	tree[3]->data = 1;
	tree[3]->left_ptr = NULL;
	tree[3]->right_ptr = NULL;

	tree[4]->data = 6;
	tree[4]->left_ptr = tree[6];
	tree[4]->right_ptr = tree[7];

	tree[5]->data = 14;
	tree[5]->left_ptr = tree[8];
	tree[5]->right_ptr = NULL;

	tree[6]->data = 4;
	tree[6]->left_ptr = NULL;
	tree[6]->right_ptr = NULL;

	tree[7]->data = 7;
	tree[7]->left_ptr = NULL;
	tree[7]->right_ptr = NULL;

	tree[8]->data = 13;
	tree[8]->left_ptr = NULL;
	tree[8]->right_ptr = NULL;

	//Data processing
	char command;
	while (1) {
		printf("Please input a command: ");
		scanf(" %c", &command);

		//Search
		if (command == 'S') {
			int n;
			printf("Please input a search key: ");
			scanf("%d", &n);
			if (search(tree[0], n))
				printf("%d is exist in the tree.\n", n);
			else
				printf("%d is not exist in the tree.\n", n);
		}

		//Insert
		else if (command == 'I') {
			int n;
			printf("Please input a integer: ");
			scanf("%d", &n);
			insert(&tree[0], n);
		}

		//Exit
		else if (command == 'E')
			break;
		
		//Exception
		else {
			printf("Please input a right command.\n");
		}
	}

	return 0;
}


//UDF
tree_ptr search(tree_ptr node, int key) {
	while (node) {
		if (key == node->data)
			return node;
		else if (key < node->data)
			node = node->left_ptr;
		else
			node = node->right_ptr;
	}
	return NULL;
}

tree_ptr modified_search(tree_ptr node, int key) {
	tree_ptr parent = NULL;
	while (node) {
		if (key == node->data)
			return NULL;
		
		parent = node;
		if (key < node->data)
			node = node->left_ptr;
		else
			node = node->right_ptr;
	}
	return parent;
}

void insert(tree_ptr *node, int num) {
	tree_ptr temp = modified_search(*node, num);
	if (temp || !(*node)) {
		tree_node* new_node = (tree_node*)malloc(sizeof(tree_node));
		new_node->data = num;
		new_node->left_ptr = NULL;
		new_node->right_ptr = NULL;
		if (*node) {
			if (num < temp->data)
				temp->left_ptr = new_node;
			else
				temp->right_ptr = new_node;
		}
		else
			*node = new_node;
	}
}