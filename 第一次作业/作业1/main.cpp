//Modify integer data in this directory'zhengshu.txt'
//The minimum value part of the main function has been annotated and can be tested by yourself.

#include <stdio.h>
#define MAXORMIN 10

#ifdef MAXORMIN
	#include"max.h"
#else
	#include"min.h"	
#endif
int main()
{
	int ch,max6;
	int sum=0;
	char a[100];
	int b[100];
	int i=0,j=0,k=0;
	FILE *fp;
	fp=fopen("zhengshu.txt","r");
	while((ch=getc(fp))!=EOF)
	{ //putchar(ch);  
	 a[i]=ch;
     i++;
	}
	a[i]=' ';

	for(j=0;j<i-1;j++)
	{
		if(a[j]!=' ') {
			sum=sum*10+a[j]-'0';
		}
		else{
			b[k]=sum;
			k++;
			sum=0;
		}
	}
	b[k]=sum;
	//printf("%d\n",k);

/*	for(i=0;i<k+1;i++)
	{

	printf("%d ",b[i]);
	}*/
	max6=max1(b,k);
	//min6=min1(b,k);
	//printf("The minimum value is:%d",min6);
	printf("The maximum value is:%d",max6);


	
	
	
}


