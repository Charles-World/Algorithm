#pragma once
#include <stdio.h>
//void InsertSort(int array[], int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		int k = array[i];    
//		int j = 0;
//		for (j = i - 1; j >= 0; j--)       
//		{
//			if (array[j] <= k)
//			{
//				break;
//			}
//			array[j + 1] = array[j];
//		}
//		array[j + 1] = k;
//	}
//}
//
//void InsertSortWithGap(int *arr, int size, int gap)
//{
//	for (int i = gap; i < size; i++)
//	{
//		int k = arr[i];
//		int j = 0;
//		for (j = i - gap; j >= 0; j -= gap)
//		{
//			if (arr[j] >= k)
//			{
//				break;
//			}
//			arr[j + gap] = arr[j];
//		}
//		arr[j + gap] = k;
//	}
//}
//
//void PrintSort(int *arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//
//	printf("\n");
//}
//
//void ShellSort(int *arr, int size)
//{
//	int gap = size;
//
//	while (1)
//	{
//		gap = (gap / 3) + 1;
//		InsertSortWithGap(arr, size, gap);
//
//		if (gap == 1)
//		{
//			break;
//		}
//	}
//
//	PrintSort(arr, size);
//}

//void ADJustDown(int *arr, int size, int root)
//{
//	int left = 2 * root + 1;
//	int right = 2 * root + 2;
//	int max = 0;
//
//	if (left >= size)
//	{
//		return;
//	}
//
//	if (right < size && arr[left] < arr[right])
//	{
//		max = left;
//	}
//	else if (right >= size)
//	{
//		max = left;
//	}
//	else
//	{
//		max = right;
//	}
//
//	if (arr[root] <= arr[max])
//	{
//		return;
//	}
//	else
//	{
//		int tem = arr[root];
//		arr[root] = arr[max];
//		arr[max] = tem;
//	}
//
//	ADJustDown(arr, size, max);
//}
//
//void CreatHeap(int *arr, int size)
//{
//	for (int i = (size - 2) / 2; i >= 0; i--)
//	{
//		ADJustDown(arr, size, i);
//	}
//}
//
//void HeapSortPrint(int *arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	printf("\n");
//}

//void HeapSort(int *arr, int size)
//{
//	CreatHeap(arr, size);
//
//	for (int i = 1; i < size; i++)
//	{
//		int tmp = arr[0];
//		arr[0] = arr[size - i];
//		arr[size - i] = tmp;
//
//		ADJustDown(arr, size - i, 0);
//	}
//
//	HeapSortPrint(arr, size);
//}
//
//
//
void AdjustDown(int *arr, int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int max = 0;

	if (left >= size)
	{
		return;
	}

	if (right < size && arr[left] < arr[right])
	{
		max = right;
	}

	else
	{
		max = left;
	}

	if (arr[root] >= arr[max])
	{
		return;
	}
	else
	{
		int tmp = arr[root];
		arr[root] = arr[max];
		arr[max] = tmp;
	}

	AdjustDown(arr, size, max);
}

void CreatHeap(int *arr, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, size, i);
	}
}

void PrintHeapSort(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void HeapSort(int *arr, int size)
{
	CreatHeap(arr, size);

	for (int i = size - 1; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		AdjustDown(arr, i, 0);
	}

	PrintHeapSort(arr, size);
}
//
//void InsertSortGap(int *arr, int size, int gap)
//{
//	for (int i = gap; i < size; i++)
//	{
//		int n = arr[i];
//		int j = 0;
//
//		for (j = i - gap; j >= 0; j -= gap)
//		{
//			if (arr[j] <= n)
//			{
//				break;
//			}
//
//			arr[j + gap] = arr[j];
//		}
//		arr[j + gap] = n;
//	}
//}
//
//void PrintSort(int *arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//
//	printf("\n");
//}
//
//void ShellSort(int *arr, int size)
//{
//	int gap = 0;
//
//	while (1)
//	{
//		gap = gap / 3 + 1;
//
//		InsertSortGap(arr, size, gap);
//
//		if (gap <= 1)
//		{
//			break;
//		}
//	}
//
//	PrintSort(arr, size);
//}

