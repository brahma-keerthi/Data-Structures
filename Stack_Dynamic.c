#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node * link;
};
typedef struct node * STK;

STK create(int item){
    STK new = (STK)malloc(sizeof(struct node));
    if(new == NULL){
        printf("MEMORY ERROR(#$");
        return NULL;
    }

    new->info = item;
    new -> link = NULL;
    return new;
}

void print(STK x){
    printf("STACK>>\n");
    STK temp = x;
    while(temp != NULL){
        printf("%d\n", temp->info);
        temp = temp->link;
    }
}

STK push(STK x, int item){
    STK new = create(item);
    new->link = x;
    return new;
}

STK peek(STK x){
    printf("TOP OF STACK >> %d\n", x->info);
    return x;
}

STK pop(STK x){
    if(x==NULL){
        printf("STACK EMPTY (UNDERFLOW)\n");
        return NULL;
    }

    printf("POPPED ELEMENT>> %d\n", x->info);
    STK temp = x->link;
    free(x);
    return temp;
}

void main(){
    STK first = NULL;
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