/**********************************************
程序编号：02
程序名称：文件中字符的读与写 The reading and writing of characters in a file
程序功能：从键盘输入一行字符，写入文件string， 再把该文件内容读出显示在屏幕上
程序输入：I Love C Program
程序输出：I Love C Program
程序员：  黄龙飞
编程时间：2016-7-27
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
	FILE *fp;
	char ch;
	/* 定义变量结束 */
	
	/* 打开文件 */
	if((fp=fopen("string.txt","w+"))==NULL)  //只写打开或者建立一个ASCII文件，只允许写数据
	{
		printf("Cannot open file strike any key exit!");	//若文件打开失败
		getch();
		exit(1);							//退出函数
	}
	/* 打开文件结束 */

	/* 输入字符，将对应字符存入文件中 */
	printf("input a string:\n");
	ch=getchar();						//先从控制台接收第一个输入的字符
	while (ch!='\n')					//    !!!  从键盘输入时以 \n 为结束标记 
	{
		fputc(ch,fp);					//    !!!   函数原型：int fputc (int c, File *fp)    函数功能：将ch对应的字符写到fp所指文件上 
		                                //    !!!   返回值：在正常调用情况下，函数返回写入文件的字符的ASCII码值，出错时，返回EOF (EOF是在头文件 stdio.h中定义的宏)。
										//    !!!   当正确写入一个字符或一个字节的数据后，文件内部写指针会自动后移一个字节的位置。						 
		ch=getchar();					//继续从控制台接收输入的字符
	}
	/* 输入、存放字符结束 */

	rewind(fp);							//   !!!   写完文件之后，将文件指针重新指向一个流的开头

	/* 从文件中读入字符，显示在屏幕上 */
	ch=fgetc(fp);
	while(ch!=EOF)                      //    !!!   从文件读取时以 EOF 为结束标记
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	/* 读入文件结束 */
	printf("\n");

	/* 关闭文件 */
	fclose(fp);
	
	return 0; 
}//main函数结束
