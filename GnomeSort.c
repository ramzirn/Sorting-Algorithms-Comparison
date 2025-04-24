#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Gnome Sort algorithm
void gnomeSort(int arr[], int n) {
    int index = 0;
    while (index < n) {
        if (index == 0 || arr[index] >= arr[index-1]) {
            index++;
        } else {
            int temp = arr[index];
            arr[index] = arr[index-1];
            arr[index-1] = temp;
            index--;
        }
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
    int demo[20] = {12, 23, 23, 23, 33, 32};

    clock_t start = clock();
    gnomeSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output the time taken
    printf("Time taken (Gnome Sort): %f seconds\n", time_taken);

    return 0;
}
