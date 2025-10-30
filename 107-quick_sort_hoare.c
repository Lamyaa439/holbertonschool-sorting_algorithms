#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Hoare partition
 * @array: Array
 * @low: Low index
 * @high: High index
 * @size: Array size
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_sort - QuickSort recursion using Hoare scheme
 * @array: Array to sort
 * @low: Low index
 * @high: High index
 * @size: Array size
 */
void hoare_sort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		hoare_sort(array, low, p, size);
		hoare_sort(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sort array with Hoare partition
 * @array: Array to sort
 * @size: Array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, 0, size - 1, size);
}
