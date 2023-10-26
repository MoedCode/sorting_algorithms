#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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
 * number_len - function that gets the length of a given numbers
 *
 * parameters:
 * @n: number that it's length wanted to be calculated
 *
 * Return: the given number length
 */

 int number_len(int n)
{
	unsigned int len = 0;

	unsigned int divisor = 10;

	while (n)
	{
		n = n / divisor;
		len++;
	}
	return (len);
}

char *int2str(int n, int len)
{
	int temp, max_len, num_chars;
	static char str[12];  /* Assuming a maximum of 11 digits and a null terminator */

	if (len <= 0) {
		fprintf(stderr, "Error: Length should be greater than 0\n");
		return ("nill");
	}

	temp = n;
	max_len = 0;
	while (temp != 0) {
		temp /= 10;
		max_len++;
	}

	if (len < max_len) {
		fprintf(stderr, "Error: Length is too small to represent the integer\n");
		return ("nill");
	}

	num_chars = snprintf(str, sizeof(str), "%0*d", len, n);

	if (num_chars != len) {
		fprintf(stderr, "Error: Conversion failed\n");
		return ("nill");
	}

	return str;
}
void radix_sort(int *array, size_t size)
{
	int max_int, max_int_len , size_i = (int)size, i;
	char **output_array;



	max_int = getMaxInAr(array, size);
	max_int_len = number_len(max_int);

	output_array = malloc((size_i) * sizeof(char *));
	if (!output_array)
		return;


	for (i = 0; i < size_i; i++)
	{
		output_array[i] = int2str(array[i],  max_int_len);
		printf("[%i]=%s, ", i, int2str(array[i],  max_int_len));
		if (i == (size_i - 1))
			puts("\n");
	}
	output_array[i] = NULL;
	for (i = 0; i < size_i; i++) {
		if (output_array[i]) {
			printf("[%i]=%s, ", i, output_array[i]);
		}
	}

	putchar(10);
	free(output_array);

}