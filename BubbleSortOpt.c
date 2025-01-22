#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortOpt(int arr[], int n) {
    int m = n - 1;
    bool changed;
    do {
        changed = false;
        for (int i = 0; i < m; i++) {
            if (arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                changed = true;
            }
        }
        m--;
    } while (changed);
}

int main() {
    int n = 10000; // Taille du tableau
    int arr[n];
    srand(time(NULL)); // Initialisation de la graine pour rand()

    // Remplissage du tableau avec des valeurs aléatoires
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Valeurs entre 0 et 99 999
    }

    clock_t start = clock();
    bubbleSortOpt(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken (Optimized Bubble Sort): %f seconds\n", time_taken);

    return 0;
}