#include <stdio.h>
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
    save_test_array(test_array);
    return test_array;
}

void save_test_array(TestArray *test_array)
{
    FILE *file = fopen("../data/test_array.csv", "a+");
    if (file == NULL)
    {
        perror("Failed to open file");
        return;
    }
    // Check if the file is empty to write the header
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    if (file_size == 0)
    {
        fprintf(file, "test_id,size,type,array\n");
    }
    fseek(file, 0, SEEK_SET);
    // Write test array to file
    fprintf(file, "%d,%d,%d,", test_array->test_id, test_array->size, test_array->type);
    for (int i = 0; i < test_array->size; i++)
    {
        fprintf(file, "%d", test_array->arr[i]);
        if (i < test_array->size - 1)
        {
            fprintf(file, " ");
        }
    }
    fprintf(file, "\n");
    fclose(file);
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