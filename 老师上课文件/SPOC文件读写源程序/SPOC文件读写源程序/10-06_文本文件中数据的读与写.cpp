/**********************************************
程序编号：06
程序名称：文本文件中数据的读与写 Reading and writing of data in a text file
程序功能：用记事本生成10个学生的数据（包括学号，姓名，三门课的成绩）文件stu061；
		  用fscanf读入stu061的数据，并按学号排序后用fprintf写入stu062中（依然是ASCII文件）；
		  从文件stu062中读出数据，计算出平均成绩，并按平均成绩排序后，写入文件stu063中
程序输入：无
程序输出：
程序员：  黄龙飞
编程时间：2016-7-30
版本号：  1.2
*************************************************/

/*包含库函数*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*包含库函数结束*/

/*宏定义*/
#define N 5		//结构体数组长度为10
/*宏定义结束*/

/*定义结构体变量*/
struct student01				
{
	char num[10];
	char name[8];
	int score[3];
}stu01[N],temprangenum;			//stu01[N]  存放文件stu061中的数据
/*定义结构体变量结束*/

/*定义结构体变量*/
struct student02
{
	char num[10];
	char name[8];
	int score[3];
	float ave;
}stu02[N],stu03[N],temprangeave;		//stu02[N]  存放文件stu062中的数据；stu03[N]  存放文件stu063中的数据
/*定义结构体变量结束*/

main()
{
	/*定义变量*/
	int i,j,sum;
	FILE *fpstu061,*fpstu062,*fpstu063;		//fpstu061,fpstu062,fpstu063分别指向文件stu061、stu062和stu063
	/*定义变量结束*/

	/*判断并以只读形式打开文件stu001.txt*/
	if((fpstu061=fopen("stu061.txt","r"))==NULL)				//若打开文件失败，执行花括弧内的命令，退出函数
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	/*判断结束*/

	/*读取数据，将文件stu061.txt中数据存入数组stu01[N]中*/
	for(i=0;i<N;i++)
		fscanf(fpstu061,"%s %s %d %d %d\n",&stu01[i].num,&stu01[i].name,&stu01[i].score[0],&stu01[i].score[1],&stu01[i].score[2]);
		                                                        //   !!!   函数原型： int fscanf(FILE * stream, const char * format, [argument...]);
		                                                        //   !!!   函数功能：为根据数据格式(format)，从输入流(stream)中读入数据，存储到argument中，遇到空格和换行时结束。fscanf位于C标准库头文件<stdio.h>中。
		                                                        //   !!!   返回值：整型，成功返回读入的参数的个数，失败返回EOF
	fclose(fpstu061);	
	/*读取数据结束*/

	/*打印数组中的数据*/
	printf("输出学生信息的原始数据列表:\n");
	for(i=0;i<N;i++)
		printf("%s,%s,%d,%d,%d\n",stu01[i].num,stu01[i].name,stu01[i].score[0],stu01[i].score[1],stu01[i].score[2]);
	/*输出数据结束*/

	/*将数组stu01[N]中数据按照学号顺序排序*/
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			if(strcmp(stu01[i].num,stu01[j].num)>0)
			{
				temprangenum=stu01[i];
				stu01[i]=stu01[j];
				stu01[j]=temprangenum;
			}
	/*排序结束*/

	/*将数组stu01[N]中输入存入数组stu02[N]中*/
	for(i=0;i<N;i++)
	{	
		strcpy(stu02[i].num,stu01[i].num);
		strcpy(stu02[i].name,stu01[i].name);
		stu02[i].score[0]=stu01[i].score[0];
		stu02[i].score[1]=stu01[i].score[1];
		stu02[i].score[2]=stu01[i].score[2];
	}
	/*转存操作结束*/
			
	/*只写形式打开文件stu062.txt*/
	fpstu062=fopen("stu062.txt","w");
	for(i=0;i<N;i++)
		/*将数组stu02[N]中数据存入fpstu002所指文件中*/
		fprintf(fpstu062,"%s %s %d %d %d\n",stu02[i].num,stu01[i].name,stu02[i].score[0],stu02[i].score[1],stu02[i].score[2]);
	                                                             	//   !!!   函数原型： int fprintf (FILE* stream, const char*format, [argument])
	                                                             	//   !!!   函数功能：格式化输出到一个流文件中
	                                                             	//   !!!   返回值：成功则返回输出的字节数，失败返回eof
	fclose(fpstu062);
	/*关闭文件*/

	/*打印stu02[N]中的数据*/
	printf("输出学生信息按照学号排序之后的数据列表:\n");
	for(i=0;i<N;i++)
		printf("%s,%s,%d,%d,%d\n",stu02[i].num,stu02[i].name,stu02[i].score[0],stu02[i].score[1],stu02[i].score[2]);
	/*打印结束*/	

	/*求出均值*/
	for(i=0;i<N;i++)
	{	
		sum=0;
		for(j=0;j<3;j++)
		{
			sum=sum+stu02[i].score[j];
		}
		stu02[i].ave=sum/3.0;
	}
	/*求值结束*/

	/*将数组stu02[N]中数据按照均值从大到小排序*/
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			if(stu02[i].ave<stu02[j].ave)
			{
				temprangeave=stu02[i];
				stu02[i]=stu02[j];
				stu02[j]=temprangeave;
			}
	/*排序结束*/
			
	/*重新输出按均值排序后的数据*/
	printf("输出学生信息按照成绩均值排序之后的数据列表:\n");
	for(i=0;i<N;i++)
		printf("%s,%s,%d,%d,%d,%4.2f\n",stu02[i].num,stu02[i].name,stu02[i].score[0],stu02[i].score[1],stu02[i].score[2],stu02[i].ave);
	/*输出结束*/
	
	/*将stu02[N]中数据赋值给stu03[N]中*/
	for(i=0;i<N;i++)
		stu03[i]=stu02[i];
	/*处理结束*/
	
	/*只写形式打开文件stu063.txt*/
	fpstu063=fopen("stu063.txt","w");
	for(i=0;i<N;i++)
		/*将数组stu03[N]中数据存入fptus003所指文件中*/
		fprintf(fpstu063,"%s %s %d %d %d %f\n",stu03[i].num,stu03[i].name,stu03[i].score[0],stu03[i].score[1],stu03[i].score[2],stu03[i].ave);
	/*存入数据处理结束*/			
}//main函数结束
