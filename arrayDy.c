#include<stdio.h>
#include<stdlib.h>
//#include<alloc.h>

void read(int arr[], int size){
	int i;
	printf("Enter the elements of the array>>");
	for(i=0;i<size; i++)
	scanf("%d", &arr[i]);
}

void display(int arr[], int size){
	int i;
	for(i=0; i<size; i++)
	printf("%d  ", arr[i]);
	
	printf("\n");
}

void search(int arr[], int size){
	int i=0, key;
	
	printf("Enter the key element to be searched>>");
	scanf("%d", &key);	
	
	for(i=0; i<size; i++){
		if(key == arr[i]){
			printf("The element found in index %d", i);
			printf("\n");
			return;
			}
	}
	printf("Element is not present in array");
	printf("\n");
}

void insertPos(int *ptr, int *size){
	int pos, key, i;
	printf("Enter the index of the array to where the element has to be added>>");
	scanf("%d", &pos);
	
	if(pos>*size || pos < 0){
		printf("Invalid Input\n");
		return;
		}
	
	printf("Enter the element>>");
	scanf("%d", &key);
	
	for(i=(*size-1); i>=pos; i--)
		*(ptr+i+1) = *(ptr+i);
		
	(*size)++;
	*(ptr+pos) = key;
}

void delEle(int *ptr, int *size){
	int key, i, j;
	printf("Enter the Element which has to be deleted>>");
	scanf("%d", &key);
	
	for(i=0; i<*size; i++){
		if(key == *(ptr+i))
			goto DEL;}
			
	printf("Invalid Input\n");
	return;
	
	DEL:
	for(i=0; i<*size; i++){
		if(key == *(ptr+i)){
			j = i;
			}
	}
	for(i=j; i<(*size); i++)
		*(ptr+i) = *(ptr+i+1);
		
	(*size)--;
	printf("Deleted Successfully\n");
	
}

void delPos(int *ptr, int *size){
	int j, i;
	printf("Enter the index which has to be deleted>>");
	scanf("%d", &j);
	
	if(j>*size || j<0){
		printf("Invalid Input\n");
		return;
		}
		
	for(i=j; i<(*size); i++)
		*(ptr+i) = *(ptr+i+1);
		
	(*size)--;
	printf("Deleted Successfully\n");
}

void sort(int *ptr, int size){
	int j, i;
	for(i=0; i<size-1; i++){
		for(j=0; j<size-1-i; j++){
			if(*(ptr+j) > *(ptr+j+1)){
				int temp = *(ptr+j+1);
				*(ptr+j+1) = *(ptr+j);
				*(ptr+j) = temp;}
				}
	}
	printf("Sorted Successfully\n");
}

	
void main(){
	int choice, n, key, pos, ele,i, *arr;

	
	for(;;){
	printf("___________________!!!!!!!!!!!!!!ARRAY FUNCTIONS!!!!!!!!!!!!!!!!__________________\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("The program will perform will following operations\n1.Read\n2.Display\n3.Search\n4.Insert\n5.Deletion by Value\n6.Deletion by Index\n7.Sorting the array\nOther num to exit\nEnter your choice>>");
	scanf("%d", &choice);
	
	switch (choice){
	
		case 1:
		printf("Enter the size of the array>>");
	    scanf("%d", &n);
	    
	    arr = (int *)calloc(n, sizeof(int));
	    
	    if( arr ==NULL){
	    	printf("MEMORY ERROR!!!");
	    	exit(0);
	    	}
			read(arr, n);
			break;
		case 2:
			display(arr, n);
			break;
		case 3:
			search(arr, n);
			break;
		case 4:
			arr = (int *)realloc(arr, (n+1)*sizeof(int));
			insertPos(arr, &n);
			display(arr, n);
			break;
		case 5:
			delEle(arr, &n);
			arr = (int *)realloc(arr, n*sizeof(int));
			display(arr, n);
			break;
		case 6:
			delPos(arr, &n);
			arr = (int *)realloc(arr, (n-1)*sizeof(int));
			display(arr, n);
			break;
		case 7:
			sort(arr, n);
			display(arr, n);
			break;
		default:
			exit(0);
		}
	}
}
