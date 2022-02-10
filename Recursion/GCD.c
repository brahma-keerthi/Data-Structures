// Finds the Greatest Common Divisor between 2 numbers
#include<stdio.h>

int gcd(int a, int b){
    if(a%b == 0)
        return b;

    gcd(b, a%b);
}
void main(){
    int a, b;
    printf("Enter 2 numbers whose GCD has to be calculated>> ");
    scanf("%d%d", &a, &b);

    printf("The GCD of %d and %d is>> %d", a, b, gcd(a, b));
}

// 2, 3 = 2 ==> gcd(2,3)
// 3, 2 = 1 ==> gcd(3,2)
// 2, 1 = 0 ==> gcd(2,1)
