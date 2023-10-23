#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * swap - swaps two integers
 * @x: pointer to the first integer
 * @y: pointer to the second integer
 * Return: void
 */
void swap(int *x, int *y)
{
	int tmp;

	if (x == NULL || y == NULL)
		return;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lo_partition - sorts the array portion according to start and end
 *
 * @array: pointer to array
 * @size: size of the array
 * @start_idx: index to start from
 * @end_idx: index to end with
 * Return: index of the pivot, 0 on error
 */
int lo_partition(int *array, size_t size, int start_idx, int end_idx)
{
	int pivot = array[end_idx];
	int j, i = start_idx;

	for (j = start_idx; j < end_idx; j++)
	{
		if (array[j] <= pivot)
		{
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		swap(&array[i], &array[end_idx]);
		print_array(array, size);
	}
	return (i);
}

/**
 * str_end_sort - recursive function that sorts the array using
 * quick sort algorithm
 * @array: pointer to the array of integers to sort
 * @size: size of the array
 * @start: index to start array partition to order
 * @end_idx: index to end array partition to order
 * Return: 1 on error if array is NULL or start <= end, 0 otherwise
 */
int str_end_sort(int array[], int size, int start, int end)
{
	int pivot;

	srand(time(NULL));

	if (array && start < end)
	{
		pivot = lo_partition(array, size, start, end);

		str_end_sort(array, size, start, pivot - 1);
		str_end_sort(array, size, pivot + 1, end);
	}
	else
		return (1);

	return (0);
}

/**
 * quick_sort - sorting array using recursive str_end_sort function
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	str_end_sort(array, size, 0, size - 1);
}
