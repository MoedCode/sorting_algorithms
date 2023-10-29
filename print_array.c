#include "sort.h"
#include <stddef.h>
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
void _print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	putchar('{');
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("[%d]=%d",(int)i, array[i]);
		++i;
	}
	putchar('}');
	printf("\n");
}
/**
 * swap - swaps two integers
 * @x: pointer to the first integer
 * @y: pointer to the second integer
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
void print_2Dstr_arr(char **array, size_t size)
{
	/* __print for Debug purposes__ */

	size_t i;
	putchar('{');
	for (i = 0; i < size; i++)
		if (array[i])
		{
			if ((int)i > 0)
				printf(",  ");
			printf("[%i]=\"%s\"" ,(int)i, array[i]);
		}
	putchar('}');
	putchar(10);
}
