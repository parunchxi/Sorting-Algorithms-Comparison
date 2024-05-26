#include <time.h>
#include "../include/array.h"

// Utility functions for testing
int get_bubble_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    bubble_sort(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}

int get_selection_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    selection_sort(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}

int get_insertion_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    insertion_sort(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}

int get_quick_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    quick_sort(arr, 0, n - 1);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}

int get_merge_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    merge_sort(arr, 0, n - 1);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}