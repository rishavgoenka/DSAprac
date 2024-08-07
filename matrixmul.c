#include <limits.h>
#include <stdio.h>

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++) 
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

int main()
{
    int N;
    int arr[100];

    printf("Enter the number of matrices: ");
    scanf("%d", &N);

    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, 1, N));

    return 0;
}