//��student.txt�ļ�����ȡȫ��ѧ����Ϣ������ṹ�����飻�ٴӼ���������1��ѧ�������ݣ�Ҳ����ṹ�������У�
//�Ѷ�ȡ��ȫ��ѧ����Ϣ���������ѧ����Ϣһ��浽�ļ�student_new.txt�ļ��У�����ȫ��ѧ����Ϣ��ʾ����Ļ�ϣ��ر��ļ���
//����ѧ����Ϣ����ѧ�ţ�4λ��������������������10���ַ�����3�ſεķ���(������,����2λС��)��

/*�����⺯��*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*�����⺯������*/

/*�궨��*/
#define N 5		
/*�궨�����*/

/*����ṹ�����*/
struct student01				
{
	char num[10];
	char name[8];
	float score[3];
}stu01[N+1];			
/*����ṹ���������*/


main()
{
	/*�������*/
	int i,j;
	FILE *fpstu061,*fpstu063;	
	/*�����������*/

	/*�жϲ���ֻ����ʽ���ļ�student.txt*/
	if((fpstu061=fopen("student.txt","r"))==NULL)				//�����ļ�ʧ�ܣ�ִ�л������ڵ�����˳�����
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	/*�жϽ���*/

	/*��ȡ���ݣ����ļ�student.txt�����ݴ�������stu01[N]��*/
	for(i=0;i<N;i++)
		fscanf(fpstu061,"%s %s %f %f %f\n",&stu01[i].num,&stu01[i].name,&stu01[i].score[0],&stu01[i].score[1],&stu01[i].score[2]);
		                                                        //   !!!   ����ԭ�ͣ� int fscanf(FILE * stream, const char * format, [argument...]);
		                                                        //   !!!   �������ܣ�Ϊ�������ݸ�ʽ(format)����������(stream)�ж������ݣ��洢��argument�У������ո�ͻ���ʱ������fscanfλ��C��׼��ͷ�ļ�<stdio.h>�С�
		                                                        //   !!!   ����ֵ�����ͣ��ɹ����ض���Ĳ����ĸ�����ʧ�ܷ���EOF
	fclose(fpstu061);	
	/*��ȡ���ݽ���*/


	printf("\ninput score of student:\n");
	printf("No.:");
	scanf("%s",stu01[N].num);			//����ѧ�ţ�
	printf("name:");
	scanf("%s",stu01[N].name);			//����������		
	for(j=0;j<3;j++)
	{
		printf("score %d:",j+1);
		scanf("%f",&stu01[N].score[j]);	//˳�����������ɼ���
	}
	
	
	/*ֻд��ʽ���ļ�student_new.txt*/
	fpstu063=fopen("student_new.txt","w");
	for(i=0;i<N+1;i++)
		/*������stu03[N]�����ݴ���fptus003��ָ�ļ���*/
		fprintf(fpstu063,"%s %s %.2f %.2f %.2f\n",stu01[i].num,stu01[i].name,stu01[i].score[0],stu01[i].score[1],stu01[i].score[2]);
	/*�������ݴ������*/	
	fclose(fpstu063);


	/*��ӡ�����е�����*/
	printf("���ѧ����Ϣ��ԭʼ�����б�:\n");
	for(i=0;i<N+1;i++)
		printf("%s,%s,%.2f,%.2f,%.2f\n",stu01[i].num,stu01[i].name,stu01[i].score[0],stu01[i].score[1],stu01[i].score[2]);
	/*������ݽ���*/

}//main��������
