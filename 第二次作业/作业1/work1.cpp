//�Ӽ���������Ҫд���ѧ����Ϣ����n��n<10�ˣ�������n��ѧ�������ݣ�������д���ļ�student.txt�У�����ȫ��ѧ����Ϣ��ʾ����Ļ�ϣ�
//�ر��ļ�������ѧ����Ϣ����ѧ�ţ�4λ��������������������10���ַ�����3�ſεķ���(������,����2λС��)��

#include <stdio.h>
#include <stdlib.h>

/*����ṹ�����*/
struct student				
{
	char num[10];
	char name[8];
	float score[3];
};	
/*����ṹ���������*/



int main()
{
	
	
	/*�������*/
	int i,j,sum,N;
	printf("input the number of student:\n");
	scanf("%d",&N)	;
	struct student stud01[N];	

	FILE *fpstu062; 
	/*�����������*/
	
	/*����N�����ݣ�����ṹ������stud01��*/
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
			scanf("%f",&stud01[i].score[j]);	//˳�����������ɼ���
		}
	}
	/*�������ݽ���*/
	
	
	/*ֻд��ʽ���ļ�stu062.txt*/
	fpstu062=fopen("student.txt","w");
	for(i=0;i<N;i++)
		
		fprintf(fpstu062,"%s %s %.2f %.2f %.2f\n",stud01[i].num,stud01[i].name,stud01[i].score[0],stud01[i].score[1],stud01[i].score[2]);
	                                                             	//   !!!   ����ԭ�ͣ� int fprintf (FILE* stream, const char*format, [argument])
	                                                             	//   !!!   �������ܣ���ʽ�������һ�����ļ���
	                                                             	//   !!!   ����ֵ���ɹ��򷵻�������ֽ�����ʧ�ܷ���eof
	fclose(fpstu062);
	/*�ر��ļ�*/
		
		
		
	/*��ӡ�����е�����*/
	printf("���ȫ��ѧ����Ϣ:\n");
	for(i=0;i<N;i++)
		printf("%s,%s,%.2f,%.2f,%.2f\n",stud01[i].num,stud01[i].name,stud01[i].score[0],stud01[i].score[1],stud01[i].score[2]);
	/*������ݽ���*/

	return 0;
	
	
	
	


}//main��������
