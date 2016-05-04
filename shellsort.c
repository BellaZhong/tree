#include "stdio.h"

void shellsort1(int a[],int n)
{
    int i,j,k,gap,temp;
    for(gap=n/2;gap>0;gap=gap/2)
    {//gap narrows each time look through the array
	for(i=0;i<gap;i++)
	{//each time the start element of the group
	    for(j=i+gap;j<n;j+=gap)
	    {//the next element according to gap
		if(a[j]<a[j-gap])
		{
		    temp=a[j];
		    k=j-gap;//record the smallest one in the group but not change it
		    while(k>=0 && a[k]>temp)
		    {
			a[k+gap]=a[k];
			k-=gap;

		    }
		    a[k+gap]=temp;
		}
	    }
	}
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}


void shellsort2(int a[],int n)
{
    int j,k,gap,temp;
    for(gap=n/2;gap>0;gap=gap/2)
    {
	for(j=gap;j<n;j++)//from the last element of the group
	{//not from the start of each group
	    if(a[j]<a[j-gap])
	    {
		temp=a[j];		
		k=j-gap;
		while(k>=0 && a[k]>temp)
		{
		    a[k+gap]=a[k];
		    k-=gap;
		}	
		a[k+gap]=temp;		
	    }
	}
    }
    for(j=0;j<n;j++)
	printf("%d ",a[j]);
    printf("\n");
}

int main(void)
{
    int a[10]={49,38,65,97,26,13,27,49,55,4};
    shellsort1(a,10);
    shellsort2(a,10);
}
