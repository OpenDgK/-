/**********************************************
程序编号：04
程序名称：文件中字符串的读与写 The reading and writing of the string in the file
程序功能：在文件02中建立的文件string中追加一个字符串
程序输入：wetoo
程序输出：I Love Chinawetoo
程序员：  黄龙飞
编程时间：2016-7-28
版本号：  1.0
*************************************************/

/*包含库函数*/ 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*包含库函数结束*/

 
main()
{
	/*定义变量*/ 
	FILE *fp;
	char ch,st[20];
	/*第一变量结束*/
	
	/*用追加方式打开ASCII文件*/ 
	if((fp=fopen("string.txt","a+"))==NULL)				//   !!!    a+追加方式打开
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	/*打开文件结束*/ 
	
	/*输入要追加的字符串*/ 
	printf("input a string:\n");
	scanf("%s",st);
	/*输入字符串结束*/
	
	/*将st所指字符串追加至fp所指文件中*/ 
	fputs(st,fp);                       //    !!!   函数原型：int fputs(const char *str, FILE *stream);    str-- 这是指向一个字符数组的指针，该数组存储了要读取的字符串
	                                    //    !!!   函数功能：向指定的文件写入一个字符串（不自动写入字符串结束标记符‘\0’）。
										//           成功写入一个字符串后，文件的位置指针会自动后移，函数返回值为非负整数；否则返回EOF。

	
	/*追加字符串结束*/ 

	rewind(fp);						//将文件指针重新指向一个流的开头

	/*逐个读入fp所指文件内的字符*/ 
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	/*读入字符结束*/ 

	printf("\n");

	/*关闭文件*/ 
	fclose(fp);
	/*关闭文件结束*/ 
}//main函数结束
