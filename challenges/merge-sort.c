#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
    int i,j,k;
    int lengthL = m - l+1;
    int lengthR = r - m;
    //copy arrays
    int L[lengthL], R[lengthR];
    for(i = 0; i<lengthL; i++) L[i] = arr[l+i]; 
    for(j = 0; j<lengthR; j++) R[j] = arr[m+1+j];
    //Merge temp arrays
    i = 0;
    j = 0;
    k = l;
    while(i<lengthL&&j<lengthR){
        if(L[i]<R[j]){
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

void mergesort(int arr[], int l, int r){
    int m = (l+r)/2;
    if(l==r) return;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
    printf("%d ", A[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
  int arr[] = {85, 24, 63, 45, 17, 31, 96, 50};
  int size = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, size);
  mergesort(arr, 0, size-1); 
  printArray(arr, size);
}

