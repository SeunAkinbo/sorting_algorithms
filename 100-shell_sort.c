#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: Array to be sorted
 * @size: Size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	/* Initialize the gap using Knuth sequence */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	/* Start with the largest gap and work down to a gap of 1 */
	for (; gap > 0; gap /= 3)
	{
		/* Do a gapped insertion sort for this gap size */
		for (i = gap; i < size; i++)
		{
			/* Save a copy of the current element to be inserted */
			temp = array[i];

			/**
			 * Shift earlier gap-sorted elements up until the
			 * correct location for array[i] is found
			 **/
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			/* Place the saved element into the correct location */
			array[j] = temp;
		}
		/* Print the array each time the interval decreases */
		if (gap < size)
			print_array(array, size);
	}
}

