#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int printIntAr(int arr[], size_t size);
void swap(int *x, int *y);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
#endif