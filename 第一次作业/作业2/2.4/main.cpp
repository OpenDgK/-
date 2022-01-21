//Please enter the information of all students in the local directory'in.txt'!
//Please view the information of failed students in the local directory 'out.txt'!
#include <stdio.h>
struct studentscore
{
	char name[10];
	int score;
};
int main()
{
	FILE *fp,*dt;
	int i=0,j=0;
	struct studentscore students[15];
	dt=fopen("out.txt","w");
	fp=fopen("in.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s %d\n",&students[i].name,&students[i].score);
		i++; 
	}
	fclose(fp);
	for(j=0;j<i;j++)
	{
        if(students[j].score<60)
		fprintf(dt,"%s %d\n",students[j].name,students[j].score);
    }
	printf("Please view the information of failed students in the local directory 'out.txt'!\n");
    return 0;
} 

