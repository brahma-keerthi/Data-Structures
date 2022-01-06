#include<stdio.h>
#include<stdlib.h>

int size = 0;

struct node {
    int info;
    struct node * link;
};
typedef struct node * NODE;

NODE create(int item){
    NODE new = (NODE)malloc(sizeof(struct node));
    new->info = item;
    new -> link = new;
    return new;
}

void print(NODE x){
    printf("\n");
    if(x==NULL || size == 0){
        printf("Empty List@)$(#");
    }
    NODE temp = x;
    int i =0;
    while(i<size){
        printf("%d   ->    ", temp->info);
        temp = temp->link;
        i++;
    }
    printf("\n");
}

NODE insertFront(NODE x, int item){
    NODE new = create(item);
    size++;
    if(x==NULL || size==0){
        return new;
    }

    NODE temp = x->link;
    x->link = new;
    new->link = temp;
    return x;
}

NODE insertRear(NODE x, int item){
    NODE new = create(item);
    size++;
    if(x==NULL|| size == 0){
        return new;
    }
    
    NODE temp = x->link;
    x->link = new;
    new->link = temp;
    return new;
}

NODE insertPos(NODE x, int pos, int item){
    if(pos>size+1 || pos<1){
        printf("Invalid Input#)#&");
        return x;
    }
    int i;
    NODE new = create(item);
    size++;
    NODE temp = x->link;
    NODE prev = NULL;
    if(pos==1){
        new->link = temp;
        x->link = new;
        return x;
    }
    for(i=1; i<pos; i++){
        prev = temp;
        temp = temp->link;
    }
    prev->link = new;
    new->link = temp;
    if(pos == size)
        return new;
    return x;
}

NODE deleteFront(NODE x){
    if(x==NULL|| size == 0){
        printf("Empty List#$*");
        return NULL;
    }
    size--;
    NODE temp = x->link->link;
    printf("The deleted node contains>> %d", x->link->info);
    free(x->link);
    x->link = temp;
    return x;
}

NODE deleteRear(NODE x){
    if(x==NULL || size == 0){
        printf("Empty List$&$");
        return NULL;
    }
    size--;
    NODE temp = x->link;
    while (temp->link != x){
        temp = temp->link;
    }
    temp->link = x->link;
    printf("The deleted node contains>> %d", x->info);
    free(x);
    return temp;   
}

NODE deletePos(NODE x, int pos){
    if(pos<1 || pos>size){
        printf("Invalid Input#(*&");
    }
    size--;
    NODE temp = x->link;
    NODE prev = NULL;

    if(pos==1){
        x->link = temp->link;
        printf("Deleted node contains>> %d", temp->info);
        free(temp);
        return x;
    }
    int i ;
    for(i=1; i<pos; i++){
        prev = temp;
        temp = temp->link;
    }
    prev->link = temp->link;
    printf("Deleted node contains>> %d", temp->info);
    if(size == 0 && pos == 1)
        return NULL;
    if(pos == size+1)
        return prev;
    return x;
}

NODE deleteValue(NODE x, int item){
    if(x == NULL || size== 0){
        printf("Empty List$*@");
        return NULL;
    }
    size--;

    NODE temp = x->link;
    NODE prev = x;
    while(temp->info != item && temp!=x){
        prev = temp;
        temp = temp -> link;
    }
    prev->link = temp->link;
    printf("Deleted node contains>> %d", temp->info);
    if(temp == x){
        free(temp);
        return prev;
    }
    free(temp);
    return x;
}

NODE search(NODE x, int item){
    if(x==NULL || size==0){
        printf("Empty List#*$\n");
    }
    NODE temp = x->link;
    int i = 0;
    while(temp->info != item && temp->link != x){
        temp = temp ->link;
        i++;
    }

    if(temp -> info == item){
        printf("%d is present at NODE %d\n", item, i+1);
        return x;
    }

    else{
        printf("%d is NOT PRESENT in list\n", item);
        return x;
    }
}

NODE copy(NODE x){
    if(x==NULL){
        printf("Empty list#($");
        return NULL;
    }
    NODE new, cur, temp, prev;
    temp = x->link;
    prev = x;
    cur = x->link;
    cur->link = temp->link;
    new = create(temp->info);
    while(temp!=x){
        temp = temp->link;
        prev = cur;
        cur = cur->link;
        new = create(temp->info);
        cur = new;
        cur -> link = temp->link;
    }
    return cur;
} 

NODE reverse(NODE x){
    if(x==NULL){
        printf("Empty List#&*");
        return x;
    }
    NODE cur, prev, next;
    cur = x->link;
    prev = x->link;
    next = cur->link;

    while(cur!=x){
        prev = cur;
        cur = next;
        next= cur->link;
        cur->link = prev;
    }
    next->link = x;
    return next;
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
                print(first->link);
                break;

            case 2:
                printf("Enter the data>> ");
                scanf("%d", &item);
                first = insertRear(first, item);
                print(first->link);
                break;

            case 3:
                printf("Enter the data>> ");
                scanf("%d", &item);
                printf("Enter the position>> ");
                scanf("%d", &pos);

                first = insertPos(first, pos, item);
                print(first->link);
                break;

            case 4:
                first = deleteFront(first);
                print(first->link);
                break;

            case 5:
                first = deleteRear(first);
                print(first->link);
                break;

            case 6:
                printf("Enter the position>> ");
                scanf("%d", &pos);

                first = deletePos(first, pos);
                print(first->link);
                break;

            case 7:
                printf("Enter the Data>> ");
                scanf("%d", &item);

                first = deleteValue(first, item);
                print(first->link);
                break;

            case 8:
                printf("Enter the data>> ");
                scanf("%d", &item);

                first = search(first, item);
                break;

            case 9:
                second = copy(first);
                printf("The copied list is >> \n");
                print(second->link);
                printf("\nOriginal list is>> \n");
                print(first->link);
                break;

            case 10:
                first = reverse(first);
                printf("\nThe reversed list is>>\n");
                print(first->link);
                break;

            case 11:
                print(first->link);
                break;

            default:
                exit(0);
            }
    }
}