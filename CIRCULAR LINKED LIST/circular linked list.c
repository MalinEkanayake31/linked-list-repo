#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createCircularList(int n){
    node* head = NULL;
    node* current = NULL;
    int data;

    for(int i=0; i<n; i++){
        printf("Enter the data: ");
        scanf("%d", &data);
        if(i == 0){
            head = (node*)malloc(sizeof(node));
            current = head;
        }else{
            current->next = (node*)malloc(sizeof(node));
            current = current->next;
        }
        current->data = data;
    }
    current->next = head; // Make the last node point back to the head to form a circular list
    return head;
}

void printCircularList(node* head){
    if(head == NULL){
        printf("Circular list is empty\n");
        return;
    }

    node* current = head;
    do{
        printf("%d  ", current->data);
        current = current->next;
    } while(current != head);
    printf("\n");
}

node* insertAtPosition(node* head, int data, int pos){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    if(head == NULL){
        newnode->next = newnode;
        return newnode;
    }

    if(pos == 1){
        newnode->next = head;
        node* current = head;
        while(current->next != head){
            current = current->next;
        }
        current->next = newnode;
        return newnode;
    }

    node* current = head;
    for(int i=1; i<pos-1; i++){
        current = current->next;
        if(current == head){ // To handle pos greater than list length
            printf("Position is beyond the length\n");
            free(newnode);
            return head;
        }
    }
    newnode->next = current->next;
    current->next = newnode;
    return head;
}

node* deleteAtPosition(node* head, int pos){
    if(head == NULL){
        printf("Circular list is empty\n");
        return head;
    }

    if(pos == 1){
        if(head->next == head){ // Only one node in the list
            free(head);
            return NULL;
        }
        node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        return temp->next;
    }

    node* current = head;
    for(int i=1; i<pos-1; i++){
        current = current->next;
        if(current->next == head){ // To handle pos greater than list length
            printf("Position is beyond the length\n");
            return head;
        }
    }
    node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

int main(){
    int data, n, pos;

    printf("How many elements do you need to add to the circular linked list: ");
    scanf("%d", &n);

    node* head = createCircularList(n);

    printf("Circular Linked List: ");
    printCircularList(head);

    while(1){
        printf("\nEnter the position (-1 to stop): ");
        scanf("%d", &pos);

        if(pos == -1){
            break;
        }
        printf("Enter the data: ");
        scanf("%d", &data);

        head = insertAtPosition(head, data, pos);
        printf("Circular Linked List: ");
        printCircularList(head);
    }

    while(1){
        printf("\nEnter the position you want to delete (-1 to stop): ");
        scanf("%d", &pos);

        if(pos == -1){
            break;
        }

        head = deleteAtPosition(head, pos);
        printf("Circular Linked List: ");
        printCircularList(head);
    }

    // Free memory
    node* current = head;
    if(current != NULL){
        while(current->next != head){
            node* temp = current;
            current = current->next;
            free(temp);
        }
        free(current);
    }

    return 0;
}
