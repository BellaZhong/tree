#include "stdio.h"

void selectsort(int array[],int length)
{
    int i,j=0;
    int temp=0;
    int index=0;
    for(i=0;i<length-1;i++)
    {
	temp=0;
	index=i;
	for(j=i+1;j<length;j++)
	{
	    if(array[index]>array[j])
		index=j;
	}
	temp=array[index];
	array[index]=array[i];	
	array[i]=temp;	
    }
    for(i=0;i<length;i++)
	printf("%d ",array[i]);
    printf("\n");
}


void bubblesort(int array[],int length)
{
    int i,j=0;
    int temp=0;
    for(i=0;i<length-1;i++)
    {
	for(j=i;j<length;j++)
	{
	    if(array[i]>array[j])
	    {
		temp=array[i];		
		array[j]=array[i];
		array[i]=temp;
	    }
	}
    }
    for(i=0;i<length;i++)
	printf("%d ",array[i]);
    printf("\n");
}


void insertsort(int array[],int length)
{
    int i,j=0;
    int temp=array[0];
    int index=0;
    for(i=1;i<length;i++)
    {
        temp=array[i];
	j=i;
	while(j>0 && array[j-1]>temp)
	{
	    array[j]=array[j-1];
	    j--;
	}
	array[j]=temp;
    }
    for(i=0;i<length;i++)
	printf("%d ",array[i]);
    printf("\n");
}

int main()
{
    int a[7]={9,4,5,6,7,2,3};
    insertsort(a,7);
    bubblesort(a,7);
    selectsort(a,7);
}
