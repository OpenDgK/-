#include"putout.h"
#include <stdio.h>
void PrintArray(int a[],int num)
{
	printf("The data you entered is��\n") ;
	for(int i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}
}
