#include "test.h"

int main()
{
	int arr[] = { 1, 3, 5, 2, 8, 1, 0, 33, 55, 22, 344, 13, 5, 6, 243, 151, 388 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, sz - 1);
	Print(arr, sz);

	system("pause");
	return 0;
}
//int main() {
//	int array[] = { 3, 9, 1, 4, 7, 8, 3, 5 };
//	int size = sizeof(array) / sizeof(int);
//	QuickSort(array, size);
//	for (int i = 0; i < size; i++) {
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//
//	system("pause");
//}
