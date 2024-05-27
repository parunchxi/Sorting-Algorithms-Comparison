#ifndef TESTING_H
#define TESTING_H

// Define struct for test array
typedef struct TestArray
{
    int test_id;
    int size;
    int type; // 0: random, 1: sorted, 2: reversed sorted
    int *arr;
} TestArray;

// Utility functions for testing
TestArray *new_test_array(int test_id, int size, int type);
void save_test_array(TestArray *test_array);
void save_sorting_runtimes(TestArray *test_array, int algorithm, int runtimes[]);
void test_sorting_algorithms(int test_id, int size, int type);
int get_bubble_sort_runtime(int arr[], int n);
int get_selection_sort_runtime(int arr[], int n);
int get_insertion_sort_runtime(int arr[], int n);
int get_quick_sort_runtime(int arr[], int n);
int get_merge_sort_runtime(int arr[], int n);

#include "../src/testing.c"
#endif