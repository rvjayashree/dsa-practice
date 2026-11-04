# dsa-practice
# Data Structures & Algorithms in C

A structured collection of Data Structures and Algorithms implementations in C, focusing on core concepts, memory efficiency, and practical lab exercises.

---

## 📂 Repository Contents

| Topic | File Name | Description | Time Complexity |
| **Queues** | `circular_queue.c` | Circular queue implementation using fixed-size arrays with wrap-around indexing. | Enqueue: $O(1)$<br>Dequeue: $O(1)$ |
| **Trees** | `bst.c` | Binary Search Tree with insertion, deletion, and depth-first traversals (Inorder, Preorder, Postorder). | Search: $O(h)$<br>Insert: $O(h)$ |

---

## 🛠️ Prerequisites & Compilation

To compile and run any of the programs locally, you need a C compiler (`gcc` or `clang`).

### 1. Compile

Open a terminal or command prompt in the directory containing the file and run:

```bash
gcc -Wall -Wextra circular_queue.c -o circular_queue
