#include "stdio.h"



struct node{
    int data;
    struct node *next;
};


struct node *dellist(struct node *head,int num)
{
    struct node *p=head;
    struct node *q=head;
    if(head->data==num)
    {
	head=head->next;
	return head;
    }   
    else
    {
	p=q->next;// point to the next behind head node
	while(num!=p->data)
	{
	    q=q->next;//p is always point to q's next node
	    p=q->next;
	}
	q->next=p->next;		
    }
    return head;
}


void searchmid(struct node *head)  
{  
    //判断空链表、单节点链表  
    if(NULL == head || NULL == head->next)  
    {  
        return head;  
    }  
    struct node *p1  = head;
    struct node *p2=head;  
    while(NULL != p2->next && NULL != p2->next->next )  
    {  
        p2 = p2->next->next;  
        p1 = p1->next;  
    }  
    printf("%d\n",p1->data);  
} 


void searchmid2(struct node *head,struct node *mid)
{
    struct node *temp=NULL;
    temp=head;
    mid=head;
    while(temp->next->next!=NULL && temp->next!=NULL)
    {
	temp=temp->next->next;
	mid=mid->next;
	//mid=(struct node*)malloc(sizeof(struct node));
	//mid=temp;
    }
    printf("%d\n",mid->data);
}


void show(struct node *head)
{
    struct node *p=head;
    int i=0;
    while(p!=NULL)
    {
	printf("%d ",p->data);
	p=p->next;
    }
    printf("\n");
}


struct node *newlist()
{
    int n=0;
    struct node *head, *tail, *lnew;
    //head=(struct node*)malloc(sizeof(struct node));
    //tail=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    tail=NULL;
    //lnew=(struct node*)malloc(sizeof(struct node));
    printf("input number in the list:\n");
    while(1)
    {
	scanf("%d",&n);
	if(n==0)
	    break;
	//everytime you enter a number
	//you'll need a new space to save it
	//save the structure
        lnew=(struct node*)malloc(sizeof(struct node));
	    lnew->data=n;
	    lnew->next=NULL;
	    if(head==NULL)
	    {
		head=lnew;
	    }	    
	    else
	    {
		tail->next=lnew;
	    }
	    tail=lnew;

		
    }
    return head;
}

int main()
{
    //struct node *head=(struct node*)malloc(sizeof(struct node));
    //struct node *mid=(struct node*)malloc(sizeof(struct node));
    struct node *head=NULL;
    
    head=newlist();
    show(head);
    searchmid(head);
    head=dellist(head,1);
    show(head);   
}











