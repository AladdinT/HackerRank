#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int* declare_arr(int n){
    int* arr = NULL;
    int size = (n*2)-1;
    arr = (int*) malloc( (size)*sizeof(int) );
    
    
    return arr;
}
void init_arr(int arr[], int n){
    int size = (n*2)-1;
    for(int i=0; i<size ; i++){
        arr[i] = n;
    }
}
void print_arr(int arr[], int n){
    int size = (n*2)-1;
    for(int i=0; i<size ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void dec_array(int arr[], int n, int order){
    int size = (n*2)-1;
    for(int i=order ; i< size-order ; i++){
        arr[i] --;
        
    }
    print_arr(arr, n);
    /*for(int j=0 ; j<size ; j++){
        printf("%d ", arr[j]);    
    }
    printf("\n");*/
}
void pyr_arr(int arr[], int n, int order){
    int size = (n*2)-1;
    for(int i=0 ; i<order ; i++){
        arr[n-1+i]++;
        if(i!=0){
            arr[n-1-i]++;
        }
    }
}
int main() 
{

    int n;
    int *arr;
    scanf("%d", &n);
    arr = declare_arr(n);
    init_arr(arr, n);
    print_arr(arr, n);
    for(int i=0 ; i<n-1 ; i++){
        dec_array(arr , n, i+1);
        
    }
    for(int j=0 ; j<n-1 ; j++){
        pyr_arr(arr, n, j+1);
        print_arr(arr, n);
    }
    return 0;
}