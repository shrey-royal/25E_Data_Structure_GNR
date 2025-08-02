#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSearch(int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;    // if element found return the index
    }
    return -1;  // no element found matching the key
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
        arr[i] = rand() % 100;  // generating random number
    }

    printArray(arr, size);

    printf("\nEnter the element that you want to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, size, key);

    if(result != -1) {
        printf("\n%d found at index %d", key, result);
    } else {
        printf("\n%d not found in the array.", key);
    }
    

    return 0;
}