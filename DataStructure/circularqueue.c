#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;
int count = 0;  // To keep track of number of elements

// Function to insert (enqueue)
void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1)  // Empty queue
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    count++;
    printf("Inserted: %d\n", value);
}

// Function to delete (dequeue)
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! (Empty Queue)\n");
        return;
    }

    int deleted = queue[front];
    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    count--;
    printf("Deleted: %d\n", deleted);
}

// Function to display queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Function to show total number of elements
void totalCount() {
    printf("Number of elements in queue: %d\n", count);
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                totalCount();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
