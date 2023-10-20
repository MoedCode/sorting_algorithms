#include "sort.h"

/**
 * bubble_sort - sorts a given array of integers  using bubble sort algorithm
 * @array: (int *) pointer to an integer array to sort
 * @size: size of the array
 * Return: (void)
*/
void bubble_sort(int *array, size_t size)
{
	int is_swp = 1;
	size_t i;

	if (!array || !size || size < 2)
		return;

	while (is_swp)
	{
		is_swp = 0;
		for (i = 0; i < size - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				array[i] ^= array[i + 1];
				array[i + 1] ^= array[i];
				array[i] ^= array[i + 1];
				is_swp = 1;
			}
		}
		if (is_swp)
			print_array(array, size);
	}
}

