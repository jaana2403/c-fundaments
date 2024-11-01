#include <stdio.h>

// Swap function to exchange two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to divide the array
int partition(int A[], int left, int right) {
    int pivot = A[left];
    int i = left + 1;
    int j = right;

    while (1) {
        while (i <= right && A[i] <= pivot)  // Move i to the right as long as A[i] <= pivot
            i++;
        while (A[j] > pivot)  // Move j to the left as long as A[j] > pivot
            j--;

        if (i < j) {  // If i and j have not crossed, swap them
            swap(&A[i], &A[j]);
        } else {
            break;  // If they have crossed, stop
        }
    }

    swap(&A[left], &A[j]);  // Place the pivot at its correct position
    return j;  // Return the partition point
}

// QuickSort function
void quicksort(int A[], int left, int right) {
    if (left < right) {
        int s = partition(A, left, right);  // Partition the array
        quicksort(A, left, s - 1);  // Recursively sort the left part
        quicksort(A, s + 1, right);  // Recursively sort the right part
    }
}

int main() {
    int n, i, A[150];

    // Read number of elements
    printf("\nRead number of elements: ");
    scanf("%d", &n);

    // Read the elements
    printf("\nRead elements:\n");
    for (i = 0; i < n; i++) {  // Corrected to 0-based indexing
        scanf("%d", &A[i]);
    }

    // Perform QuickSort
    quicksort(A, 0, n - 1);

    // Print sorted elements
    printf("\nSorted elements:\n");
    for (i = 0; i < n; i++) {  // Corrected to 0-based indexing
        printf("%d\t", A[i]);
    }

    return 0;
}
