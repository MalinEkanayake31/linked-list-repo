#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* createList(int n) {
    node* head = NULL;
    node* current = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);

        if (i == 0) {
            head = (node*)malloc(sizeof(node));
            current = head;
        } else {
            current->next = (node*)malloc(sizeof(node));
            current = current->next;
        }
        current->data = data;
        current->next = NULL;
    }
    return head;
}

void printList(node* head) {
    node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

node* insertAtPosition(node* head, int data, int pos) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }
    node* current = head;
    for (int i = 0; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("The position is beyond the length of the list.\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    int n, pos, data;

    printf("Enter the number of elements you want to add: ");
    scanf("%d", &n);

    node* head = createList(n);

    printList(head);

    while (1) {
        printf("Enter the position (-1 to stop): ");
        scanf("%d", &pos);

        if (pos == -1) {
            break;
        }

        printf("Enter the data: ");
        scanf("%d", &data);

        head = insertAtPosition(head, data, pos);
        printList(head);
    }

    // Free the memory
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

