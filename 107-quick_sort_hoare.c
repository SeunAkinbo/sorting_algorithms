#include "sort.h"

/**
 * swap - Swaps two array integers
 * @a: The array to be swapped
 * @b: The array to be swapped
 **/

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Applies hoare partition scheme on the array
 * @arr: The array to be sorted
 * @start: The lower bound of the pivot
 * @end: The upper bound of the pivot
 * @size: Size of the array
 * Return: The sorted integer
 **/

int hoare_partition(int *arr, int start, int end, size_t size)
{
	int pivot, i, j;

	pivot = arr[start];
	i = start - 1;
	j = end + 1;

	while (true)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		swap(arr + i, arr + j);
		print_array(arr, size);
	}
}


/**
 * sorts - Sorts the array
 * @arr: The array of integers to be sorted
 * @start: The index of the array
 * @end: The index of the array
 * @size: The size of the array
 **/

void sorts(int *arr, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = hoare_partition(arr, start, end, size);
		sorts(arr, start, pivot, size);
		sorts(arr, pivot + 1, end, size);
	}
}


/**
 * quick_sort_hoare - Sorts an array of integers in
 *		      ascending order using quick sort
 * @array: An array of integers to be operated on
 * @size: The size of the array
 **/

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sorts(array, 0, (int)size - 1, size);

}
