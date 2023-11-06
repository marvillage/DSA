#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;  
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    int reversed = 0;
    int temp = data;
    for (int i = 0; i < 4; i++) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    newNode->data = reversed;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%04d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* addNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10000;
        sum = sum % 10000;

        appendNode(&result, sum);
    }

    return result;
}

void reverseNumbersInList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        int original = current->data;
        int reversed = 0;
        while (original > 0) {
            int digit = original % 10;
            reversed = reversed * 10 + digit;
            original /= 10;
        }
        current->data = reversed;
        current = current->next;
    }
}

int main() {
    long long int number1, number2;
    printf("Enter the first number: ");
    scanf("%lld", &number1);
    printf("Enter the second number: ");
    scanf("%lld", &number2);

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

 
    while (number1 > 0) {
        int segment = number1 % 10000; 
        appendNode(&list1, segment);
        number1 /= 10000;
    }

  
    while (number2 > 0) {
        int segment = number2 % 10000; 
        appendNode(&list2, segment);
        number2 /= 10000;
    }

    printf("Linked List 1: ");
    printList(list1);
    printf("Linked List 2: ");
    printList(list2);

   
    struct Node* result = addNumbers(list1, list2);

    reverseNumbersInList(result);

    printf("Result : ");
    printList(result);

  

    return 0;
}
