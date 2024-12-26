# include "array.h"

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int N, int array[]) {
	//0~N-1, 0~N-2, 0~N-3..., 0~1인덱스까지 차례로 swap하며 정렬
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}
}