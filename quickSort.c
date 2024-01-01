#include<stdio.h>
#include<stdlib.h>

void printArray(int a[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

int partition(int a[],int l,int h){
    int pivot=a[l];
    int i=l;
    int j=h;
    while(j>i){
    while(i<=h && a[i]<=pivot) i++;
    while(j>=l && a[j]>pivot) j--;
    if(j>i){
        swap(a,i,j);
    }
    } 
    swap(a,j,l);
    return j;
}
void quickSort(int a[],int l,int h){
    if(l<h){
    int pivot=partition(a,l,h);
    quickSort(a,l,pivot-1);
    quickSort(a,pivot+1,h);
    }
}


void main(){
    int a[]={3,7,9,1,5,2,4};
    quickSort(a,0,6);
    printArray(a,7);
}