# include "array.h"

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int N, int array[]) {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}
}

void selectSort(int N, int array[]) {
	for (int i = 0; i < N - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < N; j++) {
			//Save index of minimum number
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		swap(&array[i], &array[minIndex]);
	}
}

void insertionSort(int N, int* array[]) {
	for (int i = 1; i < N; i++) {
		for (int j = i; j > 0; j--) {
			if (array[j] < array[j - 1])
				swap(&array[j], &array[j - 1]);
			else
				break;
		}
	}
}