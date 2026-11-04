# Data Structures & Algorithms in C

A structured collection of Data Structures and Algorithms implementations in C, focusing on core concepts, memory efficiency, and practical lab exercises.

---

## 📂 Repository Contents

| Topic | File Name | Description | Time Complexity |
| :--- | :--- | :--- | :--- |
| **Arrays** | `array.c` | Basic array operations: linear traversal, element insertion at index, and deletion. | Traversal: O(n)<br>Insert: O(n)<br>Delete: O(n) |
| **Pointers & Memory** | `StudentRecordsDynamicMemory.c` | Manage dynamic student records using `malloc()`, `realloc()`, and `free()`. | Read: O(n)<br>Display: O(n) |
| **Stack** | `postfix_evaluation.c` | Evaluation of arithmetic postfix expressions using an array-based stack. | Evaluation: O(n)<br>Space: O(n) |
| **Queues** | `queue.c` | Standard FIFO linear queue implementation using a static array. | Enqueue: O(1)<br>Dequeue: O(1) |
| **Queues** | `circular_queue.c` | Circular queue implementation using fixed-size arrays with wrap-around indexing. | Enqueue: O(1)<br>Dequeue: O(1) |
| **Queues** | `priority_queue.c` | Priority queue implementation where elements with higher priority numbers are serviced first. | Enqueue: O(1)<br>Dequeue: O(n) |
| **Linked Lists** | `singly_linked_list.c` | Dynamic singly linked list supporting insertion at head/tail, value deletion, and linear search. | Insert(Head): O(1)<br>Insert(Tail): O(n)<br>Delete: O(n) |
| **Trees** | `bst.c` | Binary Search Tree with insertion, deletion, and depth-first traversals (Inorder, Preorder, Postorder). | Search: O(h)<br>Insert: O(h) |
| **Sorting** | `sorting_algorithms.c` | Comparative study of Bubble Sort, Selection Sort, and Heap Sort for student ranking. | Bubble: O(n²)<br>Selection: O(n²)<br>Heap: O(n log n) |
| **Hashing** | `hash_table_linear_probing.c` | Hash table implementation for student IDs using modulo hashing and linear probing for collision resolution. | Average: O(1)<br>Worst Case: O(n) |

---

## 🛠️ Prerequisites & Compilation

To compile and run any of the programs locally, you need a C compiler (`gcc` or `clang`).

### 1. Compile

Open a terminal or command prompt in the directory containing the file and run:


---

## 👤 Author

* **RV Jayashree**
* GitHub: [@rvjayashree](https://github.com/rvjayashree)

```bash
gcc -Wall -Wextra circular_queue.c -o circular_queue
