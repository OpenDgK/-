#include <stdio.h>
#include <stdlib.h>

int main()
{  
    system("color B0"); 
  	//�û����棬���û�ѡ�����ģʽ

	
	int nMode;//�����û�����
	
	while(1)
	{	
		
		printf("The output mode list of this program \n ");
		printf("\na  ASCII mode \nb  Binary mode  \nc  exit \n");  
		printf("\nPlease input your choice: ");	
		setbuf(stdin,NULL);
		scanf("%c",&nMode);
		if(nMode=='c')//��ʱ���û����� 
		{
		printf("\nYou choose exit, Bye Bye!\n");
		//return 0; 
		}
		else if(nMode!='a'&&nMode!='b')//��ֹ�û���� 
		{
		printf("\nYou'v given the wrong choice! Please try again!\n");
		//return 0; 
		}
		
		//�û����棬�������ļ���
		printf("\nPlease input the data file name inclue extension name:\n ");
	    char szFileName[20];
	    scanf("%s",szFileName);
    
	    //��ʱ���û����� 
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
