#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack {
    int top;
    int array[MAX_SIZE];
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow. Cannot push %d\n", data);
        return;
    }

    stack->array[++stack->top] = data;
    printf("%d pushed onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow. Cannot pop\n");
        return -1;
    }

    int data = stack->array[stack->top--];
    printf("%d popped from the stack\n", data);
    return data;
}

// Function to display the elements of the stack
void displayStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Elements in the stack: ");
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->array[i]);
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    int choice, data;

    do {
        printf("\n----- Stack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                displayStack(&stack);
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}