#include "sort.h"
#include <stddef.h>




int main(void)
{
    size_t n;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
    return (0);

}