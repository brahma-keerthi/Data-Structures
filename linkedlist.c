
#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
NODE head = NULL;

struct node
{
    int data;
    NODE link;
};
NODE create(){
    NODE temp;
    int info;
    temp = (NODE )malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory allocation error!..");
        return temp;
    }
    temp->link=NULL;
    return temp;
    
}
void display(NODE p){
    printf("\n");
    while (p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->link;
    }
}
NODE orderedList(NODE first,int *p,int val){
	NODE prev,cur,newNode;
	cur=first;
	newNode= create();
	newNode->data=val;
	if(first==NULL){
		*p=*p+1;
		return newNode;
	}
	else if(newNode->data<=first->data){
		newNode->link=first;
		*p=*p+1;
		return newNode;
	}
	while(newNode->data>cur->data && cur->link!=NULL){
		prev=cur;
		cur=cur->link;
	}
	if(cur->link==NULL){
			cur->link=newNode;
			*p=*p+1;
			return first;
	}
	else{
		prev->link=newNode;
		newNode->link=cur;
		*p=*p+1;
		return first;
	}
}

NODE insAtBeg(NODE first,int *p,int val){
    NODE newNode = create();
    newNode->data=val;
    newNode->link=first;
    *p = *p+1;
    return newNode;
}
NODE insAtPos(NODE first,int pos,int *p,int val){
    NODE newNode,cur;
    int i=1;
    cur = first;
    
    if(pos<0 || pos>*p+1){
        printf("Invalid position number!...");
        return first;
    }
    newNode= create();
    newNode->data=val;
    while(i<pos-1){
        cur = cur->link;
        i++;
    }
    newNode->link= cur->link;
    cur->link=newNode;
    *p = *p+1;
    return first;
}
NODE insAtEnd(NODE first,int *p,int val){
    NODE temp,newNode;
    if(first==NULL){
        printf("Empty list..");
        return first;
    }
    newNode = create();
    newNode->data=val;
    temp= first;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newNode;
    *p = *p+1;
    return first;
}

NODE delAtBeg(NODE first,int *p){
    if(first!=NULL){
        NODE temp = first->link;
        free(first);
        *p = *p-1;
        printf("%d",*p);
        return temp;
    }
    printf("\nEmpty list\n");
    return first;
    
}

NODE delAtPos(NODE first,int pos,int *p){
    NODE newNode,cur,prev;
    int i=0;
    cur = first;
    prev=NULL;
    if(pos<0 || pos>*p){
        printf("Invalid position number!...");
        return first;
    }
    while(i<pos-1){
        prev=cur;
        cur = cur->link;
        i++;
    }
    prev->link=cur->link;
    free(cur);
    *p = *p-1;
    return first;
}

NODE delByVal(NODE first,int *p){
    NODE prev,cur,temp;
    int key;
    if(first==NULL){
        printf("Empty list..");
        return first;
    }
    printf("Enter the value to be deleted>>");
    scanf("%d",&key);
    cur= first;
    prev=NULL;
    if(first->data==key){
    	temp=first->link;
    	free(cur);
    	return temp;
    }
    while(cur!=NULL && cur->data!=key ){
        prev=cur;
        cur=cur->link;
    }
    if(cur!=NULL){
        prev->link=cur->link;
        free(cur);
        *p=*p-1;
         return first;
    }
    printf("Key not in the list.");
    return first;
}

NODE delAtEnd(NODE first,int *p){
    NODE prev,cur;
    if(first==NULL){
        printf("Empty list..");
        return first;
    }
    cur= first;
    prev=NULL;
    while(cur->link!=NULL){
        prev=cur;
        cur=cur->link;
    }
    prev->link=NULL;
    free(cur);
    *p=*p-1;
    return first;
}

NODE searchVal(NODE first){
    NODE prev,cur;
    int key;
    if(first==NULL){
        printf("Empty list..");
        return first;
    }
    printf("Enter the value to search>>");
    scanf("%d",&key);
    cur= first;
    prev=NULL;
    int i =1;
    while(cur!=NULL){
        if(cur->data==key){
            printf("The key found at position %d",i);
            return first;
        }
        else{
            prev=cur;
            cur=cur->link;
        }
    }
    printf("Key not found");
    return first;
}
NODE reverse(NODE first){
    NODE temp,cur;
    cur=NULL;
    while(first!=NULL){
        temp=first;
        first=first->link;
        temp->link=cur;
        cur=temp;
    }
    return cur;
}
NODE copy(NODE first){
	NODE second,temp,temp1,newNode;
	second=NULL;
	temp=first;
	temp1=NULL;
	while(temp!=NULL){
		newNode=create();
		printf("%p---",temp);
		printf("%d\n",temp->data);
		if(second==NULL){
			temp1=newNode;
			temp1->data=temp->data;
			temp=temp->link;
			second= temp1;
		}
		else{
			temp1->link=newNode;
			temp1=newNode;
			temp1->data=temp->data;
			temp=temp->link;
		}
	}
	return second;
	
}

void main(){
    NODE first=NULL,temp,cur,second=NULL;
    int ch,n=0,*ptr,pos,i,val;
    ptr=&n;
    for(;;){
        printf("\n1.Read\n2.Display\n3.Create ordered list\n4.Insert at beginning\n5.Insert at position\n6.Insert at end\n7.Delete the beginning\n8.Delete by pos\n9.Delete by value\n10.Delete the end\n11.Search by value\n12.Reverse the list\n13.Copy the list\n14.Update the value\n15.Exit\nEnter your choice>>");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:first=cur=NULL;printf("\nEnter the number of terms>>");scanf("%d",ptr);
                for(i=0;i<*ptr;i++){
                	printf("Enter the data>>");
    				scanf("%d",&val);
                    temp = create();
                    if(cur==NULL){
                    	temp->data=val;
                        cur=temp;
                        first=cur;
                    }
                    else{
                    	temp->data=val;
                        cur->link=temp;
                        cur =temp;
                    }
                    
                }
            break; 
        case 2:
        	display(first);
        	break;
        case 3:
        	printf("Enter the data>>");
    		scanf("%d",&val);
        	first=orderedList(first,ptr,val);
        	break;
        case 4:
        	printf("Enter the data>>");
    		scanf("%d",&val);
    		first = insAtBeg(first,ptr,val);
    		break;
        case 5:
        	printf("\nEnter the position to insert value>>");
            scanf("%d",&pos);
            printf("Enter the data>>");
    		scanf("%d",&val);
            first = insAtPos(first,pos,ptr,val);
                break;
        case 6:
        	printf("Enter the data>>");
        	scanf("%d",&val);
        	first = insAtEnd(first,ptr,val);
        	break;
        case 7:
        	first = delAtBeg(first,ptr);
        	break;
        case 8:
        	printf("\nEnter the position to delete its value>>");
            scanf("%d",&pos);first = delAtPos(first,pos,ptr);
            break;
        case 9:
        	first = delByVal(first,ptr);
        	break;
        case 10:
        	first = delAtEnd(first,ptr);
        	break;
        case 11:
        	searchVal(first);
        	break;
        case 12:
        	first=reverse(first);
        	break;
        case 13:	
        	first=reverse(first);
        	display(first);
        	second=copy(first);
        	display(second);
        	break;
        case 14://TODO 
        	printf("To be done");
        case 15:exit(0);
        default:exit(0);
        }
    }
}
