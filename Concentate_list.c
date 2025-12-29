#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    struct Node* head1 = newNode(10);
    head1->next = newNode(20);
    head1->next->next = newNode(30);

    struct Node* head2 = newNode(40);
    head2->next = newNode(50);
    head2->next->next = newNode(60);

    printf("List 1: ");
    printList(head1);
    printf("\nList 2: ");
    printList(head2);

    head1 = concatenate(head1, head2);

    printf("\nConcatenated List: ");
    printList(head1);

    return 0;
}
