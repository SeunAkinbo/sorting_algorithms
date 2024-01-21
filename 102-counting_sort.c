#include "sort.h"

/**
 * counting_sort - Sorts array of integers in
 *		   ascending order, using counting sort
 * @array: Array of integers to be sorted
 * @size: THe array size
 * Return: void
 **/

void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int max, k, *counting_array;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (k = 0; k <= max; k++)
		counting_array[k] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	print_array(counting_array, max + 1);

	j = 0;
	for (k = 0; k <= max; k++)
	{
		while (counting_array[k] > 0)
		{
			array[j] = k;
			j++;
			counting_array[k]--;
		}
	}

	free(counting_array);
}
