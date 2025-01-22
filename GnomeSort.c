#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
    int n = 10000; // Taille du tableau
    int arr[n];
    srand(time(NULL)); // Initialisation de la graine pour rand()

    // Remplissage du tableau avec des valeurs aléatoires
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Valeurs entre 0 et 99 999
    }

    clock_t start = clock();
    gnomeSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken (Gnome Sort): %f seconds\n", time_taken);

    return 0;
}