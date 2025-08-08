#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>

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

void selectionSort(int *arr, int size) {
    for (int i = 0; i < size-1; i++) {
        int min_index = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&arr[min_index], &arr[i]);
        }
    }
}

void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i-1;
        int key = arr[i];
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
}

/*
Partition method which selects a pivot
and places each element which is less than pivot value to its left
and the elements greater than the pivot value to its right
*/
int partition(int arr[], int lower, int upper) {
    int i = (lower - 1);

    int pivot = arr[upper]; // select last element as pivot

    int j;
    for (j = lower; j < upper; j++) {
        if (arr[j] <= pivot) {
            // if curent element is smaller than pivot
            i++;    // increase the index of smaller elements
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[upper]);   // places the last element i.e. the pivot to its correct position

    return (i+1);
}

/*
This is where the sorting of the array takes place
*/
void quickSort(int arr[], int lower, int upper) {
    if (upper > lower) {

        // paritioning index is returned by the parition function
        // element is at its correct position
        int partitionIndex = partition(arr, lower, upper);

        // sorting elements before and after the partition index
        quickSort(arr, lower, partitionIndex-1);
        quickSort(arr, partitionIndex+1, upper);
    }
}

void printArray(int *arr, int size) {
    printf("{ ");
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

    int *arr = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100000) - 49999;  // generating random number
    }

    // printf("\nBefore Sorting: ");
    // printArray(arr, size);

    printf("\nSorting Started!");
    clock_t start = clock();

    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size);
    quickSort(arr, 0, size-1);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf("\nAfter Sorting: ");
    // printArray(arr, size);

    for (int i = 0; i < size - 1; i++) {
        assert(arr[i] <= arr[i+1]);
    }

    printf("\nAlgorithm took %.4f seconds to sort %d elements.\n", time_taken, size);

    return 0;
}

/*
1. Bubble Sort - 🍋‍🟩
2. Selection Sort - 🍊
3. Insertion Sort -🥭
4. Quick Sort - 🍉
5. Merge Sort - 
*/