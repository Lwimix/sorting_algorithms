#include "sort.h"

/**
 * bubble_sort - implements bubble sort algorithm
 * @array: unsorted/sorted array
 * @size: size of array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int temp = 0, counter = 0;
	unsigned int i = 0, j = 0;

	if (array == NULL || size == 0 || size < 2)
		return;
	 (i = 0; i < size; ++i)
	{
		for (j = 0; j < size - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				++counter;
			}
		}
		if (counter == 0)
		{
			print_array(array, size);
			break;
		}
	}
}
