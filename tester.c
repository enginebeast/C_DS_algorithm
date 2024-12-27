#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "array.h"	//swap, bubbleSort, selectSort, insertSort

//udf


int main(void) {
	//Input
	FILE* fp;
	int N, array[100];
	fp = fopen("array.txt", "r");
	fscanf(fp, "%d", &N);
	for (int i = 0; i < N; i++)
		fscanf(fp, "%d", &array[i]);

	//Sort and print
	selectSort(N, array);
	for (int i = 0; i < N; i++)
		printf("%d ", array[i]);

	return 0;
}


//UDF