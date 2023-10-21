#include "sort.h"
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size; i++)
	{

		for (j = i; j < size; j++)
		{
			/*printf("arr[%li] = %i, arr[%li] = %i\n", i, array[i], j, array[j]);*/
			printf("     arr[%i] > arr[%i] \n", array[j], array[i]);

			if (array[j] > array[i])
			{
				int tmp = array[i];

				array[i] = array[j];
				array[j] = tmp;

				print_array(array, size);
			}
		}
		printf("***\n");
	}
}
