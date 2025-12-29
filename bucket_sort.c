#include <stdio.h>

#define N 10

void insertionSort(float arr[], int n)// Distribute elements into buckets
 {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    float arr[N] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    float bucket[N][N];
    int count[N] = {0};

    
    for (int i = 0; i < N; i++) // Distribute elements into buckets
    {
        int index = N * arr[i];
        bucket[index][count[index]++] = arr[i];
    }

    
    for (int i = 0; i < N; i++)// Sort each bucket
        insertionSort(bucket[i], count[i]);

    
    int k = 0;   // Concatenate buckets
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%.2f ", arr[i]);

    return 0;
}