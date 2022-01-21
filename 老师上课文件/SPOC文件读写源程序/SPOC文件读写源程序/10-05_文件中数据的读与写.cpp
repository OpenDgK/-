/**********************************************
�����ţ�05
�������ƣ��ļ������ݵĶ���д Reading and writing of data in a file
�����ܣ��ú�����ɣ�1���Ӽ�������10��ѧ��������ѧ�ţ�������3�ſεĳɼ���д�뵽�ļ�stu051.dat��
					��2�����ļ�stu051.dat�ж������ݣ������ƽ���ɼ�������ƽ���ɼ������д���ļ�stu052.dat��
�������룺10��ѧ������Ϣ��ѧ�š��������ɼ�1���ɼ�2���ɼ�3
���������
����Ա��  ������
���ʱ�䣺2016-7-30
�汾�ţ�  2.1
*************************************************/

/*�����⺯��*/ 
#include <stdio.h>
#include <stdlib.h>
/*�����⺯������*/

/*�궨��*/
#define N 3
/*�궨�����*/

/*�ṹ���������*/
struct student
{char num[10];
 char name[8];
 int score[3];
 float ave;
}stud01[N],stud02[N];    
/*�ṹ������������*/




main()
{
	/*�������*/
	struct student temp;	//temp �������ݵ���ʱ����
	int i,j,sum;
	FILE *fpstu051,*fpstu052; //fpstu051 ����ָ��stu051.dat��fpstu052����ָ��stu052.dat
	/*�����������*/
	
	/*����ʮ�����ݣ�����ṹ������stud01��*/
	for(i=0;i<N;i++)
	{
		printf("\ninput score of student %d:\n",i+1);
		printf("No.:");
		scanf("%s",stud01[i].num);			//����ѧ�ţ�
		printf("name:");
		scanf("%s",stud01[i].name);			//����������		
		for(j=0;j<3;j++)
		{
			printf("score %d:",j+1);
			scanf("%d",&stud01[i].score[j]);	//˳�����������ɼ���
		}
	}
	/*�������ݽ���*/

	/*ֻд���ļ�stu01.dat*/
	fpstu051=fopen("stu051.dat","w");
	for(i=0;i<N;i++)
		if(fwrite(&stud01[i],sizeof(struct  student),1,fpstu051)!=1) //   !!!      ����ԭ�ͣ� size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
		                                                             //   !!!      �������ܣ�����ָ�����ļ���д���������ݿ�
		                                                             //                       ����������stud01[i]�����ݴ���fpstu051ָ����ָ�ļ���
																	 //   !!!	   ����ֵ�� ����ɹ����򷵻�ʵ��д������ݿ���Ŀ������������� nmemb ������ͬ�������ʾһ������

		
			printf("file write error\n");
	fclose(fpstu051);
	/*�ر��ļ�*/

	/*ֻ�����ļ�*/
	fpstu051=fopen("stu051.dat","r");
	for(i=0;i<N;i++)
	{
		fread(&stud02[i],sizeof(struct student),1,fpstu051);			//   !!!      ����ԭ�ͣ� size_t fread( void *buffer, size_t size, size_t count, FILE *stream ); 
		                                                                //   !!!      �������ܣ��Ӹ���������stream��ȡ���count����������buffer��
		                                                                //                 ���� ��fpstu051��ָ�ļ���ȡ�����ݴ�������stud052[i]��
																	    //   !!!	   ����ֵ�� ���سɹ���ȡ�Ķ�������������ִ���򵽴��ļ�ĩβ�������С��count
	
		
		printf("\n%s,%s,%d,%d,%d\n",stud02[i].num,stud02[i].name,stud02[i].score[0],stud02[i].score[1],stud02[i].score[02]);
	}
	/*ֻ������*/

	/*�������stud02[i]�е�����stud02[i].ave*/
	for(i=0;i<N;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
			sum+=stud02[i].score[j];
		stud02[i].ave=sum/3.0;
	}
	/*���ݼ������*/

	/*�Ƚϳɼ���ֵ���Ӵ�С��������*/
	for(i=0;i<N;i++)
		for(j=i+1;j<3;j++)
			if(stud02[i].ave<stud02[j].ave)
			{
				temp=stud02[i];
				stud02[i]=stud02[j];
				stud02[j]=temp;
			}
	/*�������*/
	
	/*ֻд��ʽ���ļ�stu02.dat*/
	fpstu052=fopen("stu052.dat","w");
	for(i=0;i<N;i++)
		if(fwrite(&stud02[i],sizeof(struct  student),1,fpstu052)!=1)  //д������
			printf("file write error\n");
	fclose(fpstu052);
	/*�ر��ļ�*/

	/*ֻ�����ļ�*/
	fpstu052=fopen("stu052.dat","r");
	for(i=0;i<N;i++)
	{
		fread(&stud02[i],sizeof(struct student),1,fpstu052);
		printf("\n%s,%s,%d,%d,%d,%6.2f\n",stud02[i].num,stud02[i].name,stud02[i].score[0],stud02[i].score[1],stud02[i].score[02],stud02[i].ave);
	}
	/*������ݽ���*/
}//main��������
