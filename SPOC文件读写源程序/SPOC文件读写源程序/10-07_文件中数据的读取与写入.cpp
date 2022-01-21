/**********************************************
程序编号：07
程序名称：文件中数据的读取与写入 Data reading and writing in the file
程序功能：从文件05中生成的stu02.dat中分别读出第2个和第7个学生的数据，交换后重新写入文件。
程序输入：无
程序输出：
程序员：  黄龙飞
编程时间：2016-7-31
版本号：  1.1
*************************************************/

/*包含库函数*/
#include <stdio.h>
/*包含库函数结束*/

/*宏定义*/
#define N 3  //  !!!   在实例 “10-05_文件中数据的读与写”中我们写入了N组数据 

/*定义结构体类型数组变量*/
struct student
{
	char num[10];
	char name[8];
	int score[3];
	float ave;
}stu[N],temp;
/*定义结构体类型数组变量结束*/


int main()
{
	/*定义变量*/
	int i;
	FILE *fp;
	fp=fopen("stu02.dat","r");
	/*定义变量结束*/

	/*从文件stu02.dat中读入数据*/
	printf("输出文件中的原始数据信息:");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);   ///   !!!    从fp所指文件中取出数据存入数组stu[i]中 
		printf("\n%s,%s,%d,%d,%d,%6.2f\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[02],stu[i].ave);
	}
	/*读入数据结束*/

	/*打印需要交换的两组数据*/
	printf("输出要实现交换的数据信息:");
	printf("\n%s,%s,%d,%d,%d,%6.2f\n",stu[0].num,stu[0].name,stu[0].score[0],stu[0].score[1],stu[0].score[02],stu[0].ave);
	printf("\n%s,%s,%d,%d,%d,%6.2f\n",stu[2].num,stu[2].name,stu[2].score[0],stu[2].score[1],stu[2].score[02],stu[2].ave);
	/*打印数据结束*/

	/*数据交换*/
	temp=stu[0];
	stu[0]=stu[2];	
	stu[2]=temp;
	/*交换处理结束*/
	
	/*重新写入数据到文件stu02.dat中*/
	fp=fopen("stu02.dat","w");
	for(i=0;i<N;i++)
		if(fwrite(&stu[i],sizeof(struct  student),1,fp)!=1)    ///    !!!    stu[i]内数据存入fp指针所指文件内 
			printf("file write error\n");
	fclose(fp);
	/*写入数据结束*/
	
	/*重新读取数据，并打印出*/
	printf("输出交换数据后再次文件中的数据信息:");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);      
		printf("\n%s,%s,%d,%d,%d,%6.2f\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[02],stu[i].ave);
	}
	/*输出结束*/
	
	return 0;
}	
