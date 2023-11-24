#include "sort.h"

/**
 * swapping - swap two int
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
 * spliting - Partition an array and using pivot
 * @array: Array
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivote (int)
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
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
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
 * quick_sort_hoare - Quick Sort Algorithme using hoare partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	myqsort_hoare(array, 0, size - 1, size);
}
