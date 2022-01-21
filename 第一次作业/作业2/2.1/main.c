#include <stdio.h>
#include"imput.h"
#include"putout.h"
int main() 
{
	int a[100];
	//printf("请输入数据（每输入一个数据，回车键作为间隔，当输入0时，表示输入结束）：\n");
	printf("Please input data (enter as the interval for each data input. When 0 is entered, it means the input is over):\n");
	for(int i=0;i<100;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		break;
	}
	
	int n=InputArray(a);
	PrintArray(a,n);
	return 0;
}
