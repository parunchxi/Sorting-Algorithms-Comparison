#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/config.h"
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
    FILE *file = fopen("data/test_array.csv", "a+");
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

void save_sorting_runtimes(TestArray *test_array, int algorithm, int runtimes[])
{
    FILE *file = fopen("data/sorting_runtimes.csv", "a+");
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
        fprintf(file, "test_id,size,type,algorithm,");
        for (int i = 1; i <= NUM_SORTS; i++)
        {
            fprintf(file, "runtime_%d,", i);
        }
        fprintf(file, "runtime_avg\n");
    }
    fseek(file, 0, SEEK_SET);
    // Write sorting runtimes to file
    fprintf(file, "%d,%d,%d,", test_array->test_id, test_array->size, test_array->type);
    switch (algorithm)
    {
    case 0:
        fprintf(file, "bubble_sort,");
        break;
    case 1:
        fprintf(file, "selection_sort,");
        break;
    case 2:
        fprintf(file, "insertion_sort,");
        break;
    case 3:
        fprintf(file, "quick_sort,");
        break;
    case 4:
        fprintf(file, "merge_sort,");
        break;
    default:
        break;
    }
    int sum = 0;
    for (int i = 0; i < NUM_SORTS; i++)
    {
        fprintf(file, "%d,", runtimes[i]);
        sum += runtimes[i];
    }
    fprintf(file, "%d\n", sum / NUM_SORTS);
    fclose(file);
}

int get_bubble_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    bubble_sort(arr, n);
    clock_t end = clock();
    return (int)(((double)(end - start)) / CLOCKS_PER_SEC * 1000);
}

int get_selection_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    selection_sort(arr, n);
    clock_t end = clock();
    return (int)(((double)(end - start)) / CLOCKS_PER_SEC * 1000);
}

int get_insertion_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    insertion_sort(arr, n);
    clock_t end = clock();
    return (int)(((double)(end - start)) / CLOCKS_PER_SEC * 1000);
}

int get_quick_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    quick_sort(arr, 0, n - 1);
    clock_t end = clock();
    return (int)(((double)(end - start)) / CLOCKS_PER_SEC * 1000);
}

int get_merge_sort_runtime(int arr[], int n)
{
    clock_t start = clock();
    merge_sort(arr, 0, n - 1);
    clock_t end = clock();
    return (int)(((double)(end - start)) / CLOCKS_PER_SEC * 1000);
}

void test_sorting_algorithms(int test_id, int size, int type)
{
    TestArray *test_array = new_test_array(test_id, size, type);
    int bubble_sort_runtime[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; i++)
    {
        int *arr = copy_array(test_array->arr, test_array->size);
        bubble_sort_runtime[i] = get_bubble_sort_runtime(arr, test_array->size);
        free(arr);
    }
    save_sorting_runtimes(test_array, 0, bubble_sort_runtime);

    int selection_sort_runtime[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; i++)
    {
        int *arr = copy_array(test_array->arr, test_array->size);
        selection_sort_runtime[i] = get_selection_sort_runtime(arr, test_array->size);
        free(arr);
    }
    save_sorting_runtimes(test_array, 1, selection_sort_runtime);

    int insertion_sort_runtime[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; i++)
    {
        int *arr = copy_array(test_array->arr, test_array->size);
        insertion_sort_runtime[i] = get_insertion_sort_runtime(arr, test_array->size);
        free(arr);
    }
    save_sorting_runtimes(test_array, 2, insertion_sort_runtime);

    int quick_sort_runtime[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; i++)
    {
        int *arr = copy_array(test_array->arr, test_array->size);
        quick_sort_runtime[i] = get_quick_sort_runtime(arr, test_array->size);
        free(arr);
    }
    save_sorting_runtimes(test_array, 3, quick_sort_runtime);

    int merge_sort_runtime[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; i++)
    {
        int *arr = copy_array(test_array->arr, test_array->size);
        merge_sort_runtime[i] = get_merge_sort_runtime(arr, test_array->size);
        free(arr);
    }
    save_sorting_runtimes(test_array, 4, merge_sort_runtime);

    free(test_array->arr);
    free(test_array);
}
