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
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: An array list to be sorted
 * @size: The size of the array
 *
 * Return: void
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		/*Breaks if the array is already sorted*/
		if (!swapped)
			break;
	}
}
