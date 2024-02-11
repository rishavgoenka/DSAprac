#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push %d\n", data);
        return;
    }

    // Set the data and next pointer
    newNode->data = data;
    newNode->next = stack->top;

    // Update the top pointer
    stack->top = newNode;

    printf("%d pushed onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow. Cannot pop\n");
        return -1;
    }

    // Get the data from the top node
    int data = stack->top->data;

    // Update the top pointer and free the top node
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);

    printf("%d popped from the stack\n", data);
    return data;
}

// Function to display the elements of the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Elements in the stack: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the stack
void freeStack(struct Stack* stack) {
    while (stack->top != NULL) {
        struct Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
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

    // Free the memory used by the stack before exiting
    freeStack(&stack);

    return 0;
}