#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node*  prev;
    int data;
    struct Node* next;
}Node;

Node* insert_at_first(Node* head,int data){
    Node* temp=(Node*)(malloc(sizeof(Node)));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;

}
Node* insert_at_end(Node* head,int data){
    Node* temp=(Node*)(malloc(sizeof(Node)));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    Node* tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;

}


void printDLL(Node* head){
    Node* tp=head;
    while(tp!=NULL){
        printf("%d -><-",tp->data);
        tp=tp->next;
    }
    printf("\n");
}

Node* delete_at_end(Node* head){
    Node*tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->prev->next=NULL;
    free(tp);
    return head;

}

Node* delete_at_first(Node* head){
    Node*tp=head;
    head=head->next;
    head->prev=NULL;
    free(tp);
    return head;
}
void main(){
        Node* dHead=(Node*)(malloc(sizeof(Node)));
        dHead->prev=NULL;
        dHead->data=27;
        dHead->next=NULL;
       
        dHead=insert_at_first(dHead,25);
        dHead=insert_at_first(dHead,37);

        printDLL(dHead);
        dHead=insert_at_end(dHead,77);
        
        


        printDLL(dHead);

        delete_at_first(dHead);
        printDLL(dHead);  

        delete_at_end(dHead);
        printDLL(dHead);      
}