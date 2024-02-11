#include <stdio.h>

// Function to perform selection sort on an array
void selectionSort(int arr[], int n) {
    int i, j, min_index;

    // Traverse the array
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, arr_size);

    selectionSort(arr, arr_size);

    printf("\nSorted array: \n");
    printArray(arr, arr_size);

    return 0;
}