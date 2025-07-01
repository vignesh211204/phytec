## Queue

A **Queue** is a linear data structure that follows the **FIFO** principle:

> **First In, First Out**

Think of it like a line at a ticket counter — the person who enters first gets served first.

### Basic Operations:

- `enqueue(x)` → Add element `x` to the **rear**
- `dequeue()` → Remove element from the **front**

---
## 🧠 Queue using Linked List: How it Works

Each node contains:
- `data` → the actual value
- `next` → pointer to the next node

Two pointers track the state:
- `front` → where elements are removed
- `rear` → where elements are added
---
## ⚙️ Program Workflow

### 1. Enqueue (Insertion)
- When `enqueue(value)` is called:
  - A new node is created dynamically using `malloc`.
  - If the queue is empty (`rear == NULL`), both `front` and `rear` point to the new node.
  - Otherwise, the current `rear->next` is linked to the new node, and `rear` is updated.

### 2. Dequeue (Deletion)
- `dequeue()` removes the node at the `front` of the queue.
- **Case 1: Empty Queue**
  - If `front == NULL`, it prints a message: _"Queue is empty. Nothing to dequeue."_
- **Case 2: Single Element**
  - After removing the node, both `front` and `rear` are set to `NULL`.
- **Case 3: Multiple Elements**
  - `front` is updated to `front->next`, and the old front node is freed.

### 3. Display
- `display()` walks from `front` to `rear`, printing each node’s data.
- Each node’s value is followed by an arrow (`←`) indicating the queue flow (front to rear).

---

## 💻 Example Output

```bash
Queue: 10 ← 20 ← 30 ← NULL
Dequeued: 10
Queue: 20 ← 30 ← NULL
Dequeued: 20
Dequeued: 30
Queue is empty. Nothing to dequeue.
```
