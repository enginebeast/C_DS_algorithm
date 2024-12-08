#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//Data structure
typedef struct tree_node{
	char data;
	struct tree_node *left_ptr, *right_ptr;
}tree_node;
typedef tree_node* tree_ptr;


//udf
void inorder(tree_ptr ptr);


int main(void) {
	tree_ptr tree[9];
	for (int i = 0; i < 9; i++) 
		tree[i] = (tree_node*)malloc(sizeof(tree_node));
	tree[0]->data = '+';
	tree[0]->left_ptr = tree[1];
	tree[0]->right_ptr = tree[2];

	tree[1]->data = '*';
	tree[1]->left_ptr = tree[3];
	tree[1]->right_ptr = tree[4];

	tree[2]->data = 'E';
	tree[2]->left_ptr = NULL;
	tree[2]->right_ptr = NULL;

	tree[3]->data = '*';
	tree[3]->left_ptr = tree[5];
	tree[3]->right_ptr = tree[6];

	tree[4]->data = 'D';
	tree[4]->left_ptr = NULL;
	tree[4]->right_ptr = NULL;

	tree[5]->data = '/';
	tree[5]->left_ptr = tree[7];
	tree[5]->right_ptr = tree[8];

	tree[6]->data = 'C';
	tree[6]->left_ptr = NULL;
	tree[6]->right_ptr = NULL;

	tree[7]->data = 'A';
	tree[7]->left_ptr = NULL;
	tree[7]->right_ptr = NULL;

	tree[8]->data = 'B';
	tree[8]->left_ptr = NULL;
	tree[8]->right_ptr = NULL;

	//Inorder
	inorder(tree[0]);


	return 0;
}


//udf
void inorder(tree_ptr ptr) {
	if (ptr) {
		inorder(ptr->left_ptr);
		printf("%c", ptr->data);
		inorder(ptr->right_ptr);
	}
}