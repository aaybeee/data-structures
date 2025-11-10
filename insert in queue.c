#include <stdio.h>
#define SIZE 5

int q[SIZE];
int f = 0;
int r = -1;

void enqueue(int x) {
    if (r == SIZE - 1)
        printf("Queue Full\n");
    else {
        q[++r] = x;
    }
}

void dequeue() {
    if (f > r)
        printf("Queue Empty\n");
    else {
        printf("Dequeued: %d\n", q[f++]);
    }
}

void display() {
    if (f > r)
        printf("Queue Empty\n");
    else {
        printf("Queue elements: ");
        for (int i = f; i <= r; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();

    display();

    return 0;
}
