#include "sort.h"

/**
 *bubble_sort - to sort num array in ascending order
 *@array: sort array
 *@size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, i;
	int m;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				m = array[j];
				array[j] = array[j + 1];
				array[j + 1] = m;
				print_array(array, size);
			}
		}
	}
}

