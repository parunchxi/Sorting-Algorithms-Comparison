// Utility functions for arrays
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *copy_array(int arr[], int n)
{
    int *copy = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        copy[i] = arr[i];
    }
    return copy;
}

int *generate_array(int size, int type)
{
    switch (type)
    {
    case 0:
        return generate_random_array(size);
    case 1:
        return generate_sorted_array(size);
    case 2:
        return generate_reversed_sorted_array(size);
    default:
        return NULL;
    }
}

int *generate_random_array(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    for (i = 0; i < size - 1; i++)
    {
        j = rand() % (size - i);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return arr;
}

int *generate_sorted_array(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    return arr;
}

int *generate_reversed_sorted_array(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
    return arr;
}