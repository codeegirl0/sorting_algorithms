#include "sort.h"

/**
 * locate_it - locate min from array
 * @array: Searched array
 * @index: first index search
 * @size: arr size
 * Return: min index or
 * same index
 */

int locate_it(int *array, int index, size_t size)
{
	int mymin, num_min;
	int j;

	mymin = array[index];
	num_min = index;
	for (j = index; j < (int)size; j++)
	{
		if (array[j] < mymin)
		{
			mymin = array[j];
			num_min = j;
		}
	}
	if (num_min == index)
		return (-1);
	return (num_min);
}

/**
 * selection_sort - sort algorithme 
 * @array: sorting array
 * @size: given array size
 *
 * Return: (void) the sorted array
 */
void selection_sort(int *array, size_t size)
{
	int j;
	int mymin, thetmp;

	for (j = 0; j < (int)size; j++)
	{
		mymin = locate_it(array, j, size);
		if (mymin != -1)
		{
			thetmp = array[j];
			array[j] = array[mymin];
			array[mymin] = thetmp;
			print_array(array, size);
		}
	}
}
