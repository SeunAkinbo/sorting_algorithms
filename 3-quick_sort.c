#include "sort.h"

/**
 * swap - Swaps array order in ascending order
 * @a: Integer number
 * @b: Integer number
 *
 * Return: void
 **/

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}


/**
 * partition - The function partitions an
 *	       array and sorts them accordingly
 * @array: The array of integers to be sorted and partitioned
 * @lb: The lower limit of the partition
 * @ub: The upper limit of the partition
 * @size: The size of the array
 * Return: A position partitioning the array
 **/

size_t partition(int *array, int lb, int ub, size_t size)
{
	int j;
	int pivot = array[ub];
	int i = lb - 1;

	for (j = lb; j < ub; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != (int)j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != ub)
	{
		swap(&array[i + 1], &array[ub]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * sorts -  Sorts an array using the Lomuto partition scheme
 * @array: An array of integers to be sorted
 * @lb: The lower bound of the partition
 * @ub: The upper bound of the partition
 * @size: The array size
 **/

void sorts(int *array, int lb, int ub, size_t size)
{
	size_t pivot;

	if (lb < ub)
	{
		pivot = partition(array, lb, ub, size);

		if (pivot > 0)
			sorts(array, lb, (int)pivot - 1, size);

		sorts(array, (int)pivot + 1, ub, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using
 *		the quick sort algorithm
 * @array: An array of integers to be sorted
 * @size: The array size
 *
 * Return: void
 **/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sorts(array, 0, (int)size - 1, size);
}
