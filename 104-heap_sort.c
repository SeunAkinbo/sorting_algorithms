#include "sorts.h"

void swap_heap(int *a, int *b);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_heap - Swap two integers in an array using heap sort.
 * @a: Integer to swap.
 * @b: Integer to swap.
 */

void swap_heap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Turn a binary tree into a binary heap.
 * @array: An array of integers.
 * @size: The size of the.
 * @base: The index of the base row.
 * @root: The root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left_side, right_side, largest;

	left_side = 2 * root + 1;
	right_side = 2 * root + 2;
	largest = root;

	if (left_side < base && array[left_side] > array[largest])
		largest = left_side;
	if (right_side < base && array[right_side] > array[largest])
		largest = right_side;

	if (largest != root)
	{
		swap_heap(array + root, array + largest);
		print_array(array, size);
		heapify(array, size, base, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void heap_sort(int *array, size_t size)
{
	int count;

	if (array == NULL || size <= 1)
		return;

	for (count = (size / 2) - 1; count >= 0; count--)
		heapify(array, size, size, count);

	for (count = size - 1; count > 0; count--)
	{
		swap_heap(array, array + count);
		print_array(array, size);
		heapify(array, size, count, 0);
	}
}
