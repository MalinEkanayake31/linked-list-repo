#include<stdio.h>
#include<stdlib.h>

/*void insert_begin(){
    struct node{
        int data;
        struct node* next;
    };
    struct node *head,*newnode,*temp;

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to enter ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insert_end(){
    struct node{
        int data;
        struct node* next;
    };
    struct node *head,*newnode,*temp;

    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;
}*/

void insert_value(struct node *head struct node*newnode struct node*temp){

}

void main(){
    struct node{
        int data;
        struct node* next;
    };
    struct node *head,*newnode,*temp;

    head=0;
    int choice,count;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to continue (0,1)? ");
        scanf("%d",&choice);
    }
    temp=head;

    while(temp!=0){
        printf("%d  ",temp->data);
        temp=temp->next;
        count++;
    }

    insert_begin();
    insert_end();

    while(temp!=0){
        printf("%d  ",temp->data);
        temp=temp->next;
        count++;
    }

    printf("no of nodes: %d",count);
    getch();
}
