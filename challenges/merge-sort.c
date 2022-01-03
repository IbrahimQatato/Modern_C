#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char* arr[], int l, int m, int r){
    int i,j,k;
    int lengthL = m - l+1;
    int lengthR = r - m;
    //copy arrays
    char* L[lengthL];
    char* R[lengthR];
    for(i = 0; i<lengthL; i++) L[i] = arr[l+i]; 
    for(j = 0; j<lengthR; j++) R[j] = arr[m+1+j];
    //Merge temp arrays
    i = 0;
    j = 0;
    k = l;
    while(i<lengthL&&j<lengthR){
        if(strcmp(L[i],R[j])<0){
            arr[k] = L[i]; 
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    } 
    // Copy the remaining elements of L[]
    while (i < lengthL){
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[]
    while (j < lengthR){
        arr[k] = R[j];
        j++;
        k++;
    }  
}

void mergesort(char* arr[], int l, int r){
    int m = (l+r)/2;
    if(l==r) return;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
}

void printArray(char* A[], int size){
    int i;
    for (i=0; i < size; i++)
    printf("%s ", A[i]);
    printf("\n");
}

int checkOrder(char* A[], int size){
    int i;
    for (i=0; i < size-1; i++){
    if(strcmp(A[i],A[i+1])>0) return 0;
    }
    return 1; 
}

int main(int argc, char *argv[]) {
  char* arr[] = {"blabla", "asd", "zen", "fruru"};
  int size = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, size);
  mergesort(arr, 0, size-1); 
  printArray(arr, size);
  if(checkOrder(arr, size)) printf("test passed\n");
  else printf("test failed\n");
}

