#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct node {
    int stack[SIZE];
    int tos;
};

typedef struct node * STK;

void print(STK x){
    printf("STACK>> \n");
    for(int i = x->tos; i>=0; i--)
        printf("%d\n", x->stack[i]);
}

STK push(STK x, int item){
    if(x->tos == SIZE -1 ){
        printf("STACK FULL (OVERFLOW)\n");
        return x;
    }

    x->stack[++x->tos] = item;
    return x;
}

STK peek(STK x){
    if(x->tos == -1) {
        printf("STACK has no elements\n");
        return x;
    }

    printf("TOP OF STACK >> %d\n", x->stack[x->tos]);
    return x;
}

STK pop(STK x){
    if(x->tos == -1){
        printf("STACK EMPTY (UNDERFLOW)\n");
        return x;
    }

    printf("POPPED ELEMENT >> %d\n", x->stack[x->tos--]);
    return x;
}

void main(){
    struct node STACK;
    STK first = &STACK;
    first->tos = -1;
    int item, choice;

    for(;;){
        printf("!!!___   STACK   ___!!!\n1. PUSH \n2. PEEK\n3. POP\n4. PRINT\n");
        printf("Enter choice>> ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter Element for Push operation>> ");
                scanf("%d", &item);
                first = push(first, item);
                print(first);
                break;
            
            case 2:
                first = peek(first);
                break;

            case 3:
                first = pop(first);
                print(first);
                break;

            case 4:
                print(first);
                break;

            default:
                exit(0);
        }
    }
}