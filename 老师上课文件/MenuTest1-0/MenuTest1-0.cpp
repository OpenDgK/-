#include <stdio.h>
#include <stdlib.h>

int main()
{  
    system("color B0"); 
  	//用户界面，让用户选择输出模式

	
	int nMode;//接收用户输入
	
	while(1)
	{	
		
		printf("The output mode list of this program \n ");
		printf("\na  ASCII mode \nb  Binary mode  \nc  exit \n");  
		printf("\nPlease input your choice: ");	
		setbuf(stdin,NULL);
		scanf("%c",&nMode);
		if(nMode=='c')//随时给用户反馈 
		{
		printf("\nYou choose exit, Bye Bye!\n");
		//return 0; 
		}
		else if(nMode!='a'&&nMode!='b')//防止用户输错 
		{
		printf("\nYou'v given the wrong choice! Please try again!\n");
		//return 0; 
		}
		
		//用户界面，让输入文件名
		printf("\nPlease input the data file name inclue extension name:\n ");
	    char szFileName[20];
	    scanf("%s",szFileName);
    
	    //随时给用户反馈 
	    if(nMode=='a') 
	 		printf("\nWe will output data to \"%s\" with ASCII mode in current folder!\n",szFileName);  
		else
		    printf("\nWe will output data to \"%s\" in Binary mode in current folder!\n",szFileName);  
		
		//return 0;
		if(nMode=='c')
		{
			break;
		} 
	
	} 
	
	return 0;
	
	
}
