//Change the a[] to change the score, 
//and change the person value(Second parameter) of the entry function"PrintFailNo2" at the same time.

#include<stdio.h>
#include <stdlib.h> 

int CallFailNo(int num);
//void PrintFailNo(int a[],int num);
int PrintFailNo2(int a[],int num);
int nPassScore=60;


int main()
{
	int a[]={59,40,76,52,89,43,8};
	int x;


	x=PrintFailNo2(a,7);
	printf("The number of people who fail is:%d",x);
}

int CallFailNo(int num)
{
	static nFailNo=0;
	if(num<nPassScore)
	nFailNo++;
	return nFailNo;
}	

/*void PrintFailNo(int a[],int num)
{

	printf("\nIf the pass score is %d \n",nPassScore);
	int i; 
	for(i=0;i<num;i++)
	{
		//多次调用CalFailNo函数，观察静态变量的表现
		int n=CallFailNo(a[i]);
		printf("fail no is: %d \n",n);
	}
}
*/
int PrintFailNo2(int a[],int num)
{


	int i,n; 
	for(i=0;i<num;i++)
	{
		
		n=CallFailNo(a[i]);
		
	}
	return n;
}
