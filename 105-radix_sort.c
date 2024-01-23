#include "sort.h"

/**
 * max_num - Checks for the maximum number in an array
 * @array: Array of integers greater than -1 to be sorted
 * @size: The size of the array dataset.
 *
 * Return: The maximum integer in the array
 **/

int max_num(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * lsd_count_sort - Sorts the array integers using their
 *		    least significant digit, counting sort
 * @array: Array of integers greater than -1 to be sorted
 * @size: The size of the array dataset.
 * @place: The digit location under consideration
 * @output: An array for the output code
 **/

void lsd_count_sort(int *array, size_t size, int place, int *output)
{
	int *count;
	size_t i;

	count = calloc(10, sizeof(int));
	if (!count)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
}


/**
 * radix_sort - Sorting an array off integers.
 * @array: Array of integers greater than -1 to be sorted
 * @size: The size of the array dataset.
 *
 * Description: The function sorts an array
 *		using the radix sort algorithm.
 **/

void radix_sort(int *array, size_t size)
{
	int max, place, *output;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	max = max_num(array, size);
	for (place = 1; max / place > 0; place *= 10)
	{
		lsd_count_sort(array, size, place, output);
		print_array(array, size);
	}
	free(output);
}
