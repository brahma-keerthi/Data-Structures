#include<stdio.h>
#include<stdlib.h>

struct node{  //Defining the structure
    int ex;
    int co;
    struct node * link;
};
typedef struct node * NODE;

NODE create(int ex, int co){  //Creates a new node
    NODE new = (NODE)malloc(sizeof(struct node));
    if(new==NULL){
        printf("MEMORY ERROR!@&*#");
        return NULL;
    }
    new->co = co;
    new->ex = ex;
    new->link = NULL;
    return new;
}

void print(NODE x){  //Printing the equation
    NODE temp = x;
    while(temp!=NULL){
        printf("(%2.d x^%2.d)  ", temp->co, temp ->ex);
        temp = temp->link;

        if(temp == NULL)
            printf("\n");
        else
            printf("+  ");
    }
}

NODE insert(NODE x, int ex, int co){  //order term based on decreasing order of exponent
    NODE new = create(ex, co);
    if(x==NULL || x->ex <= ex){
        new -> link = x;
        return new;
    }
    NODE temp = x;
    NODE prev = NULL;
    while(temp  != NULL && temp ->ex > ex){
        prev = temp;
        temp = temp->link;
    }
    prev-> link = new;
    new->link = temp;
    return x;
}

NODE read(NODE x, int size){  //Input the equation
    int ex, co;
    for(int i = 0; i<size; i++){
        printf("Co-efficient of term%d>>", i+1);
        scanf("%d", &co);

        printf("Exponent of term%d>>", i+1);
        scanf("%d", &ex);
        printf("\n");
        x = insert(x, ex, co);
    }
    return x;
}

NODE add(NODE p1, NODE p2){  //Adding polynomial
    NODE q1, q2, ans;
    q1 = p1;
    q2 = p2;
    ans = NULL;
    
    while(q1 != NULL && q2 != NULL){
        if(q1->ex == q2->ex){  //add if exponents are equal
            ans = insert(ans, q1->ex, q1->co + q2->co);
            q1 = q1->link;
            q2 = q2 -> link;
        }

        else if(q1->ex > q2->ex){  //if exponent of any is large insert node to result
            ans = insert(ans, q1->ex, q1->co);
            q1 = q1->link;
        }

        else if(q2->ex > q1->ex){  //if exponent of any is large insert node to result
            ans = insert(ans, q2->ex, q2->co);
            q2 = q2->link;
        }
    }

    if(q1 == NULL){ //if list finishes insert other list to result
        while(q2 != NULL){
            ans = insert(ans, q2->ex, q2->co);
            q2 = q2->link;
        }
    }

    if(q2 == NULL){ //if list finishes insert other list to result
        while(q1 != NULL){
            ans = insert(ans, q1->ex, q1->co);
            q1 = q1->link;
        }
    }
    return ans;
}

void main(){
    NODE p1 , p2, p3;
    p1 = p2 = p3 = NULL;
    int size ;
    printf("____!!!!ADDITION OF TWO POLYNOMIALS OF SAME VARIABLES!!!!____\n");

    printf("Enter the size of polynomial: 1>>");
    scanf("%d", &size);
    printf("Enter Polynomial: 1>> \n");
    p1 = read(p1, size);

    printf("Enter the size of polynomial: 2>>\n");
    scanf("%d", &size);
    printf("Enter Polynomial: 2>> \n");
    p2 = read(p2, size);

    printf("Polynomial: 1>>   ");
    print(p1);
    printf("Polynomial: 2>>   ");
    print(p2);

    p3 = add(p1, p2);
    printf("Polynomial: ans>> ");
    print(p3);
}