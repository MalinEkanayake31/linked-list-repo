#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createList(int n){
    node* head=0;
    node* current=NULL;
    int data;

    for(int i=0;i<n;i++){
        printf("enter element %d : ",i+1);
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

void printList(node* head){
    node*current=head;

    while(current!=0){
        printf("%d  ",current->data);
        current=current->next;
    }
    printf("NULL \n");
}


int main(){
    int n;

    printf("enter the no of elements you want to add : ");
    scanf("%d",&n);

    node* head=createList(n);

    printList(head);

    while(head!=0){
        node* temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}
