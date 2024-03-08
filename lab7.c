#include <stdio.h>

typedef struct {
    int data;
    int numswaps;
} element;

void bubbleSort(int arr[], int n, element swaps[], int *totalSwaps) {
    int i, j, temp;
    *totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j]].data = arr[j];
                swaps[arr[j+1]].data = arr[j+1];
                swaps[arr[j]].numswaps++;
                swaps[arr[j+1]].numswaps++;
                (*totalSwaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, element swaps[], int *totalSwaps) {
    int i, j, min_idx, temp;
    *totalSwaps = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*totalSwaps)++;
        }
    }

    // Reset the numswaps for all elements
    for (i = 0; i < n; i++) {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    // Update swaps array
    for (i = 0; i < n; i++) {
        swaps[arr[i]].numswaps++;
    }
}

void printResults(int array[], int n, element swaps[], int totalSwaps) {
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", swaps[array[i]].data, swaps[array[i]].numswaps);
    }
    printf("Total swaps: %d\n\n", totalSwaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = 9 , n2 = 9;
    element swaps1[100] = {0};
    element swaps2[100] = {0};
    int totalSwaps1, totalSwaps2;

    printf("array1 bubble sort:\n");
    bubbleSort(array1, n1, swaps1, &totalSwaps1);
    printResults(array1, n1, swaps1, totalSwaps1);

    printf("array2 bubble sort:\n");
    bubbleSort(array2, n2, swaps2, &totalSwaps2);
    printResults(array2, n2, swaps2, totalSwaps2);

    for (int i = 0; i < 100; i++) {
        swaps1[i].numswaps = 0;
        swaps2[i].numswaps = 0;
    }

    printf("array1 selection sort:\n");
    selectionSort(array1, n1, swaps1, &totalSwaps1);
    printResults(array1, n1, swaps1, totalSwaps1);

    printf("array2 selection sort:\n");
    selectionSort(array2, n2, swaps2, &totalSwaps2);
    printResults(array2, n2, swaps2, totalSwaps2);

    return 0;
}
