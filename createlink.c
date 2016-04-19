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
    printf("end with 0\n");
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


struct node *delete(struct node *x,struct node *head)  
{  
    struct node *node1=head;  
    struct node *node2=NULL;  
    if (head==NULL)  
    {  
        return NULL;  
    }   
    else  
    {  
        if (node1->data==x->data)  
        {  
            head=head->next;  
            free(node1);  
            return head;  
        }   
        else  
        {  
            while (node1!=NULL)  
            {  
                //node2=node1;  
                node2=node1->next;  
                if (node2->data==x->data)  
                {  
                    node1->next=node2->next;  
                    free(node2);  
                    break;  
                }  
                node1=node1->next;  
            }  
            return head;  
        }  
    }  
}  


int main()
{
    struct node *head1, *head2;
    int n=0;
    head1=NULL;
    int numnode1=0;
    head1=create(&numnode1);
    show(head1);
    n=length(head1);
    printf("%d\n",n);

    struct node* x = malloc(sizeof(struct node)); 
    x->data=1;
    //int delok=0;
    
    head2=delete(x,head1);
    show(head2);
    return 0;
}
