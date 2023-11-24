#include "sort.h"

void mysubarr_merge(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void rec_sort_merge(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * mysubarr_merge - Sort a subarray of integers.
 * @subarr: the subarray of the array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of my arr.
 * @mid: The middle index of my arr.
 * @back: The back index of my arr.
 */
void mysubarr_merge(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * rec_sort_merge - merge sort algorithm in recursion.
 * @subarr: the subarray of an array of integers to sort.
 * @buff: the buffer to store the sorted result.
 * @front: The front index  subarray.
 * @back: The back index subarray.
 */
void rec_sort_merge(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		rec_sort_merge(subarr, buff, front, mid);
		rec_sort_merge(subarr, buff, mid, back);
		mysubarr_merge(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sorting the array integers in ascending
 *              order using the merge sort algorithm.
 * @array: the array of integers.
 * @size: size for the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	rec_sort_merge(array, buff, 0, size);

	free(buff);
}
