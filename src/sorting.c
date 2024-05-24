// Utility functions for sorting algorithms
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection sort
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

// Insertion sort
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Merge sort
void merge(int arr[], int left, int mid, int right)
{
    int nL = mid - left + 1;
    int nR = right - mid;
    int *L = (int *)malloc(nL * sizeof(int));
    int *R = (int *)malloc(nR * sizeof(int));
    for (int i = 0; i < nL; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < nR; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}