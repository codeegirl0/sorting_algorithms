#include "sort.h"

/**
 * swapping - swap two integer
 * @a: int
 * @b: int
 * Return: (void) Swaped int
 */
void swapping(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * spliting - splite array by pivot
 * @array: Array
 * @low: int
 * @high: int
 * @size: size array (size_t)
 * Return: index pivote (int)
 */
int spliting(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j = high;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swapping(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}
/**
 * myqsort_hoare - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: low array value
 * @high: highest value
 * @size: array size
 * Return: void
 */
void myqsort_hoare(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = spliting(array, low, high, size);
		if (i > low)
			myqsort_hoare(array, low, i, size);
		myqsort_hoare(array, i + 1, high, size);
	}
}
/**
 * quick_sort_hoare -  a sort Algorithme by hoare partition
 * @array: Array to sort
 * @size: array size
 * Return: Array sort(void)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	myqsort_hoare(array, 0, size - 1, size);
}
