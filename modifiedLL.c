// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void printLL(node* h){
    node* it=h;
    while(it!=NULL){
        printf("%d ->",it->data);
        it=it->next;
    }
    printf("\n");
}

node* insert_at_begin(node* head,int data){
    node* temp=(node*)(malloc(sizeof(node)));
    temp->data=data;
    temp->next=head;
    head=temp;
    return head;
}

node* insert_at_pos(node* head,int pos,int data){
    node* temp=(node*)(malloc(sizeof(node)));
    temp->data=data;
    node* it=head;
    if(pos==1){
        temp->next=head;
        head=temp;
        return head;
    }
    else{
        for(int i=1;i<pos-1;i++){
            it=it->next;
        }
        temp->next=it->next;
        it->next=temp;
        return head;
    }
}


node* insert_at_end(node* head,int data){
    
    node* temp=(node*)(malloc(sizeof(node)));
    temp->data=data;
    node* it=head;
    while(it->next!=NULL){
        it=it->next;
    }
    it->next=temp;
    temp->next=NULL;
    return head;
}


node* delete_at_end(node* head){
    node* it=head;
    
    while(it->next->next!=NULL){
        it=it->next;
    }
    node* last=it->next;
    it->next=NULL;
    free(last);
    return head;
    
}
node* delete_at_beg(node* head){
    node* temp=head->next;
    head=NULL;
    free(head);
    return temp;
}

node* reverseLL(node* head){
    node* next=NULL;
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
       
    }
    head=prev;
    return head;
}

void main() {
    // Write C code here
    node* head=(node*)malloc(sizeof(node));
    head->data=12;
    head->next=NULL;
    printLL(head);
    head=insert_at_begin(head,17);
    head=insert_at_begin(head,23);
    printLL(head);

    head=insert_at_pos(head,3,19);
    printLL(head);
    
    head=insert_at_pos(head,3,18);
    printLL(head);
    
    head=insert_at_end(head,21);
    printLL(head);
    
    head=delete_at_end(head);
    printLL(head);
    
    
    head=delete_at_beg(head);
    printLL(head);
    
   head=reverseLL(head);
   printLL(head);
}