#include <stdio.h>

struct studentscore
{
	char name[10];
	int score;
};
int main()
{
	FILE *fp;
	int i=0,j=0;
	struct studentscore students[15];
	
	fp=fopen("in.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s %d\n",&students[i].name,&students[i].score);
		i++; 
	}
	fclose(fp);
	for(j=0;j<i;j++)
	{
        printf("%s %d\n",students[j].name,students[j].score);
    }	
    return 0;
} 

