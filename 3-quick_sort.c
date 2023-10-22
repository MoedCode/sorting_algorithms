#include "sort.h"
#include <stddef.h>
#include <stdio.h>
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
 * swap_partition - sort the array portion according to start and end
 *
 * @array: pointer to array
 * @start: index to start from
 * @end: index to end with
 * @Return: (int) index of the pivot, (0) on error
 */
int swap_partition(int array[], int start, int end, int size)
{
	int pivot_value =  array[end], i = start, j;

	for (j = start; j < end; ++j)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	/* finally swap the pivot*/
	swap(&array[i], &array[end]);
	/* return rhe pivot*/
	print_array(array, size);

	return (i);
}


/**
 * str_end_sort-   recursive function that sort  array  using quicksort algorithm .
 * @array: pointer to  array of integers to sort.
 * @start: index to start array partition to order  with  .
 * @right: index to end array partition to order  with .
 * Return: (1) on error if array is NULL or start !< end else return (0)
  */
int str_end_sort(int array[], int start, int end,int size)
{
	int pivot;

	if(array && start <= end)
	{
		pivot = swap_partition(array, start, end, size);
		str_end_sort(array, start, pivot - 1, size);
		str_end_sort(array, pivot + 1, end, size);

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

	str_end_sort(array, 0, size - 1 , size);

}
