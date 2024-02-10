#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createlist(int n){
    node* head=NULL;
    node* current=NULL;
    int data;

    for(int i=0;i<n;i++){
        printf("Enter the data : ");
        scanf("%d",&data);
        if(i==0){
            head=(node*)malloc(sizeof(node));
            current=head;
        }else{
            current->next=(node*)malloc(sizeof(node));
            current=current->next;
        }
        current->data=data;
        current->next=NULL;
    }
    return head;
}

void printlist(node* head){
    node* current=head;

    while(current!=NULL){
        printf("%d  ",current->data);
        current=current->next;
    }
}

node* insertAtposition(node* head,int data,int pos){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;

    if(pos==1){
        newnode->next=head;
        return newnode;
    }
    node* current=head;
    for(int i=1;i<pos-1 && current!=NULL;i++){
        current=current-> next;
    }
    if(current==NULL){
        printf("position is beyond the length \n");
        free(newnode);
        return head;
    }
    newnode->next=current->next;
    current->next=newnode;
    return head;
}

node* deleteAtposition(node* head,int pos){
    if(head==NULL){
        printf("list is empty ");
        return head;
    }
     if(pos==1){
        node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    node* current=head;
    for(int i=1;i<pos-1 && current!=NULL;i++){
        current=current->next;
    }
    if(current==NULL||current->next==NULL){
        printf("position is beyond the length \n");
        return head;
    }
    node* temp=current->next;
    current->next=current->next->next;
    free(temp);
    return head;
}

int main(){
    int data,n,pos;

    printf("How many elements do you need to add to the linked list :");
    scanf("%d",&n);

    node* head=createlist(n);

    printlist(head);

    while(1){
        printf("\nEnter the position (-1 to stop) ");
        scanf("%d",&pos);

        if(pos==-1){
            break;
        }
        printf("Enter the data ");
        scanf("%d",&data);

        head=insertAtposition(head,data,pos);
        printlist(head);
    }

    while(1){
        printf("\nEnter the position you want to delete(-1 to stop) ");
        scanf("%d",&pos);

        if(pos==-1){
            break;
        }

        head=deleteAtposition(head,pos);
        printlist(head);
    }

    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
