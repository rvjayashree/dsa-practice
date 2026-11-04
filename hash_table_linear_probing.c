/*
 * Experiment 12: Implementation of Hashing with Collision Resolution using Linear Probing
 * Subject: Data Structures and Algorithms Laboratory
 * 
 * Case Study Context:
 * At the college gate, security staff must verify a student's ID card instantly
 * against the master list using a hash table for fast lookups and linear probing
 * for collision resolution.
 */

#include <stdio.h>

#define TABLE_SIZE 7

int hashTable[TABLE_SIZE];
int isOccupied[TABLE_SIZE] = {0};

/* Hash function using division method (key % TABLE_SIZE) */
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

/* Insert a Student ID into the hash table using linear probing */
void insert(int key) {
    int index = hashFunction(key);
    int probes = 0;

    // Linear probing loop to find an empty slot
    while (isOccupied[index] == 1) {
        printf("Collision at index %d for ID %d -> probing next slot\n", index, key);
        index = (index + 1) % TABLE_SIZE;
        probes++;

        if (probes == TABLE_SIZE) {
            printf("Hash Table is Full! Cannot insert ID %d.\n", key);
            return;
        }
    }

    // Place element in empty slot
    hashTable[index] = key;
    isOccupied[index] = 1;
    printf("Student ID %d stored at index %d\n", key, index);
}

/* Search for a Student ID in the hash table */
int search(int key) {
    int index = hashFunction(key);
    int probes = 0;

    while (isOccupied[index] == 1 && probes < TABLE_SIZE) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        probes++;
    }
    return -1; // Not found
}

/* Display the state of the hash table */
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (isOccupied[i] == 1) {
            printf("Index %d -> Student ID %d\n", i, hashTable[i]);
        } else {
            printf("Index %d -> empty\n", i);
        }
    }
}

int main() {
    // Preset Student IDs matching the sample input sequence
    int studentIDs[] = {101, 108, 115, 102, 122};
    int n = sizeof(studentIDs) / sizeof(studentIDs[0]);

    // Insert keys into hash table
    for (int i = 0; i < n; i++) {
        insert(studentIDs[i]);
    }

    // Display hash table contents
    display();

    // Search demonstration
    int searchKey = 115;
    int foundIndex = search(searchKey);

    if (foundIndex != -1) {
        printf("Student ID %d found at index %d\n", searchKey, foundIndex);
    } else {
        printf("Student ID %d not found\n", searchKey);
    }

    return 0;
}
