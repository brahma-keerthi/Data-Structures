#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>

struct node{
    char info;
    struct node * link;
};
typedef struct node* STK;

STK create(char item){
    STK new = (STK)malloc(sizeof(struct node));
    new -> info = item;
    new -> link = NULL;
    if(new == NULL){
        printf("MEMORY ERROR#@$*\n");
        return NULL;
    }
    return new;
}

STK push(STK x, char item){
    STK new = create(item);
    new -> link = x;
    return new;
}

STK pop(STK x){
    STK temp = x->link;
    free(x);
    return temp;
}

int pre(char i){
    if(i == '(' || i== '#') return 1;
    if(i == '+' || i== '-') return 2;
    if(i == '/' || i== '*') return 3;
    if(i == '^' || i== '$') return 4;
}

void main(){
    STK first = create('#');
    char a[20];
    printf("Infix expression>> ");
    gets(a);

    printf("Postfix expression>> ");

    for(int i = 0; i<strlen(a); i++){
        if(a[i] == ' ')
            continue;
            
        if(isalnum(a[i])==1){
            printf("%c", a[i]);
        }

        else if(a[i]=='('){
            first = push(first, '(');
        }

        else if(a[i] == ')'){
            while(first->info != '('){
                printf("%c", first->info);
                first = pop(first);
            }
            first = pop(first);
        }

        else if(isalnum(a[i]) != 1){
            if(pre(first->info) < pre(a[i]))
                first = push(first, a[i]);

            else{
                while(pre(first->info) >= pre(a[i])){
                    printf("%c", first->info);
                    first = pop(first);
                }
                first = push(first, a[i]);
            }
        }
    }
    while(first->info != '#'){
        printf("%c", first->info);
        first = pop(first);
    }
}