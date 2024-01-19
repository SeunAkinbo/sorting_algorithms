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
 * selection_sort - Sorts an array in ascending order using selection sort
 * @array: The array list of integers to be sorted
 * @size: The size of the array
 *
 * Return: void
 *
 * Description: Sorts an array using selection sort algorithm.
 *		It takes parameters, the array list and
 *		the array size.
 **/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
