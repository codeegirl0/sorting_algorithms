#include "sort.h"


/**
* intswapping - swaps index of array
* @l: left or low index for swapping
* @r: right or high idx
*/

void intswapping(int *l, int *r)
{
	int temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

/**
* bit_merge - bitonic merge
* @array: Array slice to merge
* @low: lowest index
* @count:  slice cnt
* @dir: the direction by ascending 1 descending 0
* @size:  total array size for printing
*/

void bit_merge(int *array, int low, int count, int dir, size_t size)
{
	int i, n;

	if (count > 1)
	{
		n = count / 2;
		for (i = low; i < low + n; i++)
		{
			if (((array[i] > array[i + n]) && dir == 1) ||
			(dir == 0 && (array[i] < array[i + n])))
				intswapping(&array[i], &array[i + n]);
		}
		bit_merge(array, low, n, dir, size);
		bit_merge(array, low + n, n, dir, size);
	}
}

/**
* bit_sorting - bitonic recursive sort
* @array: array to sort
* @low: lowest index
* @count: Count to slice
* @dir: ascending 1 descending 0
* @size: size of total array to print
*/

void bit_sorting(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		bit_sorting(array, low, n, 1, size);
		bit_sorting(array, low + n, n, 0, size);
		bit_merge(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
* bitonic_sort - Sorts array using bitonic algo
* @array: Array being sort
* @size: Size for array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sorting(array, 0, size, 1, size);
}
