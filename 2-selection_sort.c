#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in an ascending order using the
 * selection sort algorithm.
 *
 * @array: Pointer to an integer value, which represents the array of integers.
 * @size: Unsigned integer value, representing the size of the array.
 *
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp_j;
	int tmp_int;

	if (size < 2 || array == NULL)
	{
		print_array(array, size);
		return;
	}

	for (i = 0; i <= size - 1; i++)
	{
		tmp_j = i;

		for (j = i + 1; j <= size - 1; j++)
		{
			if (array[tmp_j] > array[j])
				tmp_j = j;
		}

		if (tmp_j != i)
		{
			tmp_int = array[tmp_j];
			array[tmp_j] = array[i];
			array[i] = tmp_int;
			print_array(array, size);
		}
	}
}
