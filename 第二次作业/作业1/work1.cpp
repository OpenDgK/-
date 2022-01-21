//从键盘输入需要写入的学生信息个数n（n<10人），输入n个学生的数据，将它们写入文件student.txt中，并把全部学生信息显示在屏幕上，
//关闭文件；其中学生信息包括学号（4位整数）、姓名（不超过10个字符）、3门课的分数(浮点型,保留2位小数)。

#include <stdio.h>
#include <stdlib.h>

/*定义结构体变量*/
struct student				
{
	char num[10];
	char name[8];
	float score[3];
};	
/*定义结构体变量结束*/



int main()
{
	
	
	/*定义变量*/
	int i,j,sum,N;
	printf("input the number of student:\n");
	scanf("%d",&N)	;
	struct student stud01[N];	

	FILE *fpstu062; 
	/*定义变量结束*/
	
	/*输入N组数据，存入结构体数组stud01中*/
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
			scanf("%f",&stud01[i].score[j]);	//顺序输入三个成绩；
		}
	}
	/*输入数据结束*/
	
	
	/*只写形式打开文件stu062.txt*/
	fpstu062=fopen("student.txt","w");
	for(i=0;i<N;i++)
		
		fprintf(fpstu062,"%s %s %.2f %.2f %.2f\n",stud01[i].num,stud01[i].name,stud01[i].score[0],stud01[i].score[1],stud01[i].score[2]);
	                                                             	//   !!!   函数原型： int fprintf (FILE* stream, const char*format, [argument])
	                                                             	//   !!!   函数功能：格式化输出到一个流文件中
	                                                             	//   !!!   返回值：成功则返回输出的字节数，失败返回eof
	fclose(fpstu062);
	/*关闭文件*/
		
		
		
	/*打印数组中的数据*/
	printf("输出全部学生信息:\n");
	for(i=0;i<N;i++)
		printf("%s,%s,%.2f,%.2f,%.2f\n",stud01[i].num,stud01[i].name,stud01[i].score[0],stud01[i].score[1],stud01[i].score[2]);
	/*输出数据结束*/

	return 0;
	
	
	
	


}//main函数结束
