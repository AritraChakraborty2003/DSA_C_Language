#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* insert_at_first(Node* head,int data){
	Node* temp=(Node*)(malloc(sizeof(Node)));
	temp->data=data;
	temp->next=head;
	head=temp;
	return head;

}

void printLL(Node* head){
	Node* p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

Node* mergeList(Node* h1,Node* h2){
    Node* p=h1;
    while(p->next!=NULL){
      p=p->next;
    }
    p->next=h2;
    return h1;
}
Node* insert_at_last(Node* head,int data){
	Node* temp=(Node*)(malloc(sizeof(Node)));
	temp->data=data;
	Node* p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=temp;
	temp->next=NULL;
	return head;

}

Node* insert_at_pos(Node* head,int data,int pos){
	Node* temp=(Node*)(malloc(sizeof(Node)));
	temp->data=data;
	Node* p=head;
	if(pos==1){
		temp->next=p;
		p=temp;
		return head;
	}
	else{
		for(int i=1;i<pos-1;i++){
			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
		return head;
	}
}
static void reverseList(Node** h){
	Node* prev=NULL;
	Node* next=NULL;
	Node* curr=*h;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;

	}
	*h=prev;

}
int main(){
	Node* head = (Node*)(malloc(sizeof(Node)));
	head->next=NULL;

	head=insert_at_first(head,23);
	head->next=NULL;
	head=insert_at_first(head,27);
	head=insert_at_first(head,39); 
	printLL(head);
	head=insert_at_last(head,21);
	printLL(head);
	reverseList(&head);
	printLL(head);

	/*head=insert_at_pos(head,31,3);
	printLL(head);*/
	
	

}