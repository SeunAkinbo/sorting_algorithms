#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array
 * @array: Original array containing two sorted subarrays
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 **/

void merge(int *array, int *left, size_t left_size, int *right,
		size_t right_size)
{
	int *temp;
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	temp = malloc((left_size + right_size) * sizeof(int));
	if (!temp)
		return;

	i = 0;
	j = 0;
	k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
	free(temp);
}


/**
 * merge_sort_recursive - Recursively sorts an array
 *			  of integers using merge sort
 * @array: Array of integers to be sorted
 * @size: Size of the array
 **/

void merge_sort_recursive(int *array, size_t size)
{
	int *left, *right;
	size_t right_size, mid;

	if (!array || size <= 1)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;
	right_size = size - mid;

	merge_sort_recursive(left, mid);
	merge_sort_recursive(right, right_size);

	merge(array, left, mid, right, right_size);
}


/**
 * merge_sort - Sorts an array of integers
 *		in ascending order using merge sort
 * @array: Array of integers to be sorted
 * @size: Size of the array
 **/

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_recursive(array, size);
}

