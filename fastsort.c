#include "stdio.h"


void quicksort(int a[],int low, int high)
{
    int i=low;
    int j=high;
    int temp=a[i];
    if(low<high)
    {
	while(i<j)
	{
	    while((a[j]>=temp) && (i<j))
	    {
		j--;
	    }
	    a[i]=a[j];//put the smaller one on a[i]
	    //and a[i]>temp || i=j at this time
	    //so it won't go to the next while below
	    while((a[i]<=temp) && (i<j))
	    {
		i++;
	    }
	    a[j]=a[i];
	}
	a[i]=temp;
	quicksort(a,low,i-1);
	quicksort(a,j+1,high);
    }
}


void printarray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
	printf("%d ",a[i]);

    }
    printf("\n");
}


int main()
{
    int a[10]={3,9,0,6,5,2,1,8,7,4};
    quicksort(a,0,10-1);
    printarray(a,10-1);
}
