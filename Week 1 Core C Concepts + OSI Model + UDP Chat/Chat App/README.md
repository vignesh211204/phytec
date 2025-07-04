# 💬 Multi-threaded UDP Chat App in C

This project implements a **simple UDP-based Chat Application** in C using **threads**, enabling **concurrent sending and receiving** of messages for both the client and server.

---
## 🛠 Features

- UDP-based communication (connectionless)
- Real-time messaging using `pthread` threads
- Command-line argument support
- Clean terminal chat interface

---
## 📁 Folder Structure
```
Chat App/
├── client.c # UDP Client with threads
├── server.c # UDP Server with threads
└── README.md # Project documentation
```
---
## ⚙️ Compilation

Use `gcc` with `-pthread` to enable threading support.

### Compile Server
```bash
gcc server.c -o server -pthread
```

### Compile Client
```bash
gcc client.c -o client -pthread
```

---
### 🚀 How to Run
### 🖥️ Start Server (Terminal 1)
```bash
./server <port>
```
# Example:
```bash
./server 8080
```
### 🖥️ Start Client (Terminal 2)
```bash
./client <server_ip> <port>
```
# Example:
```bash
./client 127.0.0.1 8080
```
## 🧪 Sample Chat Output
# Server Terminal
```bash
Server is running on port 8080...
Client: Hello Server!
You: Hello Client!
```

# Client Terminal
```bash
Connected to server at 127.0.0.1:8080
You: Hello Server!
Server: Hello Client!
```

## 📌Multithreading Explained 

| **Thread**          | **Responsibility**                                             |
|-------------------|---------------------------------------------------------|
| **Sender Thread**  | Reads user input and sends to peer        |
| **Receiver Thread** | Listens for incoming messages and prints them                 |


## 📚 Key Concepts Used

| **Concept**          | **Usage**                                             |
|-------------------|---------------------------------------------------------|
| **UDP Socket**  | Connectionless communication via sendto() / recvfrom()        |
| **POSIX Threads** | For concurrency (pthread_create, pthread_join)                |
| **Command-line Args**  | Configure IP and port at runtime        |






