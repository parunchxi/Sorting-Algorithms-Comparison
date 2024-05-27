#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/sorting.h"
#include "include/testing.h"

int main()
{
    int id = START_ID;
    for (int size = START_SIZE; size < END_SIZE; size += SIZE_STEP)
    {
        // Random array
        for (int i = 0; i < NUM_TESTS; i++)
        {
            test_sorting_algorithms(id, size, 0);
            id++;
        }
        // Sorted array
        test_sorting_algorithms(id, size, 1);
        id++;
        // Reversed sorted array
        test_sorting_algorithms(id, size, 2);
        id++;
    }
    printf("\e[0;32mTesting complete\n\e[0m");
    return 0;
}