#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * swap - swaps  tow integers
 * @x: pointer to  first integers
 * @y: pointer to  second integers
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
 * lo_partition - sort the array portion according to start and end
 *
 * @array: pointer to array
 * @size: sizeof(array)
 * @start_idx: index to start from
 * @end_idx: index to end with
 * @Return: (int) index of the pivot, (0) on error
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
 * str_end_sort-   recursive function that sort  array  using quicksort algorithm .
 * @array: pointer to  array of integers to sort.
 * @start: index to start array partition to order  with  .
 * @end_idx: index to end array partition to order  with .
 * Return: (1) on error if array is NULL or start !< end else return (0)
  */
int str_end_sort(int array[], int size, int start, int end)
{
	int pivot;

	srand(time(NULL));

	if(array && start <= end)
	{
		pivot = lo_partition(array, size, start,end);

		str_end_sort(array, size, start, pivot - 1);
		str_end_sort(array, size, pivot + 1, end);

	}
	else
		return (-1);
	return (0);
}
/**
 * quick_sort -  sorting array using recursive  str_end_sort function
 * @array: pointer to array
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	 if (!array || size < 2)
        return;

	str_end_sort(array, size, 0, size -1);

}

