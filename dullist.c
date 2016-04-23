#include "stdio.h"

struct lnode{
    int data;
    //int length;
    struct lnode *next;
    struct lnode *prior;
};


struct lnode *dellist(struct lnode *head,int x)
{
    struct lnode *delnode=head;
    struct lnode *delpre=head;
    
    while(x!=delnode->data)
    {
	delnode=delnode->next;
    }
    delpre=delnode->prior;
    delpre->next=delnode->next;
    return head;
}

struct lnode *addlist(struct lnode *head,struct lnode *addnode,int x)
{
    struct lnode *addtemp=head;
    struct lnode *addtemp2=head;
    while(x!=addtemp->data)
    {
	addtemp=addtemp->next;
    }
    addnode->next=addtemp->next;
    addnode->prior=addtemp;
    addtemp->next=addnode;
    addtemp2=addnode->next;
    addtemp2->prior=addnode;
    return head;
}

void printlist(struct lnode *dulhead)
{
    struct lnode *temp=dulhead;
    while(temp!=NULL)
    {
	printf("%d ",temp->data);
	temp=temp->next;
    }
    printf("\n");
}

struct lnode *dullist(struct lnode *dulhead)
{
    int n=0;
    struct lnode *p=dulhead;
    struct lnode *pnext=dulhead;
    struct lnode *new=NULL;
    struct lnode *tail=dulhead;
    printf("input number:\n");
    while(1)
    {
	scanf("%d",&n);
	if(n==0)
	{
	    break;

	}
	else
	{
	    new=(struct lnode*)malloc(sizeof(struct lnode));
	    new->data=n;
	    //new->prior=pnext;

	    if(pnext==NULL)
	    {
		new->prior=NULL;
		new->next=NULL;
		pnext=new;
		p=new;
		
	    }
	    else
	    {
		new->prior=pnext;
	        new->next=NULL;
	        pnext->next=new;
	        pnext=new;
	    }
	}
    }
    return p;
}

int main()
{
    struct lnode *dulhead=NULL;
    struct lnode *addnode=(struct lnode*)malloc(sizeof(struct lnode));
    //dulhead=(struct lnode*)malloc(sizeof(struct lnode));
    //dulhead->data=0;
    //dulhead->length=0;
    //dulhead->next=NULL;
    //dulhead->prior=NULL;
    addnode->data=6;
    dulhead=dullist(dulhead);
    printlist(dulhead);
    dulhead=addlist(dulhead,addnode,3);
    printlist(dulhead);
    dulhead=dellist(dulhead,3);
    printlist(dulhead);
    return 0;
}
