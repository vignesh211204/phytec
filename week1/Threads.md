# Threads and Multithreading in C

## 🚀 What is a Thread?
A **thread** is the smallest unit of execution within a process.
Multiple threads in a single process run **concurrently** and **share memory**, making inter-thread communication easy.

---
![thread processes](thread_processes.jpg)

---

## ✅Comparison: Thread vs Process

| Feature                | **Process**                                               | **Thread**                 |
|------------------------|-----------------------------------------------------------|----------------------------|
| **Memory**             | Separate                                                  | Shared(Within same process)|
| **Communication**      | Complex(IPC required)                                     | Easy (shared memory)       |
| **Creation Time**      | Slow                                                      | Fast                       |
| **Crash Impact**       | Does not affect other process even if one is crashed also |  Can affect entire process |

---

### 🎯 Why Use Threads? 
- Run multiple tasks simultaneously.  
- Perform background operations (e.g., data logging, sensor polling). 
- Improve performance on multi-core processors. 
- Keep software modular and responsive.

---

## What is Multithreading?
Multithreading is the ability of a program to **run multiple threads** in **parallel or concurrently**.

**Types**  
- **Preemptive** – the operating system or RTOS scheduler automatically controls thread switching.  
- **Cooperative** – the thread itself must voluntarily give up control (or yield) so another thread can run. 
---

## ⚙️ Thread Lifecycle in C

### ✅ 1. Thread Creation
   `pthread_create()` — create a new thread
### ✅2. Thread Termination
   Return from function or use `pthread_exit()`
### ✅3. Thread Join
   `pthread_join()` — wait for thread to complete
   
---

## Thread Synchronization
Thread synchronization is the technique used to ensure that **multiple threads** can **safely access** and **modify** shared resources (like variables, memory, or devices) without interfering with each other.s)

**Thread Synchronization Mechanisms**  
- Mutex
- Semaphores
- Condition Variables
---

### 1️⃣ Mutexes (Mutual Exclusion Locks)
-  Its main purpose is to prevent multiple threads from accessing a critical section — a part of code that accesses shared data — at the same time.
-  When a thread reaches a critical section, it locks the mutex using `pthread_mutex_lock()`.
-  If another thread tries to lock the same mutex, it will wait (block) until the first thread unlocks it using `pthread_mutex_unlock()`.

### 2️⃣ Semaphores
- It can control access to a shared resource by maintaining a counter, which represents how many threads can access the resource at the same time.
- Threads decrease the counter using `sem_wait()` (also called P operation), and increase it with `sem_post()` (also called V operation).
- If the counter is 0, `sem_wait()` blocks the thread until the counter increases.

### 3️⃣ Condition Variables
- A condition variable allows threads to wait (sleep) until a particular condition is met, and then be signaled to continue.
- They are always used with a mutex, and help when threads need to wait for a change in program state that another thread will cause.
- The producer signals the condition using `pthread_cond_signal()` or `pthread_cond_broadcast()` after adding data.
- The consumer waits using `pthread_cond_wait()` — which internally unlocks the mutex and puts the thread to sleep.
---

## 📌 Summary 

| **Term**          | **Meaning**                                             |
|-------------------|---------------------------------------------------------|
| **Thread**         | Independent path of execution within a process         |
| **Multithreading** | Running multiple threads in parallel                   |
| **Synchronization**| Mechanism to avoid conflicts when threads share data   |
| **Mutex/Semaphore**| Tools to manage access to critical sections            |
| **RTOS Threads**   | Called tasks, managed by RTOS scheduler                |


---
