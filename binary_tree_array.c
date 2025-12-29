#include <stdio.h>
#define MAX 10
int tree[MAX];
void initTree() {
    for(int i = 0; i < MAX; i++)
        tree[i] = -1;
}
void insertRoot(int value) {
    if(tree[0] == -1)
        tree[0] = value;
    else
        printf("Root already exists\n");
}
void insertLeft(int parentIndex, int value) {
    int leftIndex = 2 * parentIndex + 1;
    if(tree[parentIndex] == -1)
        printf("Parent does not exist\n");
    else if(leftIndex >= MAX)
        printf("Index out of range\n");
    else
        tree[leftIndex] = value;
}
void insertRight(int parentIndex, int value) {
    int rightIndex = 2 * parentIndex + 2;
    if(tree[parentIndex] == -1)
        printf("Parent does not exist\n");
    else if(rightIndex >= MAX)
        printf("Index out of range\n");
    else
        tree[rightIndex] = value;
}
void display() {
    for(int i = 0; i < MAX; i++) {
        if(tree[i] != -1)
            printf("%d ", tree[i]);
        else
            printf("- ");
    }
}
int main() {
    initTree();
    insertRoot(1);
    insertLeft(0, 2);
    insertRight(0, 3);
    insertLeft(1, 4);
    insertRight(1, 5);
    printf("Binary Tree Array Representation:\n");
    display();
    return 0;
}