#include "sort.h"

/**
 * shell_sort - shell array sorting
 * @array: the array
 * @size: array size
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int thegap = 1, j, k;
	int mytemp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (thegap < size / 3)
		thegap = thegap * 3 + 1;

	while (thegap > 0)
	{
		for (j = thegap; j < size; j++)
		{
			mytemp = array[j];
			k = j;
			while (k >= thegap && array[k - thegap] > mytemp)
			{
				array[k] = array[k - thegap];
				k -= thegap;
			}
			array[k] = mytemp;
		}
		print_array(array, size);
		thegap /= 3;
	}
}
