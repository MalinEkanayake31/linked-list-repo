#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
} node;

node* create_list(int n){
    node* head = NULL;
    node* current = NULL;
    int data;

    for(int i = 0; i < n; i++){
        printf("Enter the data: ");
        scanf("%d", &data);
        if(i == 0){
            head = (node*)malloc(sizeof(node));
            head->prev = NULL;
            current = head;
        }else{
            current->next = (node*)malloc(sizeof(node));
            current->next->prev = current;
            current = current->next;
        }
        current->data = data;
        current->next = NULL;
    }
    return head;
}

void print_list_forward(node* head){
    node* current = head;

    while(current != NULL){
        printf("%d  ", current->data);
        current = current->next;
    }
}

void print_list_backward(node* tail){
    node* current = tail;

    while(current != NULL){
        printf("%d  ", current->data);
        current = current->prev;
    }
}

node* insert_at_position(node* head, int data, int pos){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(pos == 1){
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        return newnode;
    }

    node* current = head;
    for(int i = 1; i < pos - 1 && current != NULL; i++){
        current = current->next;
    }

    if(current == NULL){
        printf("Position is beyond the length \n");
        free(newnode);
        return head;
    }

    newnode->next = current->next;
    newnode->prev = current;
    if (current->next != NULL){
        current->next->prev = newnode;
        current->next = newnode;
    }
    return head;
}

node* delete_at_position(node* head, int pos){
    if(head == NULL){
        printf("List is empty ");
        return head;
    }

    if(pos == 1){
        node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    node* current = head;
    for(int i = 1; i < pos - 1 && current != NULL; i++){
        current = current->next;
    }

    if(current == NULL || current->next == NULL){
        printf("Position is beyond the length \n");
        return head;
    }

    node* temp = current->next;
    current->next = current->next->next;
    if (current->next != NULL)
        current->next->prev = current;
    free(temp);
    return head;
}

int main(){
    int data, n, pos;

    printf("How many elements do you need to add to the linked list: ");
    scanf("%d", &n);

    node* head = create_list(n);

    printf("Printing the doubly linked list forward: ");
    print_list_forward(head);

    while(1){
        printf("\nEnter the position (-1 to stop) ");
        scanf("%d", &pos);

        if(pos == -1){
            break;
        }

        printf("Enter the data: ");
        scanf("%d", &data);

        head = insert_at_position(head, data, pos);
        printf("Printing the doubly linked list forward: ");
        print_list_forward(head);
    }

    while(1){
        printf("\nEnter the position you want to delete(-1 to stop) ");
        scanf("%d", &pos);

        if(pos == -1){
            break;
        }

        head = delete_at_position(head, pos);
        printf("Printing the doubly linked list forward: ");
        print_list_forward(head);
    }

    // Free the allocated memory for the nodes
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

