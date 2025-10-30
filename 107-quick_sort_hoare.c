#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: array of integers
 * @low: start index
 * @high: end index
 * Return: index of partition
 */
int hoare_partition(int *array, int low, int high)
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

		swap(&array[i], &array[j]);
		print_array(array, high - low + 1);
	}
}

/**
 * quicksort_hoare - recursive quicksort function
 * @array: array
 * @low: first index
 * @high: last index
 * @size: array size
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high);
		quicksort_hoare(array, low, p, size);
		quicksort_hoare(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array using QuickSort (Hoare scheme)
 * @array: array of integers
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}
