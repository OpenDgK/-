/**********************************************
程序编号：03
程序名称：文件中字符串的读与写 The reading and writing of the string in the file
程序功能：使用fgets函数从F01.c文件中读入一个含10个字符的字符串
程序输入：无
程序输出：I Love Chi
程序员：  黄龙飞
编程时间：2016-7-28
版本号：  1.0
*************************************************/


/*包含库函数*/ 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*包含库函数结束*/


int main()
{
	/* 定义变量 */
	FILE *fp;							//定义文件类型指针
	char str[11];						//定义长度为11的字符数组
	/* 定义变量结束 */

	/* 打开文件 */
	if((fp=fopen("F01.txt","r"))==NULL)	//若文件打开失败，则执行花括弧内的语句，退出函数
	{
		printf("Cannot open file strike any key exit!");	
		getch();
		exit(1);
	}
	/* 打开文件结束 */
	
	/* 从文件读一个字符串 */
	fgets(str,11,fp);					//    !!!   函数原型：char *fgets(char *str, int n, FILE *stream);    str-- 这是指向一个字符数组的指针，该数组存储了要读取的字符串
	                                    //    !!!   函数功能：从指定的流 stream 读取一行，并把它存储在str所指向的字符串内。
										//          当读取(n-1)个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止。 
	/* 读字符串结束 */

	/* 打印字符串 */
	printf("%s",str);
	/* 打印结束 */

	/* 关闭文件 */
	fclose(fp);
	/* 关闭文件结束 */
	
	return 0; 
}//main函数结束
