#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int n = 1000000; // Taille du tableau
    int arr[n];
    srand(time(NULL)); // Initialisation de la graine pour rand()

    // Remplissage du tableau avec des valeurs aléatoires
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Valeurs entre 0 et 999 999
    }

    clock_t start = clock();
    quickSort(arr, 0, n-1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken (Quick Sort): %f seconds\n", time_taken);

    return 0;
}