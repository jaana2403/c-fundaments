#include <stdio.h>

int arr[100];  // Increase the size for more flexibility, or use dynamic allocation

void merger(int low, int mid, int high) {
    int temp[100];  // Temporary array to store the merged elements
    int i = low;
    int k = low;
    int j = mid + 1;
    
    // Merge the two halves into temp array
    while ((i <= mid) && (j <= high)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy any remaining elements from the left half
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy any remaining elements from the right half
    while (j <= high)
        temp[k++] = arr[j++];

    // Copy the merged array back into the original array
    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void mergesort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(low, mid);          // Sort the left half
        mergesort(mid + 1, high);     // Sort the right half
        merger(low, mid, high);       // Merge both halves
    }
}

int main() {
    int n, i;
    
    // Take input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Take input for the array elements
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Perform merge sort
    mergesort(0, n - 1);
    
    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    
    return 0;
}
