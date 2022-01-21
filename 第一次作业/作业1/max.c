#include"max.h"
int max1(int a[],int num)
{
	int v;
	int max5=a[0];
	for(v=0;v<num+1;v++)
	{
		if(a[v]>max5) max5=a[v];
	}
	return max5;
	
}
