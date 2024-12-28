#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//udf


int main(void) {
	Queue* queue = createQueue();

	char command;
	while (1) {
		printf("Command: ");
		scanf(" %c", &command);
		if (command == 'I') {
			int num;
			printf("Number: ");
			scanf("%d", &num);
			enqueue(queue, num);
		}
			
		else if (command == 'O') {
			int output = dequeue(queue);
			if (output == INT_MIN)
				continue;
			printf("%d\n", output);
		}

		//Break
		else if (command == 'E')
			break;
		//Exception handler
		else
			printf("Incorrect input");
	}

	return 0;
}


//UDF