#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
/**
 * swap - ...
 * @x: ...
 * @y: ...
 * Return: void
 **/
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: ...
 * @size: ...
 *
 * Return: void
 **/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;

				print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}
