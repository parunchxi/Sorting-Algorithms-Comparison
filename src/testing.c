#include <time.h>
#include "../include/array.h"
#include "../include/testing.h"

// Utility functions for testing
TestArray *new_test_array(int test_id, int size, int type)
{
    TestArray *test_array = (TestArray *)malloc(sizeof(TestArray));
    test_array->test_id = test_id;
    test_array->size = size;
    test_array->type = type;
    test_array->arr = generate_array(size, type);
    return test_array;
}

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