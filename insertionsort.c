#include <stdio.h>

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    int i, key, j;

    // Traverse the array
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Place the key at its correct position
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, arr_size);

    insertionSort(arr, arr_size);

    printf("\nSorted array: \n");
    printArray(arr, arr_size);

    return 0;
}