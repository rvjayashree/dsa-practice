/*
 * Experiment: Implementation of Singly Linked List
 * Subject: Data Structures and Algorithms Laboratory
 * 
 * Description:
 * Implements fundamental operations on a singly linked list using dynamic 
 * memory allocation: insertion at beginning/end, deletion of a specific node,
 * searching for a value, and list traversal/display.
 */

#include <stdio.h>
#include <stdlib.h>

/* Node structure definition */
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create a new node in heap memory */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at the beginning of the list */
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

/* Insert at the end of the list */
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

/* Delete the first occurrence of a specific value */
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", key);
}

/* Search for an element in the linked list */
void search(int key) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", key);
}

/* Display the linked list */
void display() {
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Value\n");
        printf("4. Search an Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 5:
                display();
                break;
            case 6:
                // Free any remaining nodes before exit
                while (head != NULL) {
                    struct Node *temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice! Please select 1 to 6.\n");
        }
    }

    return 0;
}
