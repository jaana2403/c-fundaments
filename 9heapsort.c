#include <stdio.h>
#define MAX 100

// Function to heapify the array
void heapify(int A[MAX], int n) {
    int i, j, k, v, flag;
    
    // Start heapifying from the last non-leaf node to the root node
    for (i = n / 2; i >= 1; i--) {
        k = i;
        v = A[k];
        flag = 0;
        while (!flag && 2 * k <= n) {
            j = 2 * k;
            
            // If the right child exists and is greater than the left child, move to the right child
            if (j < n && A[j] < A[j + 1]) {
                j = j + 1;
            }
            
            // If the parent is greater or equal to the largest child, stop
            if (v >= A[j]) {
                flag = 1;
            } else {
                A[k] = A[j];  // Move the larger child up
                k = j;        // Move to the next level
            }
        }
        A[k] = v;  // Place the original parent node in its correct position
    }
}

// Function to perform heap sort
void heapsort(int A[MAX], int n) {
    int i, temp;

    // Perform sorting by repeatedly moving the root of the heap to the end
    for (i = n; i >= 1; i--) {
        temp = A[1];   // Swap the root (max element) with the last element
        A[1] = A[i];
        A[i] = temp;
        
        heapify(A, i - 1);  // Rebuild the heap for the reduced array
    }
}

int main() {
    int n, i, A[MAX];

    // Read the number of elements
    printf("\nRead number of elements: ");
    scanf("%d", &n);

    // Read the array elements
    printf("\nRead elements:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }

    // Build the max heap
    heapify(A, n);

    // Perform heap sort
    heapsort(A, n);

    // Print sorted elements
    printf("\nSorted elements:\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t", A[i]);
    }

    return 0;
}
