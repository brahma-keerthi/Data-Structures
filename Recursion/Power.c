// x power y ==> pow(x, y)
#include<stdio.h>

int power(int x, int y){
    if(y == 0)
        return 1;

    if(y == 1)
        return x;

    return x * power(x, y-1);
}

void main(){
    int x, y;
    printf("Enter the base>> ");
    scanf("%d", &x);

    printf("Enter the power>> ");
    scanf("%d", &y);

    printf("%d^%d is>> %d", x, y, power(x,y));
}