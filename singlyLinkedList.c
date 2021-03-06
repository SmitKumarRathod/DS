#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node L;
L* add(L* h);
L* addAfter(L* h);
L* addAtFirst(L* h);
L* delAtLast(L* h);
L* del_at_loc(L* h);
L* delFirst(L* h);
void view(L* h);
L* sort_ll(L* h);
L* del_ll(L* h);

int main(){
	L* head=NULL;
    int opt;
    do{
        printf("\n MENU:- ");
        printf("\n 1) Add an Element in list:- ");
        printf("\n 2) Add an Element at First:- ");
        printf("\n 3) Add an Element after a specific location:- ");
		    printf("\n 4) Delete first Element:- ");
        printf("\n 5) Delete Last Element:- ");
        printf("\n 6) Delete an Element at given location:- ");
        printf("\n 7) View:- ");
        printf("\n 8) Sort the list:- ");
        printf("\n 9) Delete the list:- ");
        printf("\n 10) Exit:- ");

        printf("\n Select your options:- ");
        scanf("%d",&opt);
        switch(opt){
            case 1:head=add(head); break;
            case 2:head=addAtFirst(head); break;
            case 3:head=addAfter(head); break;
            case 4:head=delFirst(head); break;
            case 5:head=delAtLast(head); break;
            case 6:head=del_at_loc(head); break;
            case 7:view(head); break;
            case 8:head=sort_ll(head); break;
            case 9:head=del_ll(head); break;
            case 10:exit(0);

        }
    }while(opt!=10);
    return 0;
}

L* add(L* h){
    L* cur=h;
        if(h==NULL){
            h=(L*)malloc(sizeof(L));
            cur=h;
        }
        else{
            while(cur->next!=NULL)
                cur=cur->next;
            cur->next=(L*)malloc(sizeof(L));
            cur=cur->next;
        }
            printf("\n Enter a DATA:- ");
            scanf("%d",&cur->data);
			cur->next=NULL;
    return h;
}

void view(L*h){
    L* cur=h;
    if(h==NULL)
    	printf("\n\n LIST IS EMPTY!");
    while(cur!=NULL){
        printf("\n DATA:- %d",cur->data);
        cur=cur->next;
    }
}

L* delAtLast(L* h){
	L* cur=h;
	while(cur->next->next!=NULL)
		cur=cur->next;
	cur->next=NULL;
	return h;
}

L* addAtFirst(L* h){
	L* cur=h;
	cur=(L*)malloc(sizeof(L));
	printf("\n Enter a DATA:- ");
	scanf("%d",&cur->data);
	cur->next=h;
	h=cur;
	return h;
}

L* del_at_loc(L* h){
	L* cur=h;
	int key;
	printf("\n\n Enter a value you want to delete:- ");
	scanf("%d",&key);
	while(cur->next->data!=key)
		cur=cur->next;
	cur->next=cur->next->next;
	return h;
}

L* delFirst(L* h){
	L* cur=h;
	cur=cur->next;
	h=cur;
	return h;
}

L* addAfter(L* h){
	L* cur=h,*temp;
	int key;
	printf("\n Enter a value after you want to enter a DATA:- ");
	scanf("%d",&key);
	temp->next=(L*)malloc(sizeof(L));
	while(cur->data!=key)
		cur=cur->next;
	temp->next=cur->next;
	cur->next=temp;
	printf("\n Enter a DATA:- ");
	scanf("%d",&temp->data);
	return h;
}

L* del_ll(L* h){
	printf("\n List is being Deleted......");
	h=NULL;
	printf("\n List is deleted! \n Check by view Option!");
	return h;
}

L* sort_ll(L* h){
	L* cur=h;
	int temp;
	while(cur->next!=NULL){
		if(cur->data>cur->next->data){
			temp=cur->next->data;
			cur->next->data=cur->data;
			cur->data=temp;
		}
		cur=cur->next;
	}
	return h;
}
