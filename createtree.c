#include "stdio.h"


typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


BiTree CreateBiTree()
{
    char ch;
    BiTree T;
    scanf("%c",&ch);
    if(ch=='#')
	T=NULL;
    else
    {
	T=(BiTree)malloc(sizeof(BiTNode));
	T->data=ch;
	T->lchild=CreateBiTree();
	T->rchild=CreateBiTree();
    }
    return T;
}


int main()
{
    BiTNode *root=NULL;
    root=CreateBiTree();   
}
