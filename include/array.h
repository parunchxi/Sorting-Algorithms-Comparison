#ifndef ARRAY_H
#define ARRAY_H

// Utility functions for arrays
void print_array(int arr[], int n);
int *copy_array(int arr[], int n);
int *generate_random_array(int size);
int *generate_sorted_array(int size);
int *generate_reversed_sorted_array(int size);

#include "../src/array.c"
#endif