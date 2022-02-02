#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct node{
    int a[30];
    int tos;
};
typedef struct node * STK;
STK stack;

void push(STK stack, int item){
    stack -> a[++stack -> tos] = item;
}

int pop(STK stack){
    return stack->a[stack->tos--];
}

void main(){
    stack = (STK)malloc(sizeof(struct node));
    stack -> tos = -1;
    char a[20];
    int n1, n2;
    printf("Postfix Expression>> ");
    gets(a);
    printf("RESULT>> ");

    for(int i = 0; i< strlen(a); i++){
        if(isdigit(a[i]))
            push(stack, a[i] - '0');

        else{
            n1 = pop(stack);
            n2 = pop(stack);

            switch (a[i]){
                case '+':
                    push(stack, n1 + n2);
                    break;

                case '-':
                    push(stack, n1 - n2);
                    break;

                case '*':
                    push(stack, n1 * n2);
                    break;

                case '/':
                    push(stack, n1 / n2);
                    break;

                default:
                    push(stack, pow(n1, n2));
                    break;
            } 
        }
    }
    printf("%d", stack->a[stack->tos]);
}