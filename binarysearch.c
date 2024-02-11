#include <stdio.h>

int binarySearch(int arr[], int left, int right, int num) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num)
            return mid;

        if (arr[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 10, 15, 18, 20};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", &len);
    int num = 20;

    int result = binarySearch(arr, 0, len - 1, num);

    if (result != -1)
        printf("Element %d is present at index %d\n", num, result);
    else
        printf("Element %d is not present in the array\n", num);

    return 0;
}