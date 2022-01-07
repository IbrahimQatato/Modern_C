#include <stdlib.h>
#include <stdio.h>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;
    
    for(int j = low; j<high; j++){
        if (arr[j]<pivot){
            swap(arr, i, j);
            i++;
        }
    }

    swap(arr, i, high);
    return i;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
    printf("%d ", A[i]);
    printf("\n");
}

int checkOrder(int A[], int size){
    int i;
    for (i=0; i < size-1; i++){
    if(A[i]>A[i+1]) return 0;
    }
    return 1; 
}

int main(int argc, char *argv[]) {
  int arr[] = {10, 80, 30, 90, 40, 50, 70};
  int size = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, size);
  quickSort(arr, 0, size-1); 
  printArray(arr, size);
  if(checkOrder(arr, size)) printf("test passed\n");
  else printf("test failed\n");
}
