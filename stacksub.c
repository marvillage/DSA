#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a stack structure
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push more elements.\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int num1, num2, result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Push each digit of num1 onto the stack
    while (num1 > 0) {
        push(&stack, num1 % 10);
        num1 /= 10;
    }

    int borrow = 0;
    result = 0;

    // Subtract num2 from the digits in the stack
    while (num2 > 0 || !isEmpty(&stack)) {
        int x = pop(&stack) - borrow;
        int y = num2 % 10;

        if (x < y) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = result * 10 + (x - y);
        num2 /= 10;
    }

    printf("Result of subtraction: %d\n", result);

    return 0;
}
