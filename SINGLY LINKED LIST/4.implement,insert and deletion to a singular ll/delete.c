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
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }
    node* current = head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
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

node* deleteAtPosition(node* head, int pos) {
     if (head == NULL) {
         printf("List is empty.\n");
         return head;
     }
     if (pos == 1) {
         node* temp = head;
         head = head->next;
         free(temp);
         return head;
     }
     node* current = head;
     for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
     }
     if (current == NULL || current->next == NULL) {
        printf("The position is beyond the length of the list.\n");
        return head;
     }
     node* temp = current->next;
     current->next = current->next->next;
     free(temp);
     return head;
}

void getlength(){
    int count=0;
    node*temp;
    while(temp!=0){
        count++;
        temp=temp->next;
    }
    printf("length of the linked list is %d",count);
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

    while (1) {
        printf("Enter the position you want to delete (-1 to stop): ");
        scanf("%d", &pos);

        if (pos == -1) {
            break;
        }

        head = deleteAtPosition(head,pos);
        printList(head);
    }

    getlength();

    // Free the memory
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

