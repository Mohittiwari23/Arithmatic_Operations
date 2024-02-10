#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node *head=NULL;

void ins_beg(node *new1){
    node *temp=head;
    if(head==NULL){
        head=new1;
        head->next=head;
    }
    else{
        while(temp->next!=head)
            temp=temp->next;
        new1->next=head;
        temp->next=new1;
        head=new1;
    }
}
void ins_end(node *new1){
    node *temp=head;
    if(head==NULL){
        head=new1;
        head->next=head;
    }
    else{
        while(temp->next!=head)
            temp=temp->next;
        new1->next=head;
        temp->next=new1;
    }
}
void del_beg(){
    node* temp=head;
    node* temp1=head;
    if(head==NULL)
        printf("No nodes to delete!");
    else if(head->next==head){
        head=NULL;
        printf("Node Deleted!");
    }
    else{
        while(temp->next!=head)
            temp=temp->next;
        head=head->next;
        temp->next=head;
        free(temp1);
        temp1=NULL;
        printf("Node Deleted!");
    }
}
void del_end(){
    node* temp=head;
    node* temp1=head;
    if(head==NULL)
        printf("No nodes to delete!");
    else if(head->next==head){
        head=NULL;
        printf("Node Deleted!");
    }
    else{
        while(temp->next!=head)
            temp=temp->next;
        while(temp1->next!=temp)
            temp1=temp1->next;
        temp->next=NULL;
        temp1->next=head;
        free(temp);
        temp=NULL;
        printf("Node Deleted!");
    }
}
void traverse(){
    node*temp=head;
    if(head==NULL)
        printf("No nodes exist!");
    else{
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
}

int main(){
    node *new1;
    int choice;
   
    while(1){
	    printf("\nEnter the choice\n");
    	printf("1) ins_beg\n2) ins_end\n3) del_beg\n4) del_end\n5) traverse\n6) exit\n");
    	scanf("%d",&choice);
        switch(choice){
            case 1:
                new1=(node*)malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d",&new1->data);
                new1->next=NULL;
                ins_beg(new1);
                break;
            case 2:
                new1=(node*)malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d",&new1->data);
                new1->next=NULL;
                ins_end(new1);
                break;
            case 3:
                del_beg();
                break;
            case 4:
                del_end();
                break;
            case 5:
                traverse();
                break;
            default:
                exit(1);
        }
    }
}