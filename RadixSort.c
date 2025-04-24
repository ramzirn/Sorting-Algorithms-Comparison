#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to extract the digit at a given place value
int getDigit(int number, int digitPlace) {
    return (number / digitPlace) % 10;
}

// Counting sort based on the digit place
void countingSort(int arr[], int n, int digitPlace) {
    int output[n]; // Output array to store sorted elements
    int count[10] = {0}; // Count array to store count of occurrences

    // Store count of occurrences of each digit
    for (int i = 0; i < n; i++)
        count[getDigit(arr[i], digitPlace)]++;

    // Change count[i] so it contains actual position of this digit
    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    // Build the output array
    for (int i = n-1; i >= 0; i--) {
        int digit = getDigit(arr[i], digitPlace);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix sort main function
void radixSort(int arr[], int n) {
    int max = arr[0]; // Find the maximum number to know the number of digits
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    // Do counting sort for every digit. Note that
    // instead of passing digit number, digit place is passed.
    for (int digitPlace = 1; max / digitPlace > 0; digitPlace *= 10)
        countingSort(arr, n, digitPlace);
}

// Main function to test Radix Sort
int main() {
    int n = 100000; // Size of the array
    int arr[n];
    srand(time(NULL)); // Seed for random number generation

    // Populate array with random numbers between 0 and 99,999
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    clock_t start = clock(); // Start the timer
    radixSort(arr, n); // Sort the array
    clock_t end = clock(); // End the timer

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time taken

    // Output the time taken
    printf("Time taken (Radix Sort): %f seconds\n", time_taken);

    return 0;
}
