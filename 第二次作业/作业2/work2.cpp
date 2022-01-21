//打开student.txt文件，读取全部学生信息，存入结构体数组；再从键盘新输入1个学生的数据，也存入结构题数组中，
//把读取的全部学生信息和新输入的学生信息一起存到文件student_new.txt文件中，并把全部学生信息显示在屏幕上，关闭文件。
//其中学生信息包括学号（4位整数）、姓名（不超过10个字符）、3门课的分数(浮点型,保留2位小数)。

/*包含库函数*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*包含库函数结束*/

/*宏定义*/
#define N 5		
/*宏定义结束*/

/*定义结构体变量*/
struct student01				
{
	char num[10];
	char name[8];
	float score[3];
}stu01[N+1];			
/*定义结构体变量结束*/


main()
{
	/*定义变量*/
	int i,j;
	FILE *fpstu061,*fpstu063;	
	/*定义变量结束*/

	/*判断并以只读形式打开文件student.txt*/
	if((fpstu061=fopen("student.txt","r"))==NULL)				//若打开文件失败，执行花括弧内的命令，退出函数
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	/*判断结束*/

	/*读取数据，将文件student.txt中数据存入数组stu01[N]中*/
	for(i=0;i<N;i++)
		fscanf(fpstu061,"%s %s %f %f %f\n",&stu01[i].num,&stu01[i].name,&stu01[i].score[0],&stu01[i].score[1],&stu01[i].score[2]);
		                                                        //   !!!   函数原型： int fscanf(FILE * stream, const char * format, [argument...]);
		                                                        //   !!!   函数功能：为根据数据格式(format)，从输入流(stream)中读入数据，存储到argument中，遇到空格和换行时结束。fscanf位于C标准库头文件<stdio.h>中。
		                                                        //   !!!   返回值：整型，成功返回读入的参数的个数，失败返回EOF
	fclose(fpstu061);	
	/*读取数据结束*/


	printf("\ninput score of student:\n");
	printf("No.:");
	scanf("%s",stu01[N].num);			//输入学号；
	printf("name:");
	scanf("%s",stu01[N].name);			//输入姓名；		
	for(j=0;j<3;j++)
	{
		printf("score %d:",j+1);
		scanf("%f",&stu01[N].score[j]);	//顺序输入三个成绩；
	}
	
	
	/*只写形式打开文件student_new.txt*/
	fpstu063=fopen("student_new.txt","w");
	for(i=0;i<N+1;i++)
		/*将数组stu03[N]中数据存入fptus003所指文件中*/
		fprintf(fpstu063,"%s %s %.2f %.2f %.2f\n",stu01[i].num,stu01[i].name,stu01[i].score[0],stu01[i].score[1],stu01[i].score[2]);
	/*存入数据处理结束*/	
	fclose(fpstu063);


	/*打印数组中的数据*/
	printf("输出学生信息的原始数据列表:\n");
	for(i=0;i<N+1;i++)
		printf("%s,%s,%.2f,%.2f,%.2f\n",stu01[i].num,stu01[i].name,stu01[i].score[0],stu01[i].score[1],stu01[i].score[2]);
	/*输出数据结束*/

}//main函数结束
