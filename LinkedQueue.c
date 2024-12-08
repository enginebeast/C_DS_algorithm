#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
	int data;
	struct list_node* link;
}list_node;


void enqueue(list_node** queue_front, list_node** queue_rear, int num);
void dequeue(list_node** queue_front);


int main(void) {
	list_node* ptr = NULL;
	list_node* queue_front = NULL;
	list_node* queue_rear = NULL;
	
	while (1) {
		char action;
		int num;

		printf("Please input command: ");
		scanf(" %c", &action);

		//Enqueue
		if(action == 'I'){
			printf("Please input integer: ");
			scanf("%d", &num);
			enqueue(&queue_front, &queue_rear, num);
		}

		//Dequeue
		else if(action == 'O'){
			dequeue(&queue_front);
		}

		//Exit
		else if (action == 'E') {
			printf("Program will terminate.");
			break;
		}

		//Exception
		else {
			printf("Plese input right command!\n");
		}
	}

	return 0;
}


//udf
void enqueue(list_node** queue_front, list_node** queue_rear, int num) {
	list_node* new_ptr = (list_node*)malloc(sizeof(list_node));
	new_ptr->data = num;
	new_ptr->link = NULL;

	//Check if the queue is empty
	if (*queue_front == NULL) {
		*queue_front = new_ptr;
	}
	else {
		(*queue_rear)->link = new_ptr;
	}
	*queue_rear = new_ptr;
}

void dequeue(list_node** queue_front) {
	//Exeption
	if (*queue_front == NULL) {
		printf("Queue is empty!\n");
		return;
	}
	else {
		list_node* temp = *queue_front;
		*queue_front = (*queue_front)->link;
		printf("%d\n", temp->data);
		free(temp);
	}
}