#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: Array to sort
 * @low: Lower index
 * @high: Higher index
 * @size: Array size
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

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
 * quicksort_hoare - Recursive quicksort using Hoare scheme
 * @array: Array to sort
 * @low: Lower index
 * @high: Higher index
 * @size: Array size
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		quicksort_hoare(array, low, p, size);
		quicksort_hoare(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts using QuickSort (Hoare partition scheme)
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}
