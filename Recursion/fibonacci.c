// 1, 1, 2, 3, 5, .......
#include<stdio.h>

int fib(int a){
    if(a==1 || a==2)
        return 1;
    
    return fib(a-2) + fib(a-1);
}

void main(){
    int a;
    printf("Enter the nth term which has to be displayed>> ");
    scanf("%d", &a);

    printf("%d term in series is >> %d", a, fib(a));
}