#include "stdio.h"
//#include "stack"

//using namespace std;

struct node{
    int data;
    struct node *next;
};


void reverseshow(struct node *head)
{
    struct node *p=head;
    if(p!=NULL)
    {
	reverseshow(p->next);
	printf("%d	",p->data);
    }
}


struct node *Create()
{//创建一个链表
	struct node *head,*tail,*new;
	int n=0;
	head=NULL;
	tail=NULL;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0)
		break;
	    else
	    {
		new=(struct node*)malloc(sizeof(struct node));
		new->data=n;
		new->next=NULL;
		if(head==NULL)
		{
		   head=new;
		}
		else
			
		{
		    tail->next=new;
		}
		tail=new;//new node become the new tail
	    }
	}
    return head;
}


void show(struct node *head)
{
    struct node *p=head;
    while(p!=NULL)
    {
	printf("%d	",p->data);
	p=p->next;
    }
    printf("\n");
}



int main()
{
    struct node *newlist;
    int i=0;
    newlist=NULL;
    //struct node *newhead;
    //newhead=NULL;
    //for(i=0;i<5;i++)
    //{
    newlist=Create();

    //}
    show(newlist);
    reverseshow(newlist);
    return 0;
}
