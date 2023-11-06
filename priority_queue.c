#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node into the priority queue based on priority
void insert(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    
    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to remove and return the element with the highest priority
int dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Priority queue is empty.\n");
        exit(1);
    }
    struct Node* temp = *head;
    int data = temp->data;
    *head = temp->next;
    free(temp);
    return data;
}

// Function to display the priority queue
void displayPriorityQueue(struct Node* head) {
    struct Node* current = head;
    printf("Priority Queue: ");
    while (current != NULL) {
        printf("(%d, %d) -> ", current->data, current->priority);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize an empty priority queue
    struct Node* priorityQueue = NULL;

    // Insert elements with associated priorities
    insert(&priorityQueue, 3, 1);
    insert(&priorityQueue, 5, 2);
    insert(&priorityQueue, 2, 1);

    // Display the priority queue
    displayPriorityQueue(priorityQueue);

    // Dequeue elements in order of priority
    printf("Dequeue: %d\n", dequeue(&priorityQueue));
    printf("Dequeue: %d\n", dequeue(&priorityQueue));

    // Display the updated priority queue
    displayPriorityQueue(priorityQueue);

    // Free the memory allocated for the nodes
    while (priorityQueue != NULL) {
        struct Node* temp = priorityQueue;
        priorityQueue = priorityQueue->next;
        free(temp);
    }

    return 0;
}
