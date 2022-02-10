// Binary search by recursion
#include<stdio.h>

int binary(int arr[], int key, int low, int high){
    int mid = (low+high)/2;
    if(key == arr[mid])
        return mid;

    else if(low>high)
        return -1;

    else if(key > arr[mid])
        binary(arr, key, mid+1, high);

    else
        binary(arr, key, low, mid-1);
}

void main(){
    int num ,key;
    printf("Enter the number of search items>> ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter the search elements>> ");
    for(int i = 0; i<num; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key element>> ");
    scanf("%d", &key);

    int flag = binary(arr, key, 0, num-1);

    if(flag!= -1){
        printf("Element %d found in %dth index", key, flag);
    }
    else
        printf("Element %d is not present in given elements", key);
}