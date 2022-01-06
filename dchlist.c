// Doubly circular linked list with header node

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *rlink;
    struct node *llink;
};

typedef struct node * NODE;

NODE create(int item){
    NODE new = (NODE)malloc(sizeof(struct node));
    if(new == NULL){
        printf("MEMORY ERROR*#&");
        return NULL;
    }
    new -> rlink = new -> llink = new;
    new -> info = item;
    return new;
}

void print(NODE x){
    if(x->rlink == x){
        printf("Empty list($*&");
        return;
    }

    NODE temp = x->rlink;
    while(temp != x){
        printf("%d   ->   ", temp->info);
        temp = temp -> rlink;
    }
    printf("\n");
}

NODE insertFront(NODE x, int item){
    x->info++;
    NODE new = create(item);
    new -> llink = x;
    x->rlink ->llink = new;
    new->rlink = x->rlink;
    x->rlink = new;
    return x;
}

NODE insertRear(NODE x, int item){
    x->info ++;
    NODE new = create(item);
    new -> rlink = x;
    new ->llink = x->llink;
    x->llink->rlink = new;
    x->llink = new;
    return x;
} 

NODE insertPos(NODE x, int pos, int item){
    if(pos>x->info+1 || pos<1){
        printf("Invalid position#*&^");
        return x;
    }
    x->info ++;
    NODE temp = x->rlink;
    int i = 1;
    while(i<pos){
        temp = temp->rlink;
        i++;
    }
    NODE prev = temp->llink;
    NODE new = create(item);
    prev -> rlink = new;
    new ->llink = prev;
    new -> rlink = temp;
    temp -> llink = new;
    return x;
}

NODE deleteFront(NODE x){
    if(x->rlink == x){
        printf("Empty List#(*\n");
        return x;
    }
    x->info--;
    NODE prev = x;
    NODE temp = x->rlink;
    prev -> rlink = temp ->rlink;
    temp -> rlink ->llink = prev;
    printf("Deleted>> %d\n", temp->info);
    free(temp);
    return x;
}

NODE deleteRear(NODE x){
    if(x->rlink == x){
        printf("Empty List#(*\n");
        return x;
    }
    x->info--;
    NODE temp = x->llink;
    NODE prev = temp->llink;
    prev -> rlink = x;
    x->llink = prev;
    printf("Deleted>> %d\n", temp -> info);
    free(temp);
    return x;
}

NODE deletePos(NODE x, int pos){
    if(x->rlink == x){
        printf("Empty List#(*\n");
        return x;
    }

    if(pos>x->info || pos<1){
        printf("Invalid Input\n");
        return x;
    }
    int i=1;
    NODE temp = x->rlink;
    while(i<pos){
        temp = temp ->rlink;
        i++;
    }
    NODE prev = temp->llink;
    prev -> rlink = temp -> rlink;
    temp -> rlink ->llink = prev;
    x->info--;
    printf("Deleted >> %d\n", temp->info);
    free(temp);
    return x;
}

NODE deleteValue(NODE x, int item){
    if(x->rlink == x){
        printf("Empty List#(*\n");
        return x;
    }

    NODE temp = x->rlink;

    while(temp->info != item && temp->rlink != x){
        temp = temp -> rlink;
    }

    if(temp -> info == item){
        NODE prev = temp->llink;
        temp -> rlink -> llink = prev;
        prev -> rlink = temp -> rlink;
        printf("Deleted>> %d\n", temp->info);
        free(temp);
        x->info --;
        return x;
    }
    else{
        printf("%d is not present in list\n", item);
        return  x;
    }
}

NODE search(NODE x, int item){
    if(x->rlink == x){
        printf("Empty List#(*\n");
        return x;
    }

    NODE temp = x->rlink;
    int i = 1;
    while(temp->info != item && temp->rlink != x){
        temp = temp -> rlink;
        i++;
    }

    if(temp -> info == item){
        printf("The %d is present in >> %d node", temp->info, i);
        return x;
    }
    else{
        printf("%d is not present in list\n", item);
        return  x;
    }
}

NODE copy(NODE x){
    if(x->rlink==x){
        printf("Empty LIst&$(");
        return x;
    }

    NODE temp, prev, cur, next;
    temp = x;
    prev = x->llink;
    cur = x;
    next = x->rlink;

    while(cur->rlink != x){
        temp = create(cur->info);
        temp->llink = prev;
        temp->rlink = next;

        cur = next;
        prev = cur;
        next = next->rlink;
    }
    return next;
}

NODE reverse(NODE x){
    if(x->rlink==x){
        printf("Empty list#(*&$");
        return x;
    }

    NODE cur1, cur2, prev, next;

    cur1 = cur2 = x;
    prev = x->llink;
    next = cur1->rlink;

    while(cur1->rlink!=x){
        cur1->rlink = prev;
        cur2->llink = next;
        prev = cur1;
        cur1 = cur2 = next;
        next = next->rlink;
    }
    cur1->rlink = prev;
    prev->llink = cur1;
    x->rlink = cur1;
    return next;
}

void main(){
    int choice, pos, item;
    NODE first = create(0), second = NULL;

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
                printf("\nThe reversed list is>>\n");
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