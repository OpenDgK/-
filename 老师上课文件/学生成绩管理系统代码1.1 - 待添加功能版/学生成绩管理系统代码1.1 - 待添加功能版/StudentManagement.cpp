/**********************************************
程序编号：11-01-1.1
程序名称：学生成绩管理系统     Student Score Management System  
程序功能：1）读取文件并显示,若指定文件不存在则创建文件并引导用户手动录入并保存在文件中 
          2）对已有学生信息进行增加、删除和修改
		  3)可根据学生学号、语文、数学、英语及总成绩进行排序
		  4）可根据学号、姓名查询学生信息；可查询语数英的班级平均分及各分数段分布
程序输入：学生成绩信息数据文件 
程序输出：对程序功能实现的屏幕显示输出 
程序员：  杨雯雯 1.0
编程时间：2016-08-16 
修改人：冯筠
修改时间：2022-01-18，主要添加了注释，将退出本级菜单全部改为0 
版本号：  1.1
*************************************************/
/*对库函数的定义*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

#define COURSENUM 3//课程门数 
#define STRLENGTH 30//字符串长度 
#define STUDENTNUM 100//学生人数 
#define FILENAME "studentlist.txt"//缺省数据文件名 
#define FILEFLAG1  "STL" //数据文件格式标记，基本学生数据表
#define  FILEFLAG2 "STLSA" //数据文件格式标记，基本学生数据表+总成绩和平均成绩 

/* 学生结构体定义 */ 
struct student   
{
  int nNumber;  	//学号,4位
  char szName[STRLENGTH];	//姓名，2-3个汉字
  float fScore[COURSENUM];//学生几门课的成绩
  float fAveScore;	//平均分  
  float fSumScore;	//总成绩 
};
// 函数的声明 ，加主函数，共计20个函数*/ 

/*菜单相关函数 共计5个*/ 
//一级主菜单选项显示
void Select_MainMenu(struct student stu[],char szCourseName[][STRLENGTH],int* pNum);	
/* 二级菜单：信息管理模块菜单选项显示  */
void Select_ManageMenu(struct student stu[],char szCourseName[][STRLENGTH],int* pNum);
/* 二级菜单：排序计算菜单选项显示 */ 
void Select_SortMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
/* 二级菜单：条件查询菜单选项显示 */ 
void Select_QueryMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
/* 二级菜单：文件保存菜单选项显示 */ 
void Select_SaveMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
////////////////////////////////////////////////////////////////////////////////////////

/*文件相关函数，共计4个*/
//创建文件，并将现有的数据写入文件				
int CreateFile(struct student stu[],int nStudentNum,int nFlag);
//创建另存为其它文件名 
int CreateFileAs(struct student stu[],int nStudentNum,int nFlag);
//读取文件，并提取文件中的元素信息保存到学生结构体中				
int ReadFromFile(FILE* fp,struct student stu[]);
//将当前的学生信息写入文件 
void WriteToFile(FILE* fp,struct student stu[],int nStudentNum,int nFlag);
////////////////////////////////////////////////////////////////////////////////

/*信息管理相关函数，共计4个*/ 
//添加个学生信息 
int AddStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int*npStudentNum);
//输出学生信息				
void OutputStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int num,int flag,int nFrom,int nTo);
// 删除1个学生信息,返回正常删除了还是没有删除 
int DeleteStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int* npStudentNum); 
/* 修改指定学生的成绩信息 */ 
int ModifyStudentScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);  
/////////////////////////////////////////////////////////////////////////////////////////////

/* 排序计算相关函数，共计4个  */ 
//按学号升序排序 
void SortOnNumAs(struct student stu[],int nStudentNum);
// 选择法实现按总成绩降序排序   
void SortOnSumDs(struct student stu[],int nStudentNum);
// 计算各科平均分 */ 
void ComputeAverageScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum); 
//计算各科的成绩分布
void ComputeDistribution(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum); 
/////////////////////////////////////////////////////////////////////////////////////////////

/*查询相关函数，共计2个*/
/*按学号查找 */
void FindByNumber(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) ; 
/*按姓名查找 */
void FindByName(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) ;
/////////////////////////////////////////////////////////////////////////////////////////////

/* 系统主函数，初始化，调用等功能 */ 
int main() 
{	
 /* 基本数据结构 */ 
  
     //定义学生结构体数组，这个数组一直作为参数在需要的函数之间传递 
    struct student stu[STUDENTNUM];
    //存储学生个数 ，这个个数一直作为参数在需要的函数之间传递 
	int nStudentNum=0;
	//定义课程名称 
	char szCourseName[COURSENUM][STRLENGTH]={"语文","数学","英语"};
	
///////////////////////////////////////////////////////////////////////////////	
       /* 显示菜单前的准备 */ 	
	system("color 5e") ;//改变背景前景色

	//打开学生数据文件 
	FILE * fp=fopen(FILENAME,"r"); //为简化系统，文件名在宏定义里面给定 
	
	//若数据文件不存在，新建数据文件 
	if(fp==NULL)
	{	
	     printf("\t\t系统指定数据文件: %s 不存在，需要手工输入数据\n",FILENAME);	
	    //调用添加学生信息函数	
		AddStudentInfo(stu,szCourseName,&nStudentNum);
		printf("\t\t已成功添加%d个学生数据.......\n",nStudentNum);
		
		//调用创建数据文件函数 
		if(!CreateFile(stu,nStudentNum,0))
			printf("\t\t创建数据文件: %s 失败，添加的数据没有保存在数据文件中\n",FILENAME);	
		//创建数据文件失败不影响数据添加，只是告知用户没有保存在数据文件中就行啦。 
		
	}//创建文件结束 
	
	//若数据文件现成有，读取现有数据文件信息
	else 
	{	//调用读取数据文件函数 
	    nStudentNum=ReadFromFile(fp,stu);
	    
	    //输出读取文件状态 
		if(nStudentNum>0)
			printf("\t\t已成功从数据文件中%s读取了%d个学生的数据.......\n\t\t",FILENAME,nStudentNum);
		else
			printf("\t\t数据文件%s没有数据或格式不对，请使用信息管理功能添加数据.......\n\t\t",FILENAME);
		fclose(fp); 
		
	}//关闭文件
	
	//让用户看完回车反馈后继续进行 
    system("pause");
///////////////////////////////////////////////////////////////////////////////   
    /*给用户显示主菜单,将程序控制交给主菜单控制程序*/
	Select_MainMenu(stu,szCourseName,&nStudentNum); 	 
} 

////////////////////////////////////////////////////////////////////////////////
                              /*菜单相关函数*/

/* 
函数功能：一级主菜单选项显示 
输入参数：学生结构体数组，课程名数组
返回参数：学生人数（因为可能一直改变，用指针变量实现）
*/ 
void Select_MainMenu(struct student stu[],char szCourseName[][STRLENGTH],int*npStudentNum) 
{	
	int nMainchoose;
	//主菜单无限循环 
	while(1)
	{
		system("CLS"); //系统屏幕清空 
		//输出菜单主界面 
		printf("\t\t   ------------------------  \n");
		printf("\t\t|      学生成绩管理系统      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  1.信息显示   2.信息管理   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  3.排序计算   4.条件查询   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  5.文件保存   0.退出系统   |\n");
		printf("\t\t   ------------------------  \n");
		//根据宏定义的文件名和学生数额显示 
		printf("\n\t数据文件%s中目前共有%d名学生 \n\n",FILENAME,*npStudentNum);
		//请用户输入选择的数字 
		printf("\t\t   请选择功能序号(0~5):");
		//用户根据界面提示输入数字 
	    scanf("%d",&nMainchoose);	
		//根据用户输入的数字看如何行动					
		switch(nMainchoose)
		{
		   //信息显示 
			case 1: printf("\n");
			        //调用输出学生信息函数 
				    OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);	//转到输出显示函数 
				    system("PAUSE");
			        break;
			//转到二级菜单：信息管理模块菜单选项显示 
			case 2: Select_ManageMenu(stu,szCourseName,npStudentNum);
					break;
			//转到二级菜单：条件排序模块菜单选项显示
			case 3:Select_SortMenu(stu,szCourseName,*npStudentNum);	
					break;
			//转到二级菜单：条件查询模块菜单选项显示
			case 4:Select_QueryMenu(stu,szCourseName,*npStudentNum);
					break;
			//转到二级菜单：文件保存模块菜单选项显示
			case 5:Select_SaveMenu(stu,szCourseName,*npStudentNum);
					break;
			//用户选择退出		
			case 0: printf("\n\n\t\t感谢使用我们的软件，欢迎下次再来！") ;
			        exit(0);
					break; 
			//用户选择有误 
			default:printf("选择有误，请重选！\n");
		}//switch结束 
	}//while(1)函数结束 
}//Select_MainMenu函数结束 

/* 
函数功能：一级菜单：信息管理模块菜单选项显示  
输入参数：学生结构体数组，课程名数组
返回参数：学生人数（因为可能一直改变，用指针变量实现）
*/ 
void Select_ManageMenu(struct student stu[],char szCourseName[][STRLENGTH],int* npStudentNum)
{
	int nManageChoose;
	while(1)
	{   system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********信息管理模块********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.增加学生信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.删除学生信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        3.修改学生信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.返回上级菜单      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t   ------------------------  \n");
		printf("\n\t数据文件%s中目前共有%d名学生 \n\n",FILENAME,*npStudentNum);
		printf("\t\t   请选择功能序号(0~3):");
		//读入用户选择 
		scanf("%d",&nManageChoose);
		switch(nManageChoose)
		{
			case 1:AddStudentInfo(stu,szCourseName,npStudentNum);//转到增加学生信息函数 
			       //OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
				   break;
			case 2:DeleteStudentInfo(stu,szCourseName,npStudentNum);//转到删除学生信息函数
			       //OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
				   break;
			case 3:ModifyStudentScore(stu,szCourseName,*npStudentNum);//转到修改学生信息函数
			       //OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
					break;
			case 0: Select_MainMenu(stu,szCourseName,npStudentNum);			//返回一级主菜单函数 
			        break;
					
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 */
	}//while(1)结束 

	
}//Select_ManageMenu函数结束 

/* 
函数功能：二级菜单：排序和计算菜单选项显示  
输入参数：学生结构体数组，课程名数组，学生人数
返回值：无 
*/ 
void Select_SortMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	int nSortChoose;

	while(1)
	{	system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********排序计算模块********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   1.按学号升序排序         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   2.总成绩计算及降序排序   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   3.各科平均成绩计算           |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   4.各科成绩分布计算       |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   0.返回上级菜单           |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------  \n");
		printf("\n\t数据文件%s中目前共有%d名学生 \n\n",FILENAME,nStudentNum);
		printf("\t\t   请选择功能序号(0~4):");	
		//读入用户选择 
		scanf("%d",&nSortChoose);
		
		switch(nSortChoose)
		{
			case 1:SortOnNumAs(stu,nStudentNum);//按学号升序排序 
			        //添加完函数后这里就可以解开注释了	
					//OutputStudentInfo(stu,szCourseName,nStudentNum,0,0,nStudentNum);//输出给用户看一下 
			       	system("PAUSE");
					break;
			case 2: SortOnSumDs(stu,nStudentNum);//按总成绩降序排序	
			        //添加完函数后这里就可以解开注释了	
					//printf("\n\t\t\t计算各人总成绩及平均成绩......\n");
					//OutputStudentInfo(stu,szCourseName,nStudentNum,1,0,nStudentNum);//输出给用户看一下 
			       	system("PAUSE");
					break;
			case 3: //添加完函数后这里就可以解开注释了	
			         //printf("\n\t\t\t计算总成绩及平均成绩......\n");
			        ComputeAverageScore(stu,szCourseName,nStudentNum);//按总成绩降序排序	
					system("PAUSE");
					break;
			case 4: //添加完函数后这里就可以解开注释了	
			        //printf("\n\t\t\t计算各科平均成绩及分布......\n");
			        ComputeDistribution(stu,szCourseName,nStudentNum);//按总成绩降序排序	
					system("PAUSE");
					break;
			case 0:Select_MainMenu(stu,szCourseName,&nStudentNum);//返回一级主菜单选项显示 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
	}//while(1)结束 
}//Select_SortMenu函数结束 


/* 
函数功能：二级菜单：信息查询菜单选项显示  
输入参数：学生结构体数组，课程名数组，学生人数
返回值：无 
*/ 

void Select_QueryMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{	
	int nQueryChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************信息查询模块************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.根据学号查询信息          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         2.根据姓名查询信息          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.返回上级菜单              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   请选择功能序号(0~2):");
		
		
		scanf("%d",&nQueryChoose);
		
		switch(nQueryChoose)
		{
			case 1: FindByNumber(stu,szCourseName,nStudentNum);	//按学号查询学生信息 
			        system("PAUSE");
					break;
			case 2: FindByName(stu,szCourseName,nStudentNum); //按姓名查询学生信息 
			        system("PAUSE");
					break;
			case 0: Select_MainMenu(stu,szCourseName,&nStudentNum); 	//返回一级主菜单选项 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
		
	}//while结束 
}//信息查询菜单结束 


/* 
函数功能：二级菜单：文件保存选项显示  
输入参数：学生结构体数组，课程名数组，学生人数
返回值：无 
*/ 
void Select_SaveMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{	
	int nSaveChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************文件保存模块************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.当前文件保存              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         2.另存其它文件              |\n");
		printf("\t\t|                                     |\n");
	    printf("\t\t|         3.保存平均和总成绩          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.返回上级菜单              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   请选择功能序号(0~3):");
		scanf("%d",&nSaveChoose);
		switch(nSaveChoose)
		{
			case 1:
				//重新创建数据文件
				CreateFile(stu,nStudentNum,0);
		  		break;
		    case 2:	//另存为其它文件 
				CreateFileAs(stu,nStudentNum,0);
		  		break;
		    case 3:	//另存为其它文件并保存总成绩和其它成绩 
				CreateFileAs(stu,nStudentNum,1);
		  		break;
			case 0:Select_MainMenu(stu,szCourseName,&nStudentNum); 				//返回一级主菜单选项 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
		system("PAUSE");
	}//while结束 
}//文件保存菜单结束 

////////////////////////////////////////////////////////////////////////////////////// 
                            /*文件相关函数*/
 /* 
函数功能：创建文件，并将现有的数据写入文件 
输入参数：学生结构体数组，学生人数，文件格式标志 
           注意有两种存储文件格式,1种是没有平均成绩和总成绩的,1种是有的
		   为了区分两种文件格式,将文件格式标志写到数据文件里面 
          文件格式标志：0 表示 "STL" 是存储为基本学生数据表信息文件 (无总成绩和平均成绩) 
                        1 表示 "STLSA" 是基本学生数据表+总成绩和平均成绩 
            ***文件格式标志为程序员自己定义的，用记事本打开studentlist.txt可以看到存储数据内容 
返回值：0: 创建成功，1，创建不成功 
*/ 

int CreateFile(struct student stu[],int nStudentNum,int nFlag)
{
		//数据写入文件
		FILE* fp=fopen(FILENAME,"w");
		if(fp!=NULL)
		{	
			WriteToFile(fp,stu,nStudentNum,nFlag);
			printf("\t\t已成功将%d个学生数据写入数据文件%s.......\n",nStudentNum,FILENAME);
			//给用户显示目前的信息
	 		return 1;
		}
		  
		else //文件创建不成功 
			return 0;
		
	
}//创建文件结束 

 /* 
函数功能：另存为文件，并将现有的数据写入文件 
输入参数：学生结构体数组，学生人数，文件格式标志 
          文件格式标志：0 表示 "STL" 是存储为基本学生数据表信息文件 
                        1 表示 "STLSA" 是基本学生数据表+总成绩和平均成绩 
            ***文件格式标志为程序员自己定义的，用记事本打开dd.txt，和  
			    Studentscore.data可以看到存储数据内容 
返回值：0: 创建成功，1，创建不成功 
*/ 
			
int CreateFileAs(struct student stu[],int nStudentNum,int nFlag)
{
    char szFileName[STRLENGTH];
    if(nStudentNum<1)
	{
			printf("\t\t当前没有学生数据，请到信息管理模块添加数据！\n");
			return 0;
	}
	if(nFlag==1&&stu[0].fSumScore<1)
	{
			printf("\t\t当前没有总成绩和平均成绩信息，请到排序计算模块计算成绩！\n");
			return 0;
	}
	 
	while(1)
   {
	    printf("\n\t\t请输入拟保存的文件名: ");
	  
	    scanf("%s",szFileName);
	    if(strcmp(szFileName,FILENAME)==0)
	    	printf("\n\t\t该文件名为系统文件名，不可使用！\n");
	    else
	    	break; 
	}
	//数据写入文件
	FILE* fp=fopen(szFileName,"w");
	if(fp!=NULL)
	{
		WriteToFile(fp,stu,nStudentNum,nFlag);
		printf("\t\t已成功将%d个学生数据写入数据文件%s.......\n",nStudentNum,szFileName);
		fclose(fp);
		//给用户显示目前的信息
 		return 1;
	}
	  
	else //文件创建不成功 
		return 0;
		
	
}//创建另存为文件结束 


/* 
函数功能：读取文件，并提取文件中的元素信息保存到学生结构体中
   注意：如果从数据文件中读到的起始字符串是"STL" 表示是基本学生数据表信息文件 
                          读到 "STLSA" 是基本学生数据表+总成绩和平均成绩 
            ***文件格式标志为程序员自己规定的，用记事本打开dd.txt，和  
			    Studentscore.data可以看到存储数据内容  
输入参数：文件指针，学生结构体数组
          
返回值：读到的学生数 
*/ 

int ReadFromFile(FILE *fp,struct student stu[])
{
	int i=0;
	char szFileFlag[STRLENGTH];//先读文件标记
	fscanf(fp,"%s",szFileFlag) ;
	int nFlag=-1;
	if(strcmp(szFileFlag,FILEFLAG1)==0)
		nFlag=0;
	if(strcmp(szFileFlag,FILEFLAG2)==0)
		nFlag=1;
	if (nFlag==-1)
	  return 0; //如果是未知的文件头，返回0 
	do
	{
		int nReadNum=0;
		//读学号和姓名 
		nReadNum+=fscanf(fp,"%d%s",&stu[i].nNumber,&stu[i].szName);
		//读各科成绩 
		for(int j=0;j<COURSENUM;j++)
		  nReadNum+=fscanf(fp,"%f",&stu[i].fScore[j]);
		//如果是STLSA，读总成绩和平均成绩
		if(nFlag==1)
		  fscanf(fp,"%f%f",&stu[i].fSumScore,&stu[i].fAveScore); 
		//成功读取，计数器+1 
		if (nReadNum==(COURSENUM+2))
			i++;
		else
			break;
	}
	while(1);
	return i;//返回读到的学生数 
	
}
//ReadFromFile 函数结束		



/* 
函数功能：将目前学生结构体的数据，写入一个文件
输入参数：文件指针，学生结构体数组，学生人数，文件格式标志 
          文件格式标志：0 表示 "STL" 是存储为基本学生数据表信息文件 
                        1 表示 "STLSA" 是基本学生数据表+总成绩和平均成绩 
            ***文件格式标志为程序员自己定义的，用记事本打开dd.txt，和  
			    Studentscore.data可以看到存储数据内容 
          
返回值：读到的学生数 
*/ 
 void WriteToFile(FILE* fp,struct student stu[],int nStudentNum,int nFlag)
{
	//输出标题 
	if(nFlag==0)
		fprintf(fp,FILEFLAG1);
	else if(nFlag==1)
		fprintf(fp,FILEFLAG2);
	fprintf(fp,"\n");
	for(int i=0;i<nStudentNum;i++)	
 	{
  		//写入数据文件 
  		fprintf(fp,"%d %s ",stu[i].nNumber,stu[i].szName);
  		//写各科成绩 
		for(int j=0;j<COURSENUM;j++)
			fprintf(fp,"%.2f ",stu[i].fScore[j]);
		if(nFlag==1) 
			fprintf(fp,"%.2f %.2f",stu[i].fSumScore,stu[i].fAveScore);
		fprintf(fp,"\n");  		

 	}//for循环结束  
	
}//Write to File 函数结束

/////////////////////////////////////////////////////////////////////////////// 
              /*学生信息处理函数---增加，删除，修改*/ 

/* 
函数功能：将输入N个学生信息，返回增加的学生数，并修改学生目前的数目 
输入参数：学生结构体数组，课程名称数组
返回值：学生人数（用指针变量返回，因为这个人数会变化      
返回值：添加的学生人数 
*/ 
int AddStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int* npStudentNum)
{
	
	printf("\n\t\t\t这里是增加学生信息模块\n"); 
	 	
  	//待你添加代码 1
	
	 
 	return 1;//返回添加的学生数 
	
}//AddSudentInfo函数结束 


/* 
函数功能：输出学生信息函数 ，可以输出两种，1种是有平均成绩和总成绩的，1种是没有 
输入参数：学生结构体数组，课程名称数组，学生人数，文件格式标志（是否有平均成绩和总成绩）
          没有平均成绩和总成绩文件标志为 0，有平均成绩和总成绩文件标志为 1 
         nFrom 表示从第几个开始输出，nTo表示输到第几个结束  
返回值：无      
*/ 

void OutputStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum,int nFlag,
						int nFrom,int nTo)
{
	printf("\n\t\t\t这里是显示学生信息模块\n"); 
		//待你添加代码 2
	
} 
//输出学生信息函数结束 


/* 
函数功能：删除某位学生信息的函数，函数内部自带输入 
输入参数：学生结构体数组，课程名称数组
返回值：学生人数（以指针变量形式，因为人数会变化） 
         nFrom 表示从第几个开始输出，nTo表示输到第几个结束  
返回值：是否成功删除，0为没成功删除，1为成功删除      
*/ 
int DeleteStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int* npStudentNum)
{
 	printf("\n\t\t\t这里是删除学生信息模块\n"); 
    	
	//待你添加代码 3
	
	return 1;
}//DeleteStudentInfo函数结束 


/* 
函数功能：修改某位学生的成绩信息，函数内部自带输入 
输入参数：学生结构体数组，课程名称数组，学生人数 
返回值：是否成功修改，0为没成功修改，1为成功修改     
*/ 
int ModifyStudentScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)   
{
	
 	printf("\n\t\t\t 这里是修改学生信息模块\n"); 
 	
 		//待你添加代码 4
 
	return 1;
}//ModifyScore函数结束 


////////////////////////////////////////////////////////////////////////////////////// 
                         /*排序计算相关函数*/ 
/* 
函数功能：选择法实现按学号升序排序 
输入参数：学生结构体数组，学生人数 
返回值：修改共用的学生结构体数组每个学生的顺序     
*/ 

void SortOnNumAs(struct student stu[],int nStudentNum)
{
		printf("\n\t\t\t这里是按学号升序排序模块\n"); 
		//待你添加代码 5
	
}
//按学号升序排序结束

/* 
函数功能：选择法实现按总成绩降序排序 
输入参数：学生结构体数组，学生人数 
返回值：修改共用的学生结构体数组每个学生的顺序    
*/ 
void SortOnSumDs(struct student stu[],int nStudentNum)
{
		printf("\n\t\t\t这里是计算总成绩，并按总成绩降序排序模块\n"); 
		//待你添加代码 6
}
//总成绩降序排序结束 


/* 
函数功能：计算各科平均分 
输入参数：学生结构体数组，课程名字数据，学生人数 
返回值：修改共用的学生结构体数组的每个成员的平均分    
*/ 

void ComputeAverageScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	printf("\n\t\t\t这里是计算学生各科平均分数模块\n"); 
		//待你添加代码 7
	
}

/* 
函数功能：计算并输出班级语文成绩各分数段分布情况 
    定义学生成绩分布等级如下：
    60分以下：fail
    60~70分 ：pass
    70~80分 ：good
    80~90分 ：great
    90分以上：excellent 
输入参数：学生结构体数组，课程名字数据，学生人数 
返回值：无  
*/ 
void ComputeDistribution(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	printf("\n\t\t\t 这里是计算各分数段分布模块\n"); 
 	
 		//待你添加代码 8

}// 计算成绩分布情况函数结束 

///////////////////////////////////////////////////////////////////////////////// 
             //查询相关函数 共有2个：按学号，按姓名查找 
                        

/* 
函数功能：按学号查找并输出一个学生的具体信息 
输入参数：学生结构体数组，课程名字数据，学生人数 
返回值：无  
*/ 

void FindByNumber(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{
	printf("\n\t\t\t 这里是按学号查找一个学生模块\n"); 
 	
 		//待你添加代码 9
		
}//按学号查询结束 

/* 
函数功能：按姓名查找并输出一个学生的具体信息 
输入参数：学生结构体数组，课程名字数据，学生人数 
返回值：无  
*/ 
void FindByName(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{
	printf("\n\t\t\t这里是按姓名查找学生信息模块\n"); 
 	
 		//待你添加代码 10
		
}//按姓名查询结束 




