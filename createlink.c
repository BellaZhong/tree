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


struct node *Insert(struct node *head, int num, struct node *addnode)
{
 struct node *p1;  /*p1保存当前需要检查的节点的地址*/ 
 int n=0;
 if (head == NULL) /*（结合图示7理解）*/
 {
  head = addnode;//it the link is empty
  addnode->next = NULL;
  n += 1;
  return head;
 } 
//if link is not empty
 p1 = head;
 while (p1->data != num && p1->next != NULL) /*p1指向的节点不是所要查找的，并且它不是最后一个节点，继续往下找*/
 {  
  p1 = p1->next; /*后移一个节点*/
 }
 
 if (num == p1->data) /*找到了（结合图示8理解）*/
 {//addnode insert after p1
  addnode->next = p1->next; /*显然node的下一节点是原p1的next*/
  p1->next = addnode; /*插入后，原p1的下一节点就是要插入的node*/
  n += 1; /*节点总数增加1个*/
 }
 else
 {
  printf(" %d not been found! ",n);
 }
 
 return head;
}

int main()
{
    struct node *head1, *head2, *head3;
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
    struct node* addnode=malloc(sizeof(struct node));
    addnode->data=9;
    head2=delete(x,head1);
    show(head2);
    head3=Insert(head2,3,addnode);
    show(head3);
    return 0;
}
