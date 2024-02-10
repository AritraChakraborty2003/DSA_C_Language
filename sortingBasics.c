// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int a[]={3,6,7,1,2,5};
    bubbleSort(a,6);
    printf("By Bubble Sort...\n");
    printArray(a,6);
    
    insertionSort(a,6);
    printf("By Insertion Sort...\n");
    printArray(a,6);
    
    
       
    selectionSort(a,6);
    printf("By Selection Sort...\n");
    printArray(a,6);
    
    
    return 0;
}
void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) swap(a,i,j);
        }
    }
}

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        
        a[j+1]=key;
    }
}

void selectionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(a,min,i);
        }
    }
}