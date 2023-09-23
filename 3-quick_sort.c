#include "sort.h"

/**
 * quick_sort - Sorting an array of integers in ascending order using the
 * Quicksort algorithm with Lumoto partitioning scheme.
 *
 * @array: Pointer to integer value, which represents the array to be sorted.
 * @size: Unsigned Integer value, which represents the length of the array.
 *
 * Returns: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	int high = size - 1, low = 0;

	if (size < 2 || array == NULL)
		return;

	lumoto(array, low, high, size);
}

/**
 * lumoto - Partioning scheme used in Quicksort alogrithm where it sets
 * the pivot and sort the partions made.
 *
 * @array: Pointer to integer value, which represents the array to be
 * partitioned.
 * @low: Unsigned Integer value, which represents the index of the lowest
 * integer in the partitioned array.
 * @high: Unsigned Integer value, which represents the index of the pivot.
 * @size: Unsigned Integer value, which represents the length of the array.
 *
 * Return: Nothing.
 */
void lumoto(int *array, int low, int high, size_t size)
{
	int tmp, pivot;
	int i, j = low;

	if (low >= high || low < 0)
		return;

	pivot = array[high];

	for (i = low; i < high; i++)
	{

		if (array[i] <= pivot)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;

			if (array[i] != array[j])
				print_array(array, size);

			j++;
		}
	}

	tmp = array[j];
	array[j] = pivot;
	array[high] = tmp;

	if (array[j] != array[high])
		print_array(array, size);

	lumoto(array, low, j - 1, size);
	lumoto(array, j + 1, high, size);
}
