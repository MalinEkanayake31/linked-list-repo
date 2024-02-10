#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

node* create_list(int n) {
    node* head = NULL;
    node* current = NULL;
    node* tail = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);

        if (i == 0) {
            head = (node*)malloc(sizeof(node));
            head->prev = NULL;
            current = head;
        } else {
            current->next = (node*)malloc(sizeof(node));
            current->next->prev = current;
            current = current->next;
        }

        current->data = data;
        tail = current; // Keep track of the tail node
        current->next = NULL;
    }

    // Make the list circular
    if (head) {
        head->prev = tail;
        tail->next = head;
    }

    return head;
}

void print_list_forward(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* current = head;

    do {
        printf("%d  ", current->data);
        current = current->next;
    } while (current != head);
}

void print_list_backward(node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* current = tail;

    do {
        printf("%d  ", current->data);
        current = current->prev;
    } while (current != tail);
}

node* insert_at_position(node* head, int data, int pos) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (pos == 1) {
        if (head) {
            newnode->next = head;
            newnode->prev = head->prev;
            head->prev->next = newnode;
            head->prev = newnode;
        } else {
            newnode->next = newnode; // Circular reference for a single node list
            newnode->prev = newnode;
        }

        return newnode;
    }

    node* current = head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is beyond the length \n");
        free(newnode);
        return head;
    }

    newnode->next = current->next;
    newnode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newnode;
        current->next = newnode;
    }

    return head;
}

node* delete_at_position(node* head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (pos == 1) {
        node* temp = head;

        if (head->next != head) { // More than one node in the list
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        } else { // Single node list
            head = NULL;
        }

        free(temp);
        return head;
    }

    node* current = head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position is beyond the length \n");
        return head;
    }

    node* temp = current->next;
    current->next = current->next->next;
    if (current->next != NULL) {
        current->next->prev = current;
    }

    free(temp);
    return head;
}

int main() {
    int data, n, pos;

    printf("How many elements do you need to add to the linked list: ");
    scanf("%d", &n);

    node* head = create_list(n);

    printf("Printing the doubly circular linked list forward: ");
    print_list_forward(head);

    printf("\nPrinting the doubly circular linked list backward: ");
    print_list_backward(head->prev); // The tail node is head->prev

    while (1) {
        printf("\nEnter the position (-1 to stop) ");
        scanf("%d", &pos);

        if (pos == -1) {
            break;
        }

        printf("Enter the data: ");
        scanf("%d", &data);

        head = insert_at_position(head, data, pos);
        printf("Printing the doubly circular linked list forward: ");
        print_list_forward(head);
    }

    while (1) {
        printf("\nEnter the position you want to delete(-1 to stop) ");
        scanf("%d", &pos);

        if (pos == -1) {
            break;
        }

        head = delete_at_position(head, pos);
        printf("Printing the doubly circular linked list forward: ");
        print_list_forward(head);
    }

    // Free the allocated memory for the nodes
    while (head != NULL) {
        node* temp = head;
        head = head->next;

        if (head == temp) { // Single node left in the list
            head = NULL;
        } else {
            head->prev = temp->prev;
            temp->prev->next = head;
        }

        free(temp);
    }

    return 0;
}
