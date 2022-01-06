#include<stdio.h>
#include<stdlib.h>

struct timm {
	int hr;
	int min;
	int sec;
};

typedef struct timm TIME;
typedef struct timm * clock;

void read(clock t){
	printf("Enter the time in format \'hh:mm:ss\'>> ");
	scanf("%d:%d:%d", &(t->hr), &(t->min), &(t->sec));
	printf("READ SUCCESSFULLY\n");
}

void display(clock t){
	printf("The time is \n %d:%d:%d\n", t->hr, t->min, t->sec);
}

void update(clock t){
	(t->sec)++;
	if(t->sec==60){
		(t->min)++;
		t->sec = 0;
	}
	
	if(t->min == 60){
		(t->hr)++;
		t->min = 0;
	}
	
	if(t->hr == 24){
		t->hr =0;
		t-> sec=0;
		t->min = 0;
	}
	
	printf("The time after updation by 1 sec is\n %d:%d:%d\n", t->hr, t->min, t->sec);
}

void add(TIME t1, TIME t2){
	TIME t;
	
	t.sec = t1.sec + t2.sec;
	
	if(t.sec>=60){
		t.sec = t.sec - 60;
		(t1.min)++;
	}
	
	t.min = t1.min + t2.min;
	
	if(t.min>=60){
		t.min = t.min - 60;
		(t1.hr)++;
	}
	
	t.hr = t1.hr + t2.hr;
	
	printf("The time after addition is\n%d:%d:%d\n", t.hr, t.min, t.sec);
	
}

void main(){
	int i, choice;
	TIME time, t1, t2;
	clock ptr;
	ptr = &time;
	
	for(;;){
	printf("--------------------!!!!!CLOCK!!!!!-----------------------\n");
	printf("__________________________________________________________\n");
	printf("1.Read time\n2.Display time\n3.Update time\n4.Add time\nOther num to exit\nEnter your choice>> ");
	scanf("%d", &choice);
	
	switch (choice) {
		case 1:
			read(&time);
			break;
			
		case 2:
			display(&time);
			break;
			
		case 3:
			update(&time);
			break;
			
		case 4:
			read(&t1);
			read(&t2);
			add(t1, t2);
			break;
			
		default:
			exit(0);
	}
	}
}
