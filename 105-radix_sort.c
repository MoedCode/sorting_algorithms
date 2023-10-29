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



void radix_sort(int *array, size_t size)
{
	int max_n;

	max_n = getMaxInAr(array, size);

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


/**
 * int_to_string - shift and cast  given int to string  right  by adding 0
 * to he left number of zeros = max_len - length of the number
 * it uses  number_len function to calculate it
 * returns the string
 * @n:number to be shift
 * @max_len: number of shifting steps must >= number length
 * Return: (char*) string for a casted and shifted number,
 * (NULL) in cases error
 */
char *int_to_string(int n, int max_len)
{
	int i;
	static char s[12];

	if (max_len <= 0 || max_len > 10) {
		fprintf(stderr, "Error: Invalid max_len %d\n", max_len);
		return NULL;
	}
	i = max_len - 1;

	s[max_len] = '\0';  /* Null-terminate the string.*/

	/* Fill the string with digits from right to left.*/
	while (i >= 0) {
		s[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}

	return s;
}
size_t freeDoubleArray(char **argv)
{
	size_t i, j;

	for (j = 0; argv[j]; j++)
			;
	for (i = 0; i <= j; i++)
		if(argv[i])
		{

			free(argv[i]);
			argv[i] = NULL;
 		}
	if(argv)
	{
	free(argv);
	argv = NULL;
	}
	return (i);
}