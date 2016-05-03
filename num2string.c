#include "stdio.h"

int main()
{
    int num=12345;
    int j=0,i=0;
    char temp[7];
    char str[7];    
    while(num)
    {
	temp[i]=num%10+'0';
	i++;
	num=num/10;
    }
    temp[i]=0;
    printf("temp=%s\n",temp);
    i=i-1;
    printf("temp=%d\n",i);
    while(i>=0)
    {
	str[j]=temp[i];
	j++;
	i--;
    }
    str[j]=0;
    printf("string=%s\n",str);
    return 0;

}
