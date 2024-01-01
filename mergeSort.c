#include<stdio.h>
#include<stdlib.h>

void printArray(int a[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void Merge(int a[],int l,int m,int h){
    int n1=m-l+1; int n2=h-m;
    int i;
    int j;
    int left[n1]; int right[n2];
    for(i=0;i<n1;i++)
        left[i]=a[l+i];
    for(j=0;j<n2;j++)
        right[j]=a[m+1+j];
    i=0;j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            a[k++]=left[i++];
        }
        else{
            a[k++]=right[j++];
        }
    }

    while(i<n1){
        a[k++]=left[i++];
    } 
    while(j<n2){
        a[k++]=right[j++];
    }
    
}
void MergeSort(int a[],int l,int h){
    if(h>l){
        int mid=l+(h-l)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,h);
        Merge(a,l,mid,h);
    }
}

void main(){
    int a[]={3,7,9,1,5,2,4};
    MergeSort(a,0,6);
    printArray(a,7);
}
