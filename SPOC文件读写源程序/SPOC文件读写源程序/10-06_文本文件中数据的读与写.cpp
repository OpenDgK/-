/**********************************************
�����ţ�06
�������ƣ��ı��ļ������ݵĶ���д Reading and writing of data in a text file
�����ܣ��ü��±�����10��ѧ�������ݣ�����ѧ�ţ����������ſεĳɼ����ļ�stu061��
		  ��fscanf����stu061�����ݣ�����ѧ���������fprintfд��stu062�У���Ȼ��ASCII�ļ�����
		  ���ļ�stu062�ж������ݣ������ƽ���ɼ�������ƽ���ɼ������д���ļ�stu063��
�������룺��
���������
����Ա��  ������
���ʱ�䣺2016-7-30
�汾�ţ�  1.2
*************************************************/

/*�����⺯��*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*�����⺯������*/

/*�궨��*/
#define N 5		//�ṹ�����鳤��Ϊ10
/*�궨�����*/

/*����ṹ�����*/
struct student01				
{
	char num[10];
	char name[8];
	int score[3];
}stu01[N],temprangenum;			//stu01[N]  ����ļ�stu061�е�����
/*����ṹ���������*/

/*����ṹ�����*/
struct student02
{
	char num[10];
	char name[8];
	int score[3];
	float ave;
}stu02[N],stu03[N],temprangeave;		//stu02[N]  ����ļ�stu062�е����ݣ�stu03[N]  ����ļ�stu063�е�����
/*����ṹ���������*/

main()
{
	/*�������*/
	int i,j,sum;
	FILE *fpstu061,*fpstu062,*fpstu063;		//fpstu061,fpstu062,fpstu063�ֱ�ָ���ļ�stu061��stu062��stu063
	/*�����������*/

	/*�жϲ���ֻ����ʽ���ļ�stu001.txt*/
	if((fpstu061=fopen("stu061.txt","r"))==NULL)				//�����ļ�ʧ�ܣ�ִ�л������ڵ�����˳�����
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	/*�жϽ���*/

	/*��ȡ���ݣ����ļ�stu061.txt�����ݴ�������stu01[N]��*/
	for(i=0;i<N;i++)
		fscanf(fpstu061,"%s %s %d %d %d\n",&stu01[i].num,&stu01[i].name,&stu01[i].score[0],&stu01[i].score[1],&stu01[i].score[2]);
		                                                        //   !!!   ����ԭ�ͣ� int fscanf(FILE * stream, const char * format, [argument...]);
		                                                        //   !!!   �������ܣ�Ϊ�������ݸ�ʽ(format)����������(stream)�ж������ݣ��洢��argument�У������ո�ͻ���ʱ������fscanfλ��C��׼��ͷ�ļ�<stdio.h>�С�
		                                                        //   !!!   ����ֵ�����ͣ��ɹ����ض���Ĳ����ĸ�����ʧ�ܷ���EOF
	fclose(fpstu061);	
	/*��ȡ���ݽ���*/

	/*��ӡ�����е�����*/
	printf("���ѧ����Ϣ��ԭʼ�����б�:\n");
	for(i=0;i<N;i++)
		printf("%s,%s,%d,%d,%d\n",stu01[i].num,stu01[i].name,stu01[i].score[0],stu01[i].score[1],stu01[i].score[2]);
	/*������ݽ���*/

	/*������stu01[N]�����ݰ���ѧ��˳������*/
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			if(strcmp(stu01[i].num,stu01[j].num)>0)
			{
				temprangenum=stu01[i];
				stu01[i]=stu01[j];
				stu01[j]=temprangenum;
			}
	/*�������*/

	/*������stu01[N]�������������stu02[N]��*/
	for(i=0;i<N;i++)
	{	
		strcpy(stu02[i].num,stu01[i].num);
		strcpy(stu02[i].name,stu01[i].name);
		stu02[i].score[0]=stu01[i].score[0];
		stu02[i].score[1]=stu01[i].score[1];
		stu02[i].score[2]=stu01[i].score[2];
	}
	/*ת���������*/
			
	/*ֻд��ʽ���ļ�stu062.txt*/
	fpstu062=fopen("stu062.txt","w");
	for(i=0;i<N;i++)
		/*������stu02[N]�����ݴ���fpstu002��ָ�ļ���*/
		fprintf(fpstu062,"%s %s %d %d %d\n",stu02[i].num,stu01[i].name,stu02[i].score[0],stu02[i].score[1],stu02[i].score[2]);
	                                                             	//   !!!   ����ԭ�ͣ� int fprintf (FILE* stream, const char*format, [argument])
	                                                             	//   !!!   �������ܣ���ʽ�������һ�����ļ���
	                                                             	//   !!!   ����ֵ���ɹ��򷵻�������ֽ�����ʧ�ܷ���eof
	fclose(fpstu062);
	/*�ر��ļ�*/

	/*��ӡstu02[N]�е�����*/
	printf("���ѧ����Ϣ����ѧ������֮��������б�:\n");
	for(i=0;i<N;i++)
		printf("%s,%s,%d,%d,%d\n",stu02[i].num,stu02[i].name,stu02[i].score[0],stu02[i].score[1],stu02[i].score[2]);
	/*��ӡ����*/	

	/*�����ֵ*/
	for(i=0;i<N;i++)
	{	
		sum=0;
		for(j=0;j<3;j++)
		{
			sum=sum+stu02[i].score[j];
		}
		stu02[i].ave=sum/3.0;
	}
	/*��ֵ����*/

	/*������stu02[N]�����ݰ��վ�ֵ�Ӵ�С����*/
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			if(stu02[i].ave<stu02[j].ave)
			{
				temprangeave=stu02[i];
				stu02[i]=stu02[j];
				stu02[j]=temprangeave;
			}
	/*�������*/
			
	/*�����������ֵ����������*/
	printf("���ѧ����Ϣ���ճɼ���ֵ����֮��������б�:\n");
	for(i=0;i<N;i++)
		printf("%s,%s,%d,%d,%d,%4.2f\n",stu02[i].num,stu02[i].name,stu02[i].score[0],stu02[i].score[1],stu02[i].score[2],stu02[i].ave);
	/*�������*/
	
	/*��stu02[N]�����ݸ�ֵ��stu03[N]��*/
	for(i=0;i<N;i++)
		stu03[i]=stu02[i];
	/*�������*/
	
	/*ֻд��ʽ���ļ�stu063.txt*/
	fpstu063=fopen("stu063.txt","w");
	for(i=0;i<N;i++)
		/*������stu03[N]�����ݴ���fptus003��ָ�ļ���*/
		fprintf(fpstu063,"%s %s %d %d %d %f\n",stu03[i].num,stu03[i].name,stu03[i].score[0],stu03[i].score[1],stu03[i].score[2],stu03[i].ave);
	/*�������ݴ������*/			
}//main��������
