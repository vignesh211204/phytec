#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int buffer[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Buffer is full! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    buffer[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Buffer is empty! Nothing to dequeue.\n");
        return;
    }

    printf("Dequeued: %d\n", buffer[front]);

    if (front == rear) {
        // Buffer becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Buffer is empty.\n");
        return;
    }

    printf("Buffer: ");
    int i = front;
    while (1) {
        printf("%d ", buffer[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  
    display();

    dequeue();
    dequeue();
    display();

    enqueue(60);
    enqueue(70);  
    display();

    return 0;
}
