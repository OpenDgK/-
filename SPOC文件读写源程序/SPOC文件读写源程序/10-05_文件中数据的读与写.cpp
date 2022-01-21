/**********************************************
程序编号：05
程序名称：文件中数据的读与写 Reading and writing of data in a file
程序功能：用函数完成（1）从键盘输入10个学生（包括学号，姓名）3门课的成绩，写入到文件stu051.dat中
					（2）从文件stu051.dat中读出数据，计算出平均成绩，并按平均成绩排序后，写入文件stu052.dat中
程序输入：10名学生的信息：学号、姓名、成绩1、成绩2、成绩3
程序输出：
程序员：  黄龙飞
编程时间：2016-7-30
版本号：  2.1
*************************************************/

/*包含库函数*/ 
#include <stdio.h>
#include <stdlib.h>
/*包含库函数结束*/

/*宏定义*/
#define N 3
/*宏定义结束*/

/*结构体变量定义*/
struct student
{char num[10];
 char name[8];
 int score[3];
 float ave;
}stud01[N],stud02[N];    
/*结构体变量定义结束*/




main()
{
	/*定义变量*/
	struct student temp;	//temp 交换数据的临时变量
	int i,j,sum;
	FILE *fpstu051,*fpstu052; //fpstu051 用来指向stu051.dat；fpstu052用来指向stu052.dat
	/*定义变量结束*/
	
	/*输入十组数据，存入结构体数组stud01中*/
	for(i=0;i<N;i++)
	{
		printf("\ninput score of student %d:\n",i+1);
		printf("No.:");
		scanf("%s",stud01[i].num);			//输入学号；
		printf("name:");
		scanf("%s",stud01[i].name);			//输入姓名；		
		for(j=0;j<3;j++)
		{
			printf("score %d:",j+1);
			scanf("%d",&stud01[i].score[j]);	//顺序输入三个成绩；
		}
	}
	/*输入数据结束*/

	/*只写打开文件stu01.dat*/
	fpstu051=fopen("stu051.dat","w");
	for(i=0;i<N;i++)
		if(fwrite(&stud01[i],sizeof(struct  student),1,fpstu051)!=1) //   !!!      函数原型： size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
		                                                             //   !!!      函数功能：是向指定的文件中写入若干数据块
		                                                             //                       即：将数组stud01[i]内数据存入fpstu051指针所指文件内
																	 //   !!!	   返回值： 如果成功，则返回实际写入的数据块数目。如果该数字与 nmemb 参数不同，则会显示一个错误。

		
			printf("file write error\n");
	fclose(fpstu051);
	/*关闭文件*/

	/*只读打开文件*/
	fpstu051=fopen("stu051.dat","r");
	for(i=0;i<N;i++)
	{
		fread(&stud02[i],sizeof(struct student),1,fpstu051);			//   !!!      函数原型： size_t fread( void *buffer, size_t size, size_t count, FILE *stream ); 
		                                                                //   !!!      函数功能：从给定输入流stream读取最多count个对象到数组buffer中
		                                                                //                 即： 从fpstu051所指文件中取出数据存入数组stud052[i]中
																	    //   !!!	   返回值： 返回成功读取的对象个数，若出现错误或到达文件末尾，则可能小于count
	
		
		printf("\n%s,%s,%d,%d,%d\n",stud02[i].num,stud02[i].name,stud02[i].score[0],stud02[i].score[1],stud02[i].score[02]);
	}
	/*只读结束*/

	/*求出数组stud02[i]中的数据stud02[i].ave*/
	for(i=0;i<N;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
			sum+=stud02[i].score[j];
		stud02[i].ave=sum/3.0;
	}
	/*数据计算结束*/

	/*比较成绩均值，从大到小依次排序*/
	for(i=0;i<N;i++)
		for(j=i+1;j<3;j++)
			if(stud02[i].ave<stud02[j].ave)
			{
				temp=stud02[i];
				stud02[i]=stud02[j];
				stud02[j]=temp;
			}
	/*排序结束*/
	
	/*只写形式打开文件stu02.dat*/
	fpstu052=fopen("stu052.dat","w");
	for(i=0;i<N;i++)
		if(fwrite(&stud02[i],sizeof(struct  student),1,fpstu052)!=1)  //写入数据
			printf("file write error\n");
	fclose(fpstu052);
	/*关闭文件*/

	/*只读打开文件*/
	fpstu052=fopen("stu052.dat","r");
	for(i=0;i<N;i++)
	{
		fread(&stud02[i],sizeof(struct student),1,fpstu052);
		printf("\n%s,%s,%d,%d,%d,%6.2f\n",stud02[i].num,stud02[i].name,stud02[i].score[0],stud02[i].score[1],stud02[i].score[02],stud02[i].ave);
	}
	/*输出数据结束*/
}//main函数结束
