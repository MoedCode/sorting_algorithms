#include "sort.h"

/**
 * bubble_sort - sorts a given array of integers  using bubble sort algorithm
 * @array: (int *) pointer to an integer array to sort
 * @size: size of the array
 * Return: (void)
*/

void bubble_sort(int *array, size_t size)
{
	 /* Set initially to 1 to ensure at least one pass */
	int is_swp = 1, tmp;
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
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				is_swp = 1;  /* Set the flag if a swap occurred */
				print_array(array, size);
			}
		}
	}
}
