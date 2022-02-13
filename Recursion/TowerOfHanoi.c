#include<stdio.h>

void Tower(int num, char src, char inter, char des){
    if(num == 0){
        return;
    }

    Tower(num-1, src, des, inter);
    printf("Move %c to %c\n", src, des);
    Tower(num-1, inter, src, des);
}

void main(){
    int num;
    printf("Enter the number of discs>> ");
    scanf("%d", &num);

    Tower(num, 'A', 'B', 'C');
}