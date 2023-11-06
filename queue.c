#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the queue
struct Queue {
    int front, rear, size;
    int array[MAX_SIZE];
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->rear = MAX_SIZE - 1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the rear of the queue (enqueue)
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue.\n", item);
}

// Function to remove an element from the front of the queue (dequeue)
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // An arbitrary value to indicate an error
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

// Function to get the element at the front of the queue without removing it
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1; // An arbitrary value to indicate an error
    }
    return queue->array[queue->front];
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element: %d\n", front(queue));

    printf("%d dequeued from the queue.\n", dequeue(queue));
    printf("%d dequeued from the queue.\n", dequeue(queue));

    printf("Front element: %d\n", front(queue));

    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Front element: %d\n", front(queue));

    free(queue);

    return 0;
}
