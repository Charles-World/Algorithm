#include "test_1_18.h"

int main()
{
	int arr[] = { 5, 7, 4, 9, 666, 8, 46, 79, 6, 2, 8, 1, 6, 5, 5, 61, 8, 9, 74, 65, 255, 74, 65, 3, 9, 4, 6, 11, 32, 65, 41, 42, 46, 49, 51};
	int sz = sizeof(arr) / sizeof(arr[0]);
	//ShellSort(arr, sz);
	HeapSort(arr, sz);

	system("pause");
	return 0;
}