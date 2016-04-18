#include "stdio.h"
//#include "iostream"
#include "string.h"
//#include "conio.h"

//using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *create(int *numnode)
{
    struct node *head,*tail,*cnew;
    head=NULL;
    int num;
    printf("end with 0");
    while(1)
    {
	scanf("%d",&num);
	if(num==0)
	{
	    break;
	}
	cnew=(struct node *)malloc(sizeof(struct node));
	cnew->data=num;
	cnew->next=NULL;
	if(head==NULL)
	{
	    head=cnew;
	}
	else
	    tail->next=cnew;
	tail=cnew;
	(*numnode)++;
	
    }
    return head;
}


int length(struct node *head)
{
    int n=0;
    struct node *p=NULL;
    p=head;
    while(p!=NULL)
    {
	p=p->next;	
	n++;
    }
    return n;
}


void show(struct node *head)
{
    struct node *p;
    if(head==NULL)
	
    {
	printf("null");
    }
    for(p=head;p!=NULL;p=p->next)
    {
	printf("%d",p->data);
    }
    printf("\n");
}


void main()
{
    struct node *head1;
    int n=0;
    head1=NULL;
    int numnode1=0;
    head1=create(&numnode1);
    show(head1);
    n=length(head1);
    printf("%d\n",n);
}
