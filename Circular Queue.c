#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct CircularQueue {
    int arr[MAX_SIZE];
    int front, rear;
};

void initCircularQueue(struct CircularQueue* queue) {
    queue->front = queue->rear = -1;
}

int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

int isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(struct CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->arr[queue->rear] = data;
}

int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return data;
}

int main() {
    struct CircularQueue queue;
    initCircularQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}
