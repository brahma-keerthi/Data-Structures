// Doubly Linked List

#include<stdio.h>
#include<stdlib.h>
int size=0;
struct node{
    int info;
    struct node * rlink;
    struct node * llink;
};

typedef struct node * NODE;

NODE create(int item){
    NODE temp = (NODE)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("MEMORY ERROR@#*$");
        exit(0);
    }
    temp -> llink = temp-> rlink = NULL;
    temp->info = item;
    return temp;
}

void print(NODE x){
    int i=0;
    printf("\nfirst   ");
    for(i=0; i<size; i++){
        printf("->   %d   ", x->info);
        x = x->rlink;
    }
    printf("\n");
}

NODE insertFront(NODE x, int item){
    size++;
    NODE new = create(item);
    if(x==NULL){
        return new;
    }

    new -> rlink = x;
    x-> llink = new;
    return new;
}

NODE insertRear(NODE x, int item){
    size++;
    NODE new = create(item);
    if(x==NULL){
        return new;
    }
    NODE temp = x;
    while(temp -> rlink != NULL)
        temp = temp->rlink;
    new ->llink = temp;
    new -> rlink = NULL;
    temp->rlink = new;
    return x;
}

NODE insertPos(NODE x, int pos, int item){
    if(pos>size+1 || pos<1){
        printf("Invalid Position@)*$");
        return x;
    }
    size++;
    NODE new = create(item);
    NODE temp = x;
    int i ;
    if(temp == NULL){
        return new;
    }
    if(pos==1){
        new->rlink = temp;
        temp->llink = new;
        return new;
    }

    if(pos==size){
        while(temp->rlink != NULL)
            temp = temp->rlink;
        new->rlink = NULL;
        new ->llink = temp;
        temp -> rlink = new;
        return x;
    }

    for(i=1; i<pos; i++)
        temp = temp->rlink;
    NODE prev = temp->llink;
    prev->rlink= new;
    new ->llink = prev;
    new -> rlink = temp;
    temp->llink = new;

    return x;
}

NODE deleteFront(NODE x){
    if(x==NULL){
        printf("Empty list#*&");
        return x;
    }

    size--;
    NODE temp = x->rlink;
    temp->llink = NULL;
    printf("The deleted node contained>> %d", x->info);
    free(x);
    return temp;
}

NODE deleteRear(NODE x){
    if(x==NULL){
        printf("Empty list#)$");
        return x;
    }
    size--;
    NODE temp = x->rlink;
    while(temp->rlink != NULL)
        temp = temp->rlink;
    
    NODE prev = temp->llink;
    prev ->rlink = NULL;
    printf("The deleted node contains>> %d", temp->info);
    free(temp);
    return x;
}

NODE deletePos(NODE x, int pos){
    if(x==NULL){
        printf("Empty LIst #)*#&");
        return x;
    }

    if(pos > size || pos<1){
        printf("Invalid Position#)@#$");
        return x;
    }
    size--;
    int i;
    NODE temp = x;
    if(pos ==1 ){
        NODE y = temp->rlink;
        y -> llink = NULL;
        printf("The deleted node contains>> %d", temp->info);
        free(temp);
        return y;
    }

    for(i=1; i<pos; i++)
        temp = temp->rlink;

    if(pos==(size+1)){
        NODE prev = temp->llink;
        prev->rlink = NULL;
        printf("Deleted node contains>> %d", temp->info);
        free(temp);
        return x;
    }

    temp -> llink-> rlink = temp->rlink;
    temp -> rlink -> llink = temp -> llink;
    printf("The deleted node contains>> %d", temp->info);
    free(temp);
    return x;
}

NODE deleteValue(NODE x, int item){
    if(x==NULL){
        printf("Empty List@)$*");
        return NULL;
    }   

    size--;
    NODE temp = x;
    while(temp->info != item && temp->rlink != NULL)
        temp = temp->rlink;

    if(temp->info == item){
        if(temp->llink == NULL){
            NODE y = temp->rlink;
            printf("Deleted node contains>> %d", temp->info);
            free(temp);
            y->llink = NULL;
            return y;
        }

        if(temp->rlink == NULL){
            NODE y = temp->llink;
            y->rlink = NULL;
            printf("Deleted node contains>> %d", temp->info);
            free(temp);
            return x;
        }
        temp->llink ->rlink = temp->rlink;
        temp->rlink->llink = temp->llink;
        printf("The deleted node contains>> %d", temp->info);
        free(temp);
        return x;
    }

    else{
        printf("Data %d is not present is list", temp->info);
        return x;
    }
}

NODE search(NODE x, int item){
    if(x==NULL){
        printf("Empty List@)$*\n");
        return NULL;
    }   

    NODE temp = x;
    int i =1;
    while(temp->info != item && temp->rlink != NULL){
        temp = temp->rlink;
        i++;
    }

    if(temp->info == item){
        printf("The given data is present is node %d\n", i);
        return x;
    }

    else{
        printf("Data %d is not present is list\n", temp->info);
        return x;
    }
}

NODE copy(NODE x){
    if(x==NULL){
        printf("Empty LIst&$(");
        return NULL;
    }

    NODE temp, prev, cur, next, new;
    temp = x;
    new = temp;
    prev = x->llink;
    cur = x;
    next = x->rlink;

    while(cur->rlink != NULL){
        temp = create(cur->info);
        temp->llink = prev;
        temp->rlink = next;

        cur = next;
        prev = cur;
        next = next->rlink;
    }
    return new;
}

NODE reverse(NODE x){
    if(x==NULL){
        printf("Empty list#(*&$");
        return NULL;
    }

    NODE cur1, cur2, prev, next;

    cur1 = cur2 = x;
    prev = NULL;
    next = cur1->rlink;

    while(cur1->rlink!=NULL){
        cur1->rlink = prev;
        cur2->llink = next;
        prev = cur1;
        cur1 = cur2 = next;
        next = next->rlink;
    }
    cur1->rlink = prev;
    prev->llink = cur1;
    x->rlink = NULL;
    return cur1;
}

void main(){
    int choice, pos, item;
    NODE first = NULL, second = NULL;

    for(;;){
        printf("           MENU           \n");
        printf("1.Insert Front\n2.Insert Rear\n3.Insert by Position\n4.Delete Front\n5.Delete Rear\n6.Delete by Position\n7.Delete by Value\n8.Search by Value\n9.Copy List\n10.Reverse List\n11.Display List\nEnter your choice>> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data>> ");
                scanf("%d", &item);
                first = insertFront(first, item);
                print(first);
                break;

            case 2:
                printf("Enter the data>> ");
                scanf("%d", &item);
                first = insertRear(first, item);
                print(first);
                break;

            case 3:
                printf("Enter the data>> ");
                scanf("%d", &item);
                printf("Enter the position>> ");
                scanf("%d", &pos);

                first = insertPos(first, pos, item);
                print(first);
                break;

            case 4:
                first = deleteFront(first);
                print(first);
                break;

            case 5:
                first = deleteRear(first);
                print(first);
                break;

            case 6:
                printf("Enter the position>> ");
                scanf("%d", &pos);

                first = deletePos(first, pos);
                print(first);
                break;

            case 7:
                printf("Enter the Data>> ");
                scanf("%d", &item);

                first = deleteValue(first, item);
                print(first);
                break;

            case 8:
                printf("Enter the data>> ");
                scanf("%d", &item);

                first = search(first, item);
                break;

            case 9:
                second = copy(first);
                printf("The copied list is >> \n");
                print(second);
                printf("\nOriginal list is>> \n");
                print(first);
                break;

            case 10:
                first = reverse(first);
                printf("The reversed list is>> \n");
                print(first);
                break;

            case 11:
                print(first);
                break;

            default:
                exit(0);
            }
    }
}