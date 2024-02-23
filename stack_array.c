#include<stdlib.h>
#include<stdio.h>

typedef struct Stack{
    int top;
    int size;
    int* array;
}stack;

stack* createStack(int size){
    stack* stk=(stack*)(malloc(sizeof(stack)));
    stk->top=-1;
    stk->size=size;
    stk->array=(int*)(malloc(sizeof(int)*size));
    return stk;

}

int isFull(stack* stk){
    return stk->top==stk->size-1;
}
int isEmpty(stack* stk){
    return stk->top==-1;
}
void push(stack* stk,int data){
    if(isFull(stk)) return;
    stk->array[++stk->top]=data;
}
int pop(stack* stk){
    if(isEmpty(stk)) return -1;
    return stk->array[stk->top--];
}
int peek(stack* stk){
    if(isEmpty(stk)) return -1;
    return stk->array[stk->top];
}

int main(){
    stack* stk=createStack(5);
    push(stk,3);
    push(stk,2);
    push(stk,1);
    push(stk,4);
    push(stk,5);
    printf("%d\n",peek(stk));
    for(int i=0;i<5;i++){
        printf("%d ",pop(stk));
    }
    printf("\n");
    printf("%d\n",peek(stk));

}