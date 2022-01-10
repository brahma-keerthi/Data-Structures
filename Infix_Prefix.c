#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct node {
    char info;
    struct node * link;
};
typedef struct node * STK;

void print(STK first){
    STK x = first;
    while(x != NULL){
        printf("%c", x->info);
        x = x->link;
    }
}

STK push(STK x, char item){
    STK new = (STK)malloc(sizeof(struct node));
    new -> info = item;
    if(x==NULL){
        new -> link = NULL;
        return new;
    }
    new -> link = x;
    return new;
}

STK pop(STK x){
    STK y = x->link;
    free(x);
    return y;
}

int pre(char a){
    if(a==')' || a=='#') return 1;
    if(a=='+' || a=='-') return 2;
    if(a=='/' || a=='*') return 3;
    if(a=='$'|| a=='^') return 4;
}

void main(){
    STK first = (STK)malloc(sizeof(struct node));
    first -> link = NULL; first ->info = '#';
    STK second = NULL;
    char a[20];
    printf("Infix Expression>> ");
    gets(a);
    printf("Prefix Expression>> ");

    for(int i= strlen(a)-1; i>=0; i--){
        if(isalnum(a[i]) == 1){
            second = push(second, a[i]);
        }

        else if(a[i] == ')'){
            first = push(first, a[i]);
        }

        else if(a[i]=='('){
            while(first->info != ')'){
                second = push(second, first->info);
                first = pop(first);
            }
            first = pop(first);
        }

        else if(isalnum(a[i])!=1){
            if(pre(a[i])>pre(first->info))
                first = push(first, a[i]);

            else{
                while(pre(a[i])<=pre(first->info)){
                    second = push(second, first->info);
                    first = pop(first);
                }
                first = push(first, a[i]);
            }
        }
    }
    while(first->info != '#'){
        second = push(second, first->info);
        first  = pop(first);
    }
    print(second);
}
