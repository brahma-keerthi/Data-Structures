#include<stdio.h>
#include<stdlib.h>

struct student{
	char name[50];
	int roll ;
	int m[3];
	float av;
};

typedef struct student STD;

void read(STD *arr, int a){
	int i, j;
	
	for(i=0; i<a; i++){
		printf("Enter the Details of student %d>>\n", i+1);
		printf("Enter the name of Student>>");
		scanf("%s",&((arr+i)->name));
		
		printf("Enter the Roll of Student>>");
		scanf("%d", &((arr+i)->roll));
		
		printf("Enter the marks in each Subject\n");
		for(j =0; j<3; j++){
			printf("Enter the marks of sub%d>>", j+1);
			scanf("%d", &((arr+i)->m[j]));
		}
	}
}

void display(STD *arr, int a){
	int i, j;
	
		printf("Roll No.              Name                    Sub 1                Sub 2            Sub 2\n");
		for(i=0; i<a; i++){
		printf("  %2d                   %s                       %3d                  %3d                %3d\n", (arr+i)->roll, (arr+i)->name, (arr+i)->m[0], (arr+i)->m[1], (arr+i)->m[2]);}
}

void ave(STD *p, int a){
	int i,j, min;
	for(i=0;i<a;i++){
		min = ((p+i)->m[0]);
		if(min>((p+i)->m[1])){
			min=((p+i)->m[1]);
		}else if(min>((p+i)->m[2])){
			min=((p+i)->m[2]);
		}
		((p+i)->av) = (((p+i)->m[0])+((p+i)->m[1])+((p+i)->m[2])-min)/2;
	}
	
	for(j=0; j<a; j++){
		printf("Average marks of Student is %f\n", (p+j)-> av);
}}

void main(){
	int choice, n;
	STD *st;
	for(;;){
	printf("---------------------------------!!!!!!!STUDENT RECORD!!!!!!!----------------------------------\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("1.ENTER DETAILS\n2.EXTRACT DETAILS\n3.CALCULATE\nEnter your choice>> ");
	scanf("%d", &choice);
	
	switch (choice){
		case 1:
			printf("Enter the number of students: ");
			scanf("%d", &n);
			st = (STD *)calloc(n, sizeof(STD));
			
	        read(st,n);
	        break;
	        
	    case 2:
	    	display(st, n);
	    	break;
	    	
		case 3:
			ave(st, n);
			break;
			
		default:
			exit(0);
	        
	   }
	}
}
