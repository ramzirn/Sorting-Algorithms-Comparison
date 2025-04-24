#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

// Quick Sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int n = 10000; 
    int arr[n];
    srand(time(NULL)); 

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }

    clock_t start = clock();
    quickSort(arr, 0, n-1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken (Quick Sort): %f seconds\n", time_taken);

    return 0;
}
