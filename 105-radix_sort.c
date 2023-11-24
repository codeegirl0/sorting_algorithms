#include "sort.h"

/**
 * radix_sort - sorts an array by the Radix sort algorithm
 * @array: array of integers being sort
 * @size: size to array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		lsd_sorting_counting(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * lsd_sorting_counting - counting sort wsing lsd
 * @array: array to be sort
 * @size: the array size
 * @lsd: least significant digital
 */
void lsd_sorting_counting(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0}, *out_arr, l, m;
	size_t k, n;

	out_arr = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		count_arr[(array[k] / lsd) % 10]++;
	for (l = 1; l < 10; l++)
		count_arr[l] += count_arr[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		out_arr[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
		count_arr[(array[m] / lsd) % 10]--;
	}

	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	free(out_arr);
}
