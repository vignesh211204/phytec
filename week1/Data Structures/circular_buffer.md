## Circular Buffer

A **Circular Buffer** is a data structure that uses a **fixed-size array** as if it were connected end-to-end.

- It wraps around when the end of the array is reached.
- It’s super-efficient for **producer-consumer** scenarios and real-time systems like **audio processing**, **data streams**, and **network buffers**.
---
## 🧠 Core Operations

- **enqueue(x)** → Add an element to the rear
- **dequeue()** → Remove an element from the front
- **display()** → Print the current buffer content

Also includes:
- `isFull()` → Check if buffer is full
- `isEmpty()` → Check if buffer is empty

---
## ⚙️ Program Workflow

### 1. Enqueue (Insertion)

- When `enqueue(value)` is called:
  - It first checks if the buffer is **full** using the condition:
    ```c
    front == (rear + 1) % SIZE
    ```
    If true, insertion is denied with a message.
  - If the buffer is **empty** (`front == -1`), both `front` and `rear` are initialized to `0`.
  - Otherwise, the `rear` index is advanced in a circular way:
    ```c
    rear = (rear + 1) % SIZE;
    ```
  - The value is then stored in `buffer[rear]`.

### 2. Dequeue (Removal)

- `dequeue()` removes the element at the `front` index:
  - **Case 1: Empty Buffer**
    - If `front == -1`, it prints:
      ```
      Buffer is empty! Nothing to dequeue.
      ```
  - **Case 2: Single Element**
    - If `front == rear`, the buffer becomes empty after removal. Both are reset:
      ```c
      front = rear = -1;
      ```
  - **Case 3: Multiple Elements**
    - `front` is moved forward using:
      ```c
      front = (front + 1) % SIZE;
      ```

### 3. Display

- `display()` prints the buffer contents from `front` to `rear` in a circular fashion:
  - It uses a loop starting from `front`, printing each `buffer[i]`.
  - The index is incremented with:
    ```c
    i = (i + 1) % SIZE;
    ```
  - Loop ends when it reaches `rear`.

---

### 🧪 Sample Output

```bash
Enqueued: 10
Enqueued: 20
Enqueued: 30
Enqueued: 40
Enqueued: 50
Buffer is full! Cannot enqueue 60
Buffer: 10 20 30 40 50
Dequeued: 10
Dequeued: 20
Buffer: 30 40 50
Enqueued: 60
Enqueued: 70
Buffer: 30 40 50 60 70
```



