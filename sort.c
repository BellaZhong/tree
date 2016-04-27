#include "stdio.h"

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
}
