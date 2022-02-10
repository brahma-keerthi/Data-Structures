// 3432===> 2343 will reverse the number
#include<stdio.h>
#include<math.h>

int rev(int a){
    int dig = (int)log10(a); // To push number inside

    if(a%10==a)  // Base condition
        return a;

    return (a%10)*pow(10, dig) + rev(a/10);
}

void main(){
    int a;
    printf("Enter the number which has to be reversed>> ");
    scanf("%d", &a);

    printf("The reverse of %d is >> %d", a, rev(a));
}