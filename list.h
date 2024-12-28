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

//UDF of stack
Stack* createStack(void);
void push(Stack* stack, int num);
int pop(Stack* stack);

//Queue node structure
typedef struct Queue {
	list_ptr front, rear;
}Queue;

//UDF of queue
Queue* createQueue(void);
void enqueue(Queue* queue, int num);
int dequeue(Queue* queue);