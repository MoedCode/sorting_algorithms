#include "sort.h"
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
	{
		/*
		x == NULL && fprintf(stderr, "X is nill ");
		y == NULL && fprintf(stderr, "y is nill ");
		return;
		*/
		return;
	}
	tmp = *x;
	*x = *y;
	*y = tmp;

}

/**
 * bubble_sort - sorts a given array of integers  using bubble sort algorithm
 * @array: (int *) pointer to an integer array to sort
 * @size: size of the array
 * Return: (void)
*/

void bubble_sort(int *array, size_t size)
{
	 /* Set initially to 1 to ensure at least one pass */
	int is_swp = 1;
	size_t i;

	if (!array || !size || size < 2)
		return;

	while (is_swp)
	{
		is_swp = 0;  /* Reset the flag at the beginning of each pass */
		for (i = 0; i < size - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				/*
				array[i] ^= array[i + 1];
				array[i + 1] ^= array[i];
				array[i] ^= array[i + 1];
				*/
				swap(&array[i], &array[i + 1]);
				is_swp = 1;
				print_array(array, size);
			}
		}


	}
}
