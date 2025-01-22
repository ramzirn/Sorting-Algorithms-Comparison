#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getDigit(int number, int digitPlace) {
    return (number / digitPlace) % 10;
}

void countingSort(int arr[], int n, int digitPlace) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[getDigit(arr[i], digitPlace)]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        int digit = getDigit(arr[i], digitPlace);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    for (int digitPlace = 1; max / digitPlace > 0; digitPlace *= 10)
        countingSort(arr, n, digitPlace);
}

int main() {
    int n = 100000; // Taille du tableau
    int arr[n];
    srand(time(NULL)); // Initialisation de la graine pour rand()

    // Remplissage du tableau avec des valeurs aléatoires
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Valeurs entre 0 et 99 999
    }

    clock_t start = clock();
    radixSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken (Radix Sort): %f seconds\n", time_taken);

    return 0;
}