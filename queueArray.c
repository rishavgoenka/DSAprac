#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};

// Function to initialize the queue
void initializeQueue(struct Queue *queue) {
    queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", data);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->array[queue->rear] = data;
    printf("%d enqueued to the queue\n", data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    int data = queue->array[queue->front];

    if (queue->front == queue->rear) {
        // Reset the queue when the last element is dequeued
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    printf("%d dequeued from the queue\n", data);
    return data;
}

// Function to display the elements of the queue
void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue: ");
    int i = queue->front;
    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, data;

    do {
        printf("\n----- Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
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