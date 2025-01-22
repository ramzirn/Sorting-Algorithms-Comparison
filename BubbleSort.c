#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    bool changed;
    for (int i = 0; i < n-1; i++) {
        changed = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                changed = true;
            }
        }
        if (!changed) break; // Si aucun échange n'a eu lieu, le tableau est trié
    }
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
    bubbleSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken (Bubble Sort): %f seconds\n", time_taken);

    return 0;
}