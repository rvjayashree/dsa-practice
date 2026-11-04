/*
 * Experiment: Implementation of Priority Queue using an Array
 * Subject: Data Structures and Algorithms Laboratory
 * 
 * Description:
 * Implements an ascending/descending priority queue using a structure array.
 * Each element holds a data value and an assigned priority number.
 * Higher priority items are dequeued first.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Element {
    int data;
    int priority;
};

struct Element pqueue[MAX];
int size = 0;

/* Check if the priority queue is full */
int isFull() {
    return (size == MAX);
}

/* Check if the priority queue is empty */
int isEmpty() {
    return (size == 0);
}

/* Insert an element with an assigned priority */
void enqueue(int data, int priority) {
    if (isFull()) {
        printf("Priority Queue Overflow! Cannot insert element %d.\n", data);
        return;
    }

    pqueue[size].data = data;
    pqueue[size].priority = priority;
    size++;
    printf("Enqueued: Data = %d, Priority = %d\n", data, priority);
}

/* Find the index of the highest priority element (highest number = highest priority) */
int getHighestPriorityIndex() {
    int highestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pqueue[i].priority > pqueue[highestIndex].priority) {
            highestIndex = i;
        }
    }
    return highestIndex;
}

/* Remove and return the item with the highest priority */
void dequeue() {
    if (isEmpty()) {
        printf("Priority Queue Underflow! Queue is empty.\n");
        return;
    }

    int highestIndex = getHighestPriorityIndex();
    printf("Dequeued highest priority element: Data = %d (Priority = %d)\n", 
           pqueue[highestIndex].data, pqueue[highestIndex].priority);

    // Shift remaining elements to fill the gap
    for (int i = highestIndex; i < size - 1; i++) {
        pqueue[i] = pqueue[i + 1];
    }
    size--;
}

/* Display all elements and their priorities */
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("\nCurrent Priority Queue Elements:\n");
    for (int i = 0; i < size; i++) {
        printf("[Data: %d | Priority: %d]\n", pqueue[i].data, pqueue[i].priority);
    }
}

int main() {
    int choice, data, priority;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue (Insert element with priority)\n");
        printf("2. Dequeue (Remove highest priority element)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority (higher number = higher priority): ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please select 1 to 4.\n");
        }
    }

    return 0;
}
