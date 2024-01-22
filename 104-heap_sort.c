#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in
 *             ascending order using heap sort
 * @array: An array of integers to be sorted
 * @size: The size of the array
 **/

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size - 1) / 2; i >= 0; i--)
	{
		heapify(array, i, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		print_array(array, size);
		swap_heap(array, 0, i);
		heapify(array, 0, i);
	}
}

/**
 * heapify - Sifts down an array dataset
 * @array: The dataset to be sift
 * @parent: Index of the array
 * @size: Size of the array
 **/

void heapify(int *array, int parent, size_t size)
{
	size_t left_child, right_child;
	int largest;

	left_child = 2 * parent + 1;
	right_child = 2 * parent + 2;
	largest = parent;

	if (left_child < size && array[left_child] > array[largest])
		largest = left_child;
	if (right_child < size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != parent)
	{
		print_array(array, size);
		swap_heap(array, parent, largest);
		heapify(array, largest, size);
	}
}

/**
 * swap_heap - Swaps data at different indexes
 * @a: Array to be operated on
 * @i: Index of an array
 * @j: Index of an array
 **/

void swap_heap(int *a, int i, int j)
{
	int temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
