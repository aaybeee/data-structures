
#include <stdio.h>
#define SIZE 5

int q[SIZE], f = 0, r = -1;

void enqueue(int x) {
    if (r == SIZE - 1) printf("Queue Full\n");
    else q[++r] = x;
}

void dequeue() {
    if (f > r) printf("Queue Empty\n");
    else printf("%d\n", q[f++]);
}

void display() {
    if (f > r) printf("Empty\n");
    else for (int i = f; i <= r; i++) printf("%d ", q[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
