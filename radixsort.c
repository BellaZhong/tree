#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "assert.h"
void radixsort(int array[],int length);
int pre_process_data(int array[], int length, int weight); 
void sort_for_basic_number(int array[], int length, int swap[]);
void sort_data_by_basic_number(int array[], int data[], int swap[], int length, int weight);




    int pre_process_data(int array[], int length, int weight)  
    {  
        int index ;  
        int value = 1;  
      
        for(index = 0; index < weight; index++)  
            value *= 10;  
      
        for(index = 0; index < length; index ++)  
            array[index] = array[index] % value /(value /10);  
      
        for(index = 0; index < length; index ++)  
            if(0 != array[index])  
                return 1;  
      
        return 0;  
    }  



void sort_for_basic_number(int array[], int length, int swap[])  
{  
    int index;  
    int basic;  
    int total = 0;  
  
    for(basic = -9; basic < 10; basic++){  
        for(index = 0; index < length; index++){  
            if(-10 != array[index] && basic == array[index] ){  
                swap[total ++] = array[index];  
                array[index] = -10;  
            }  
        }  
    }  
  
    memmove(array, swap, sizeof(int) * length);  
} 





    void sort_data_by_basic_number(int array[], int data[], int swap[], int length, int weight)  
    {  
        int index ;  
        int outer;  
        int inner;  
        int value = 1;  
      
        for(index = 0; index < weight; index++)  
            value *= 10;  
      
        for(outer = 0; outer < length; outer++){  
            for(inner = 0; inner < length; inner++){  
                if(-10 != array[inner] && data[outer]==(array[inner] % value /(value/10))){  
                    swap[outer] = array[inner];  
                    array[inner] = -10;  
                    break;  
                }  
            }  
        }  
      
        memmove(array, swap, sizeof(int) * length);  
        return;  
    }





void radixsort(int array[],int length)
{
    int *pData;
    int weight=1;
    int count;
    int *swap;
    int i,j,k=0;    
    if(NULL==array || 0==length)
        printf("no array!");
    pData=(int *)malloc(sizeof(int) * length);
    assert(NULL!=pData);
    //for(i=0;i<length;i++)
    //	*(pData+i)=array[i];
    memmove(pData, array, length * sizeof(int));

    swap=(int *)malloc(sizeof(int) * length);
    assert(NULL!=swap);
    while(1)
    {
	count=pre_process_data(pData,length,weight);
	if(!count)
	    break;
	sort_for_basic_number(pData,length,swap);
	sort_data_by_basic_number(array,pData,swap,length,weight);
	memmove(pData,array,length * sizeof(int));
	weight++;
    }
    free(pData);
    free(swap);
    
    for(i=0;i<length;i++)
	printf("%d ",array[i]);
    printf("\n");

}



void main()
{
    int a[10]={2093,43,212,765,90,3,56,8,1,999};
    radixsort(a,10);
}
