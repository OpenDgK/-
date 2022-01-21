/**********************************************
�����ţ�07
�������ƣ��ļ������ݵĶ�ȡ��д�� Data reading and writing in the file
�����ܣ����ļ�05�����ɵ�stu02.dat�зֱ������2���͵�7��ѧ�������ݣ�����������д���ļ���
�������룺��
���������
����Ա��  ������
���ʱ�䣺2016-7-31
�汾�ţ�  1.1
*************************************************/

/*�����⺯��*/
#include <stdio.h>
/*�����⺯������*/

/*�궨��*/
#define N 3  //  !!!   ��ʵ�� ��10-05_�ļ������ݵĶ���д��������д����N������ 

/*����ṹ�������������*/
struct student
{
	char num[10];
	char name[8];
	int score[3];
	float ave;
}stu[N],temp;
/*����ṹ�����������������*/


int main()
{
	/*�������*/
	int i;
	FILE *fp;
	fp=fopen("stu02.dat","r");
	/*�����������*/

	/*���ļ�stu02.dat�ж�������*/
	printf("����ļ��е�ԭʼ������Ϣ:");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);   ///   !!!    ��fp��ָ�ļ���ȡ�����ݴ�������stu[i]�� 
		printf("\n%s,%s,%d,%d,%d,%6.2f\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[02],stu[i].ave);
	}
	/*�������ݽ���*/

	/*��ӡ��Ҫ��������������*/
	printf("���Ҫʵ�ֽ�����������Ϣ:");
	printf("\n%s,%s,%d,%d,%d,%6.2f\n",stu[0].num,stu[0].name,stu[0].score[0],stu[0].score[1],stu[0].score[02],stu[0].ave);
	printf("\n%s,%s,%d,%d,%d,%6.2f\n",stu[2].num,stu[2].name,stu[2].score[0],stu[2].score[1],stu[2].score[02],stu[2].ave);
	/*��ӡ���ݽ���*/

	/*���ݽ���*/
	temp=stu[0];
	stu[0]=stu[2];	
	stu[2]=temp;
	/*�����������*/
	
	/*����д�����ݵ��ļ�stu02.dat��*/
	fp=fopen("stu02.dat","w");
	for(i=0;i<N;i++)
		if(fwrite(&stu[i],sizeof(struct  student),1,fp)!=1)    ///    !!!    stu[i]�����ݴ���fpָ����ָ�ļ��� 
			printf("file write error\n");
	fclose(fp);
	/*д�����ݽ���*/
	
	/*���¶�ȡ���ݣ�����ӡ��*/
	printf("����������ݺ��ٴ��ļ��е�������Ϣ:");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);      
		printf("\n%s,%s,%d,%d,%d,%6.2f\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[02],stu[i].ave);
	}
	/*�������*/
	
	return 0;
}	
