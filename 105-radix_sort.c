#include "sort.h"
#include <stddef.h>
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
/**
 * adjust_int_len - Adjusts the length of an integer by adding leading zeros.
 * @n: A pointer to the integer to be adjusted.
 * @len: The desired length of the integer.
 * Return: The adjusted integer. If the integer was already of the desired length,
 *       the original integer is returned.
 */
 int adjust_int_len(int *n, int len) {
    /* Check if the integer is already of the desired length*/
    int current_len, i, num_zeros, multiplier;

    current_len = snprintf(NULL, 0, "%d", *n);
    if (current_len >= len) {
        return *n;
    }

    /* Calculate the number of leading zeros needed */
    num_zeros = len - current_len;

    /*  Adjust the integer by adding leading zeros */
    multiplier = 1;
    for (i = 0; i < num_zeros; i++)
        multiplier *= 10;

    *n = *n * multiplier;

    return *n;
}


void radix_sort(int *array, size_t size)
{
    int max_int, max_int_len , size_i = (int)size, i,
    *output_array;


    max_int = getMaxInAr(array, size);
    max_int_len = number_len(max_int);

    output_array = malloc((size_i) * sizeof(int));
    if (!output_array)
        return;

    printf("max_int[%d] len[%d] \n", max_int, max_int_len);

    for (i = 0; i < size_i; i++)
        output_array[i] = adjust_int_len(&array[i], max_int_len);

    print_array(output_array, size);

}