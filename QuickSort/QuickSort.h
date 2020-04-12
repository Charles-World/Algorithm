#pragma once
#include <stdio.h>

//int Partion(int *arr, int left, int right)
//{
//	int pivot = arr[right];
//
//	while (left < right)
//	{
//		while (left < right && arr[left] <= pivot)
//		{
//			left++;
//		}
//
//		arr[right] = arr[left];
//		while (left < right && arr[right] >= pivot)
//		{
//			right--;
//		}
//
//		arr[left] = arr[right];
//	}
//
//	arr[left] = pivot;
//	return left;
//}

//int Partion2(int *arr, int left, int right)
//{
//	int div = left;
//
//	for (int i = left; i < right; i++)
//	{
//		if (arr[i] < arr[right])
//		{
//			int tmp = arr[div];
//			arr[div] = arr[i];
//			arr[i] = tmp;
//			div++;
//		}
//	}
//	int tmp = arr[div];
//	arr[div] = arr[right];
//	arr[right] = tmp;
//
//	return div;
//}
void Print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void Swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}


// 快速排序
// 不能保证 left 一定是 0
//升序
int Partion_1(int array[], int left, int right) {
	int begin = left;	// 不要写成 begin = 0;
	int end = right;	// end 不能是 right - 1，反例 { 1，2, 3, 4 }

	while (begin < end) {
		// 基准值在右边，先走左边
		// 否则反例 { 1, 7, 8, 4 }
		// array[begin] 和 array[right] 比较必须有 ==
		// 反例 { 1, 1, 1 }
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// 意味着 array[begin] > array[right]

		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// 意味着 array[end] < array[right]

		Swap(array + begin, array + end);
	}

	// 意味着区间被分成 3 份，分别是 { 小 ， 大， 基准值 }
	Swap(array + begin, array + right);

	// 返回当前基准值所在下标
	return begin;
}
//升序
//int Partion_2(int array[], int left, int right) {
//	int begin = left;
//	int end = right;
//	int pivot = array[right];
//
//	while (begin < end) {
//		while (begin < end && array[begin] <= pivot) {
//			begin++;
//		}
//
//		array[end] = array[begin];
//
//		while (begin < end && array[end] >= pivot) {
//			end--;
//		}
//
//		array[begin] = array[end];
//	}
//
//	array[begin] = pivot;
//
//	return begin;
//}

//升序
int Partion_3(int array[], int left, int right) {
	int d = left;
	for (int i = left; i < right; i++) {
		if (array[i] < array[right]) {
			Swap(array + i, array + d);
			d++;
		}
	}

	Swap(array + d, array + right);
	return d;
}
//

//// array[left, right]
//void __QuickSort(int array[], int left, int right) {
//	if (left == right) {
//		// 区间内只有一个数
//		return;
//	}
//
//	if (left > right) {
//		// 区间内没有数
//		return;
//	}
//
//	// 基准值是 array[right]
//	int div;	// 用来保存最终基准值所在的下标
//	div = Partion_1(array, left, right);	// 遍历 array[left, right]
//											// 把小的放左，大的放右
//											// 返回最后基准值所在的下标
//											// 区间被分成 
//											// [left, div - 1] 比基准值小	*
//											// [div, div]	   基准值		已经在最终位置
//											// [div + 1, right] 比基准值大	*
//	__QuickSort(array, left, div - 1);
//	__QuickSort(array, div + 1, right);
//}
//
//void QuickSort(int array[], int size) {
//	__QuickSort(array, 0, size - 1);
//}
//
void QuickSort(int *arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int div = Partion_3(arr, left, right);

	QuickSort(arr, left, div -  1);
	QuickSort(arr, div + 1, right);
}