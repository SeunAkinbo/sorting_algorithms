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
	int max, k, *counting_array, *out_array;

	if (array == NULL || size < 2)
		return;

	max = max_num(array, size);

	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (k = 0; k <= max; k++)
		counting_array[k] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]] += 1;

	out_array = malloc((max + 1) * sizeof(int));
	if (out_array == NULL)
		return;
	for (k = 0; k < (max + 1); k++)
		out_array[k] = counting_array[k];
	for (k = 0; k < (max + 1); k++)
		out_array[k] += out_array[k - 1];
	print_array(out_array, max + 1);

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

	free(out_array);
	free(counting_array);
}

/**
 * max_num - Checks for the maximum number
 * @array: Array of integers
 * @size: The size of the array
 * Return: The maximum integer
 **/

int max_num(int *array, size_t size)
{
	int max;
	size_t counter;

	max = array[0];
	for (counter = 1; counter < size; counter++)
	{
		if (max < array[counter])
			max = array[counter];
	}

	return (max);
}
