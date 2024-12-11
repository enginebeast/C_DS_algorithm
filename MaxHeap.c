#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Data structure
#define HEAP_MAX_SIZE 1000

int heap[HEAP_MAX_SIZE] = { 0 }; 
int tail = 0;


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
	for (int i = 1; i <= tail; i++) {
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
	int i = ++tail;
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
	
}