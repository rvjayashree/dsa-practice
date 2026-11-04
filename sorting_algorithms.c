/*
 * Experiment 11: Implementation of Bubble, Selection and Heap Sorts
 * Subject: Data Structures and Algorithms Laboratory
 * 
 * Case Study Context:
 * At the end of the semester, the class's final marks must be sorted in 
 * descending order to prepare the merit/rank list, comparing Bubble Sort, 
 * Selection Sort, and Heap Sort on the same data.
 */

#include <stdio.h>

/* Utility function to swap two integers */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Utility function to copy an array to keep the original marks intact */
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

/* Utility function to print array elements */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* 1. Bubble Sort (Descending Order) */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Compare adjacent elements and swap if smaller element is ahead
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/* 2. Selection Sort (Descending Order) */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(&arr[i], &arr[maxIdx]);
        }
    }
}

/* Max-Heapify function for Heap Sort */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/* 3. Heap Sort (Descending Order using Max-Heap + Array Inversion) */
void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from heap one by one (produces ascending order)
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }

    // Step 3: Reverse the ascending array to get descending rank list
    for (int i = 0; i < n / 2; i++) {
        swap(&arr[i], &arr[n - 1 - i]);
    }
}

int main() {
    // Preset student marks matching sample input
    int originalMarks[] = {72, 88, 65, 91, 76, 83};
    int n = sizeof(originalMarks) / sizeof(originalMarks[0]);
    int marks[6];

    // Display original marks
    printf("Original Marks       : ");
    printArray(originalMarks, n);

    // Bubble Sort
    copyArray(originalMarks, marks, n);
    bubbleSort(marks, n);
    printf("Bubble Sort (Rank)   : ");
    printArray(marks, n);

    // Selection Sort
    copyArray(originalMarks, marks, n);
    selectionSort(marks, n);
    printf("Selection Sort (Rank): ");
    printArray(marks, n);

    // Heap Sort
    copyArray(originalMarks, marks, n);
    heapSort(marks, n);
    printf("Heap Sort (Rank)     : ");
    printArray(marks, n);

    return 0;
}
