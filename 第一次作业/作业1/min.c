#include"min.h"
int min1(int a[],int num)
{
	int v;
	int min5=a[0];
	for(v=0;v<num+1;v++)
	{
		if(a[v]<min5) min5=a[v];
	}
	return min5;
	
}
