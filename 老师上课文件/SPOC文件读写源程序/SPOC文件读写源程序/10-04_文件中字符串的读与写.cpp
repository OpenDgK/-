/**********************************************
�����ţ�04
�������ƣ��ļ����ַ����Ķ���д The reading and writing of the string in the file
�����ܣ����ļ�02�н������ļ�string��׷��һ���ַ���
�������룺wetoo
���������I Love Chinawetoo
����Ա��  ������
���ʱ�䣺2016-7-28
�汾�ţ�  1.0
*************************************************/

/*�����⺯��*/ 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*�����⺯������*/

 
main()
{
	/*�������*/ 
	FILE *fp;
	char ch,st[20];
	/*��һ��������*/
	
	/*��׷�ӷ�ʽ��ASCII�ļ�*/ 
	if((fp=fopen("string.txt","a+"))==NULL)				//   !!!    a+׷�ӷ�ʽ��
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	/*���ļ�����*/ 
	
	/*����Ҫ׷�ӵ��ַ���*/ 
	printf("input a string:\n");
	scanf("%s",st);
	/*�����ַ�������*/
	
	/*��st��ָ�ַ���׷����fp��ָ�ļ���*/ 
	fputs(st,fp);                       //    !!!   ����ԭ�ͣ�int fputs(const char *str, FILE *stream);    str-- ����ָ��һ���ַ������ָ�룬������洢��Ҫ��ȡ���ַ���
	                                    //    !!!   �������ܣ���ָ�����ļ�д��һ���ַ��������Զ�д���ַ���������Ƿ���\0������
										//           �ɹ�д��һ���ַ������ļ���λ��ָ����Զ����ƣ���������ֵΪ�Ǹ����������򷵻�EOF��

	
	/*׷���ַ�������*/ 

	rewind(fp);						//���ļ�ָ������ָ��һ�����Ŀ�ͷ

	/*�������fp��ָ�ļ��ڵ��ַ�*/ 
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	/*�����ַ�����*/ 

	printf("\n");

	/*�ر��ļ�*/ 
	fclose(fp);
	/*�ر��ļ�����*/ 
}//main��������
