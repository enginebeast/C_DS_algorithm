#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//List node structure


//udf


int main(void) {
	Stack* stack = createStack();

	char command;
	while (1) {
		printf("Command: ");
		scanf(" %c", &command);
		if (command == 'I') {
			int num;
			printf("Number: ");
			scanf("%d", &num);
			push(stack, num);
		}
			
		else if (command == 'O') {
			int output = pop(stack);
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