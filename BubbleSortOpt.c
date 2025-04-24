#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Function to swap two integers in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Optimized Bubble Sort function
void bubbleSortOpt(int arr[], int n) {
    int m = n - 1; // Initialize the boundary for unsorted elements
    bool changed; // Flag to check if any swap was made
    do {
        changed = false;
        // Iterate through the array up to the last unsorted element
        for (int i = 0; i < m; i++) {
            if (arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]); // Swap if elements are in wrong order
                changed = true; // Set flag if a swap was made
            }
        }
        m--; // Reduce the boundary for unsorted elements
    } while (changed); // Continue until no swaps are made
}

int main() {
    int n = 10000; // Size of the array
    int arr[n];
    srand(time(NULL)); // Seed for random number generation

    // Populate array with random numbers between 0 and 99,999
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    clock_t start = clock(); // Start the timer
    bubbleSortOpt(arr, n); // Sort the array
    clock_t end = clock(); // End the timer

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time taken

    printf("Time taken (Optimized Bubble Sort): %f seconds\n", time_taken); // Output the time taken

    return 0;
}
