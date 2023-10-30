#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int getMaxInAr(int *array, size_t size);
 int number_len(int n);
char *int_to_string(int n, int max_len);
size_t freeDoubleArray(char **argv);
int count_sort( int array[], size_t size, int pass);


void radix_sort(int *array, size_t size)
{
	int max_n, pass, cai;

	max_n = getMaxInAr(array, size);
	for (pass = 1; max_n /  pass  ; pass *= 10)
		count_sort(array, size, pass);


	printf("max_n %d ", max_n);
}


/**
 * number_len - function that gets the length of a given numbers
 *
 * parameters:
 * @n: number that it's length wanted to be calculated
 *
 * Return: the given number length
 */

 int number_len(int n)
{
	unsigned int len, divisor;

	for(len = 0, divisor = 10; n; len++)
			n = n / divisor;
	return (len);
}
/**
 * getMaxInAr - Get the Max value in the Array
 *
 * @array: pointer to array
 * @size: size of array
 * Return: positive (int) which is max, (-1) on error
 */


int getMaxInAr(int *array, size_t size)
{
	size_t i;
	int max = 0;

	if (!array || !size)
		return (-1);

	for (i = 0, max = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}
int count_sort( int array[], size_t size, int pass)
{
	 int  size_i = (int)size,
	 *count = calloc(sizeof(int), 10),
	 *tmp = calloc(sizeof(int), size_i),
		i;

	if(!pass || !array || !size)
		return (-1);
	for(i=0; i < size_i; i++)
	{
		++count[(array[i] / pass) % 10 ];
		printf("=> %d", (array[i] / pass) % 10 );
	}
	for (i = 1; i <=9; i++)
		count[i] += count[i-1];

	for (i = size_i; i > 0; i--)
		tmp[(--count[(array[i] / pass) % 10 ]) ] = array[i];
	for (i = 0; i < size_i; i++)
		array[i] = tmp[i];
	free(count);
	free(tmp);
	putchar(10);

	return (0);

}