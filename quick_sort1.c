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
void swap2(int *x, int *y)
{
	int tmp;

	if (x == NULL || y == NULL)
		return;

	tmp = *x;
	*x = *y;
	*y = tmp;

}
/**
 * hoare_partition - sort the array portion according to start and end
 *
 * @array: pointer to array
 * @size: sizeof(array)
 * @start_idx: index to start from
 * @end_idx: index to end with
 * @Return: (int) index of the pivot, (0) on error
 */
 int hoare_partition(int *array, size_t size, int start_idx, int end_idx)
{
	/* Declare and initialize variables*/
	int pivot, above_pivot, below_pivot;

	/* Choose the pivot element from the array*/
	pivot = array[end_idx];

	/* Initialize the 'above_pivot' variable to start from the start_idx and*/
	/* the 'below_pivot' variable to start from the end_idx*/
	for (above_pivot = start_idx - 1, below_pivot = end_idx + 1; above_pivot < below_pivot;)
	{
		/* Increment the 'above_pivot' index until an element greater*/
		/* than or equal to the pivot is found*/
		do {
			above_pivot++;
		} while (array[above_pivot] < pivot);

		/* Decrement the 'below_pivot' index until an element less than*/
		/* or equal to the pivot is found*/
		do {
			below_pivot--;
		} while (array[below_pivot] > pivot);

		/* If the 'above_pivot' index is less than the 'below_pivot' index,*/
		/* swap the elements at these positions in the array*/
		if (above_pivot < below_pivot)
		{
			swap2(array + above_pivot, array + below_pivot);
			/* Print the array to show the changes (debugging output)*/
			print_array(array, size);
		}
	}

	/* Return the final index of the pivot element*/
	return (above_pivot);
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
		pivot = hoare_partition(array, size, start,end);

		str_end_sort(array, size, start, pivot - 1);
		str_end_sort(array, size, pivot, end);

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

void quick_sort_1(int *array, size_t size)
{
	 if (!array || size < 2)
        return;

	str_end_sort(array, 0, size - 1 , size);

}

