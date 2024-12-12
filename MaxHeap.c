#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Data structure
#define HEAP_MAX_SIZE 1000
#define HEAP_FULL(n) (n == HEAP_MAX_SIZE - 1)
#define HEAP_EMPTY(n) (!n)

int heap[HEAP_MAX_SIZE] = { 0 }; 
int size = 0;


//udf
void insertHeap(int num);
void deleteHeap(void);



int main(void) {
	char command;
	while (1) {
		printf("Please input command: ");
		scanf(" %c", &command);
		//Insert
		if (command == 'I') {
			int num;
			printf("Please input number: ");
			scanf("%d", &num);
			insertHeap(num);
		}

		//Delete
		else if (command == 'D') 
			deleteHeap();

		//Exit
		else if (command == 'E')
			break;

		//Exception
		else
			printf("Please input right command!\n");
	}

	int nodeNum = 1, levelEnd = 1;
	printf("This is the max heap inserted.\n");
	for (int i = 1; i <= size; i++) {
		printf("%d ", heap[i]);
		if (levelEnd == i) {
			printf("\n");
			nodeNum = nodeNum * 2;
			levelEnd += nodeNum;
		}
	}


	return 0;
}

//UDF
void insertHeap(int num) {
	if (HEAP_FULL(size)) {
		printf("The heap is full.\n");
		return;
	}

	int i = ++size;
	heap[i] = num;
	int temp;
	while (i != 1 && heap[i] > heap[i / 2]) {
		temp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = temp;
		i = i / 2;
	}
}

void deleteHeap(void) {
	if (HEAP_EMPTY(size)) {
		printf("The heap is empty.\n");
		return;
	}

	int parent = 1, child = 2;
	heap[parent] = heap[size--];
	int temp;
	while (child <= size) {
		//Compare siblings
		if (child < size && heap[child]<heap[child+1]) 
			child++;
		//Compare parent with child
		if (heap[parent] > heap[child])
			break;
		temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;
		parent = child;
		child *= child;
	}
}