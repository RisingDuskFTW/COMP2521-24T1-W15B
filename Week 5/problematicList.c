#include <stdio.h>
#include <stdlib.h>

#define LOOP_END 100

struct node {
    int data;
    struct node *next;
};

struct node *ListAppend(struct node *n, int data);
void ListPrint(struct node *node);
void ListFree(struct node *head);

int main(void) {
    struct node *head = NULL;
    for (int i = 0; i < LOOP_END; i++) {
        head = ListAppend(head, i);
    }

    ListPrint(head);
    ListFree(head);
    return 0;
}

// Append a new node with the given data to the end of the list
struct node *ListAppend(struct node *head, int data) {
    // Create the new node in memory
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // Case 1: the list is empty
    if (head == NULL) {
        head = newNode;
    } else {
        // Case 2: find the last node in the list to append to
        struct node *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    return head;
}

// Print all nodes in a linked list
void ListPrint(struct node *node) {
    if (node == NULL) return;

    while (node->next != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
    return;
}

// Free all nodes in the list
void ListFree(struct node *head) {
    struct node *temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
