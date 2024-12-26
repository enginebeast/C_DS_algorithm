#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "array.h"	//swap

//udf
void bubbleSort(int N, int array[]);


int main(void) {
	//Input
	FILE* fp;
	int N, array[100];
	fp = fopen("array.txt", "r");
	fscanf(fp, "%d", &N);
	for (int i = 0; i < N; i++)
		fscanf(fp, "%d", &array[i]);

	//Sort and print
	bubbleSort(N, array);
	for (int i = 0; i < N; i++)
		printf("%d ", array[i]);

	return 0;
}

//UDF
void bubbleSort(int N, int array[]) {
	//0~N-1, 0~N-2, 0~N-3..., 0~1인덱스까지 차례로 swap하며 정렬
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}
}