#include <stdlib.h>
#include "list.h"

Stack* createStack(void) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	stack->top = NULL;
	return stack;
}

void push(Stack* stack, int num) {
	list_ptr new_ptr = (list_ptr)malloc(sizeof(list_node));
	new_ptr->data = num;
	new_ptr->link = NULL;
	if (stack->top) {
		new_ptr->link = stack->top;
	}
	stack->top = new_ptr;
}

int pop(Stack* stack) {
	//Exception handler
	if (stack->top == NULL) {
		printf("Stack is empty.\n");
		return INT_MIN;
	}

	int output = stack->top->data;
	list_ptr temp = stack->top;
	stack->top = stack->top->link;
	free(temp);

	return output;
}