#include "test.h"

int main() {
	int array[] = { 3, 9, 1, 4, 7, 8, 3, 5 };
	int size = sizeof(array) / sizeof(int);
	MergeSort(array, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
}
