#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int linearSearch(int *arr, int size, int key) {
    // O(1) -> space complexity
    // O(n) -> time complexity
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;    // if element found return the index
    }
    return -1;  // no element found matching the key
}

void swap(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int binarySearch(int *arr, int low, int high, int key) {
    if (high > low) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        }

        if (key < arr[mid]) {
            return binarySearch(arr, low, mid-1, key);
        } else {
            return binarySearch(arr, mid+1, high, key);
        }
    }
}

int binarySearchIterative(int *arr, int low, int high, int key) {
    // O(1) -> space complexity
    // O(log n) -> time complexity
    
    // int count = 0;
    // int mid = (low + high) / 2;

    // while(arr[mid] != key) {
    //     count++;
    //     if (low >= high || high < 0) {
    //         printf("\nCount = %d\n", count);
    //         return -1;
    //     }

    //     // left subarray
    //     if(key < arr[mid]) high = mid - 1;
        
    //     // right subarray
    //     if(key > arr[mid]) low = mid + 1;

    //     mid = (low + high) / 2;
    // }
    // printf("\nCount = %d\n", count);
    // return mid;
}

void printArray(int *arr, int size) {
    printf("\nArray Elements: { ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b }\n");
}

int main() {
    int size;

    srand(time(0)); // seeding random number generator

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    int arr[size], key;

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) - 50;  // generating random number
    }

    bubbleSort(arr, size);
    printArray(arr, size);

    printf("\nEnter the element that you want to search: ");
    scanf("%d", &key);

    // int result = linearSearch(arr, size, key);
    int result = binarySearch(arr, 0, size-1, key);

    if(result != -1) {
        printf("\n%d found at index %d", key, result);
    } else {
        printf("\n%d not found in the array.", key);
    }
    

    return 0;
}