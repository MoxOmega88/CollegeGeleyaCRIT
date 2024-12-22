#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;
int element;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    while (1) {
        printf("Press 1 for insert\n");
        printf("Press 2 for delete\n");
        printf("Press 3 for display\n");
        printf("Press 4 for exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
        }
    }
    return 0;
}

void enqueue() {
    printf("Enter the element to be inserted\n");
    scanf("%d", &element);
    printf("*** Enqueue Entry *** front - %d, rear - %d\n", front, rear);
    
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("The queue is full\n");
    } else {
        if (rear == SIZE - 1) {  // if rear reaches the end of the queue
            rear = 0;             // wrap around to the beginning
        } else {
            rear++;
        }
        
        queue[rear] = element;    // insert the element
        printf("Insertion completed\n");
        
        if (front == -1) {        // first insertion
            front = 0;
        }
    }
    printf("*** Enqueue Exit *** front - %d, rear - %d\n", front, rear);
}

void dequeue() {
    printf("*** Dequeue Entry *** front - %d, rear - %d\n", front, rear);
    
    if (front == -1) {
        printf("The queue is empty\n");
    } else {
        element = queue[front];
        printf("Deleted element is: %d\n", element);
        
        if (front == rear) {  // queue will be empty after dequeue
            front = rear = -1;
        } else {
            if (front == SIZE - 1) {  // wrap around
                front = 0;
            } else {
                front++;
            }
        }
    }
    
    printf("*** Dequeue Exit *** front - %d, rear - %d\n", front, rear);
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int i;
        printf("Circular queue elements are:\n");
        
        if (front <= rear) {  // No wrap-around case
            for (i = front; i <= rear; i++) {
                printf("%d\t", queue[i]);
            }
        } else {  // Wrap-around case
            for (i = front; i < SIZE; i++) {
                printf("%d\t", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d\t", queue[i]);
            }
        }
        printf("\n");
    }
}
