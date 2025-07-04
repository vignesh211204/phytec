## Linked List

A **Linked List** is a linear data structure where each element (called a **node**) contains:

- `data` — the actual value
- `next` — a pointer to the next node in the list

Unlike arrays, linked lists don't require contiguous memory, and you can **insert/delete elements without shifting other elements**.

---
## ⚙️ Program Workflow

### 1. Insertion
- When you call `insert(value)`, a new node is dynamically allocated using `malloc`.
- If the list is empty (`head == NULL`), the new node becomes the head.
- If not, the function traverses to the last node (`temp->next == NULL`) and appends the new node.

### 2. Deletion
- The `deleteNode(value)` function searches for the first occurrence of a node with the matching `value`.
- **Case 1: Deleting Head**
  - If the node to delete is the head, it updates the head pointer and frees the old head.
- **Case 2: Deleting Other Nodes**
  - Traverses the list using a `prev` pointer to unlink the node and then frees its memory.
- **Case 3: Value Not Found**
  - If no such node is found, it prints an appropriate message.

### 3. Display
- The `display()` function walks through the list from `head` to `NULL` and prints the data.
- Each node’s data is followed by an arrow (`→`) for visual clarity.

---

## 🧪 Sample Output

```text
Linked List: 10 → 20 → 30 → 40 → NULL
Linked List: 10 → 30 → 40 → NULL
Value 50 not found in the list.
Linked List: 10 → 30 → 40 → NULL
```
