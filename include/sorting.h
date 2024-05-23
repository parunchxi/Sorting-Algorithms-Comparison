#ifndef SORTING_H
#define SORTING_H

// Utility functions for sorting algorithms
void swap(int *a, int *b);

// Bubble sort
void bubble_sort(int arr[], int n);

// Selection sort
void selection_sort(int arr[], int n);

// Insertion sort
void insertion_sort(int arr[], int n);

// Quick sort
void partition(int arr[], int low, int high, int *pivot);
void quick_sort(int arr[], int low, int high);

// Merge sort
void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);

#include "../src/sorting.c"
#endif
