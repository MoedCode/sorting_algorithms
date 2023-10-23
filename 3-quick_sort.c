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
 * lo_partition - sorts the array portion according to start_idx and end
 *
 * @array: pointer to array
 * @size: size of the array
 * @start_idx_idx: index to start_idx from
 * @end_idx: index to end with
 * Return: index of the pivot, 0 on error
 */
int lo_partition(int *array, size_t size, size_t start_idx, size_t end_idx)
{
int pivot;
size_t i, j;
pivot = array[end_idx];
i = start_idx - 1;
for (j = start_idx; j < end_idx; j++)
{
	if (array[j] < pivot)
	{
	i++;
	if (i != j)
	{
	swap(&array[i], &array[j]);
	if (array[i] != array[j])
	print_array(array, size);
	}
	}

}
	swap(&array[i + 1], &array[end_idx]);
	if (array[i + 1] != array[end_idx])
	print_array(array, size);
		return (i + 1);
}

/**
 * str_end_sort - recursive function that sorts the array using
 * quicksort algorithm
 * @array: pointer to the array of integers to sort
 * @size: size of the array
 * @start_idx: index to start_idx array partition to order
 * @end_idx: index to end array partition to order
 * Return: 1 on error if array is NULL or start_idx <= end, 0 otherwise
 */
int str_end_sort(int *array, size_t low, size_t high, size_t size)
{

	if (low < high)
	{
	size_t pivot = lo_partition(array, low, high, size);

	str_end_sort(array, low, pivot - 1, size);
	str_end_sort(array, pivot + 1, high, size);
	}
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
