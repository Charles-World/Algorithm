#pragma once
#include <stdio.h>
#include <stdlib.h>

//int Partition(int *array, int left, int right)
//{
//
//}
//void QuickSort(int *array, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//
//	int div = Partition(array, left, right);
//
//	QuickSort(array, left, div - 1);
//	QuickSort(array, div + 1, right);
//}

void Merge(int *arr, int left, int mid, int right, int *extra)
{
	int sz = right - left;
	int extra_index = 0;
	int right_index = mid;
	int left_index = left;

	while(left_index < mid && right_index < right)
	{
		if (arr[left_index] <= arr[right_index])
		{
			extra[extra_index++] = arr[left_index++];
		}
		else
		{
			extra[extra_index++] = arr[right_index++];
		}
	}

	while (left_index < mid)
	{
		extra[extra_index++] = arr[left_index++];
	}

	while (right_index < right)
	{
		extra[extra_index++] = arr[right_index++];
	}

	for (int i = 0; i < sz; i++)
	{
		arr[left + i] = extra[i];
	}
}
void _MergeSort(int *arr, int left, int right, int *extra)
{
	if (left + 1 >= right)
	{
		return;
	}

	int mid = left + (right - left) / 2;

	_MergeSort(arr, left, mid, extra);
	_MergeSort(arr, mid, right, extra);

	Merge(arr, left, mid, right, extra);
}
void MergeSort(int *arr, int size)
{
	int *extra = (int*)malloc(sizeof(int) * size);
	_MergeSort(arr, 0, size, extra);
	free(extra);
}