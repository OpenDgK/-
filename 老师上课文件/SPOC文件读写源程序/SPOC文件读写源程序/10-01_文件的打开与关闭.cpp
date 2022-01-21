/**********************************************
程序编号：01
程序名称：文件的打开与关闭 Open and close the file
程序功能：使用fgetc函数读入一个ASCII文件（如：生成的源程序），在屏幕上显示
程序输入：无
程序输出：
程序员：  黄龙飞
编程时间：2016-7-26
版本号：  1.1
*************************************************/


/*包含库函数*/ 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*包含库函数结束*/ 


main()
{
	/* 定义变量 */
	FILE *fp;					//定义一个文件类型的指针			
	char ch;
	/* 定义变量结束 */

	/*打开文件*/
	if((fp=fopen("F01.txt","r"))==NULL)		//检测文件是否存在；r  只读打开一个ASCII文件，只允许读数据
	{
		printf("Cannot open file strike any key exit!");//若不存在该文件，输出错误提示信息
		getch();								//从控制台读入一个字符（起到暂停作用）
		exit(1);								//    !!!  退出函数exit(): exit(1)表示异常退出,  exit(0)表示正常退出   需要加头文件stdlib.h
	}
	/*打开文件结束*/

	/**/
	ch=fgetc(fp);				//    !!!    函数原型：int fgetc(FILE *fp);     函数功能：从fp指向的文件读入一个字符  
	                            //    !!!    返回值：当正确读入一个字符或一个字节的数据后该，字符的ASCII值作为函数的返回值，若返回值为EOF，说明文件结束，EOF是文件结束标志
	                            
	while (ch!=EOF)				//    !!!    EOF：文件结束标志      从文件中顺序读入字符并显示在屏幕上
	{
		putchar(ch);			//输出字符ch
		ch=fgetc(fp);           
	}
	fclose(fp);					//关闭文件
}//main函数结束
