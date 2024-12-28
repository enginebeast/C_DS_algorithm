#pragma once

//List structure
typedef struct list_node {
	int data;
	struct list_node* link;
}list_node;
typedef list_node* list_ptr;

//Stack structure
typedef struct Stack {
	list_ptr top;
}Stack;

//udf
Stack* createStack(void);
void push(Stack* stack, int num);
int pop(Stack* stack);