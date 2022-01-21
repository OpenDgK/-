//ScoreFuncition.cpp
//Change the a[] to change the score, 
//and change the person value(Second parameter) of the entry function"CallFailNo" at the same time.
#include<stdio.h>
int nPassScore=60;
int main()
{
	int CallFailNo(int a[],int num);
	
	

	int a[]={59,40,76,52,8};
	int num=CallFailNo(a,5);
	
	printf("The total number of students who failed to reach the pass line is:\n%d",num);
	
	

} 
int CallFailNo(int a[],int num)
	{
		int j=0;
		//int nPassScore=50;
		printf("The serial number of students who fail to reach the pass line is:\n") ;
		for(int i=0;i<num;i++)
		{
			if(a[i]<nPassScore)
			{
				printf("%d ",i);
				j++;
			}
		}
		
		printf("\n");
		return j;
		
	}
