#include <stdlib.h>
#include "list.h"

//UDF of stack
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
	if (stack->top)
		new_ptr->link = stack->top;
	stack->top = new_ptr;
}

int pop(Stack* stack) {
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


//UDF of queue
Queue* createQueue(void) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

void enqueue(Queue* queue, int num) {
	list_ptr new_ptr = (list_ptr)malloc(sizeof(list_node));
	new_ptr->data = num;
	new_ptr->link = NULL;
	if (queue->front == NULL)
		queue->front = new_ptr;
	else
		queue->rear->link = new_ptr;
	queue->rear = new_ptr;
}

int dequeue(Queue* queue) {
	if (queue->front == NULL) {
		printf("Queue is empty.\n");
		return INT_MIN;
	}

	int output = queue->front->data;
	list_ptr temp = queue->front;
	queue->front = queue->front->link;
	free(temp);

	return output;
}