#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return (root == NULL);
}

// Function to push an element onto the stack
void push(struct StackNode** root, int data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
}

// Function to pop an element from the stack
int pop(struct StackNode** root) {
    if (isEmpty(*root)) {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to perform addition using the stack
int performAddition(struct StackNode* root) {
    int result = 0;
    while (!isEmpty(root)) {
        result += pop(&root);
    }
    return result;
}

int main() {
    struct StackNode* stack = NULL;

    // Push numbers onto the stack
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    // Perform addition using the stack
    int sum = performAddition(stack);

    printf("Sum: %d\n", sum);

    return 0;
}
