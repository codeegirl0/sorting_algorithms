#include "sort.h"

/**
 * swapping - to swap 2 integer
 * @a: integer
 * @b: integer
 * Return: (void) swap integer
 */
void swapping(int *a, int *b)
{
	int thetmp;

	thetmp = *a;
	*a = *b;
	*b = thetmp;
}

/**
 * spliting - array splited by pivot
 * @array: the array
 * @low: integer
 * @high: integer
 * @size: array size (size_t)
 * Return: pivote idx (int)
 */
int spliting(int *array, int low, int high, size_t size)
{
	int piv = array[high];
	int z = low - 1, x;

	for (x = low; x <= high; x++)
	{
		if (array[x] <= piv)
		{
			z++;
			if (z != x)
			{
				swapping(&array[z], &array[x]);
				print_array(array, size);
			}
		}
	}
	return (z);
}

/**
 * sort_lomuto - to sort recursive array
 * @array: arr to sort
 * @low: low val of array
 * @high: hight val of array
 * @size: array size
 * Return: void
 */
void sort_lomuto(int *array, int low, int high, size_t size)
{
	int j;

	if (low < high)
	{
		j = spliting(array, low, high, size);
		sort_lomuto(array, low, j - 1, size);
		sort_lomuto(array, j + 1, high, size);
	}
}

/**
 * quick_sort - to sort quickly
 * @array: array to be sorted
 * @size: array size
 * Return: the sort Array (void)
 */
void quick_sort(int *array, size_t size)
{
	sort_lomuto(array, 0, size - 1, size);
}
