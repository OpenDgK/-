#include <stdio.h>
#include"imput.h"
#include"putout.h"
int main() 
{
	int a[100];
	//printf("���������ݣ�ÿ����һ�����ݣ��س�����Ϊ�����������0ʱ����ʾ�����������\n");
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
