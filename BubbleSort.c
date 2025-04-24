#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Swap two integers in array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort algorithm
void bubbleSort(int arr[], int n) {
    // Keep track of whether any swaps were made in the current iteration
    bool changed;
    for (int i = 0; i < n-1; i++) {
        changed = false;
        // Iterate through array and compare adjacent elements
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                changed = true;
            }
        }
        // If no swaps were made, the array is already sorted
        if (!changed) break; 
    }
}

int main() {
    int n = 10000; 
    int arr[n];
    srand(time(NULL)); 

    // Populate array with random numbers between 0 and 99 999
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; 
    }

    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken (Bubble Sort): %f seconds\n", time_taken);

    return 0;
}
