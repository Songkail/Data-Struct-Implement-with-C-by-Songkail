#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

void initDeque(struct Deque* deque) {
    deque->front = deque->rear = -1;
}

int isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

int isFull(struct Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

void enqueueFront(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque->arr[deque->front] = data;
}

void enqueueRear(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->arr[deque->rear] = data;
}

int dequeueFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int data = deque->arr[deque->front];
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
    return data;
}

int dequeueRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int data = deque->arr[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return data;
}

int main() {
    struct Deque deque;
    initDeque(&deque);

    enqueueFront(&deque, 1);
    enqueueRear(&deque, 2);
    enqueueFront(&deque, 3);
    enqueueRear(&deque, 4);

    printf("Dequeued from front: %d\n", dequeueFront(&deque));
    printf("Dequeued from rear: %d\n", dequeueRear(&deque));

    return 0;
}
