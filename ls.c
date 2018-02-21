#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char **argv)
{
struct dirent *ptr;
DIR *dp;
char **p=NULL ,temp[256];
int i=0,j,cnt;
if(argc==1)
dp=opendir(".");
else if(argc==2)
{
	dp=opendir(argv[1]);
	if(dp==NULL) 
	{
		printf("\nInvalid directory \n");
		exit(1);
	}
}
else
{
	printf("\nThis program accepts either one or two arguments\n");
	exit(1);
}
while(ptr=readdir(dp))
{
	p=realloc(p,(i+1)*sizeof(char *));
	p[i]=(char *) malloc(256);
	strcpy(p[i],ptr->d_name);
	i++;
}
cnt=i;
for(i=cnt-1;i>=1;i--)
{
	for(j=0;j<i;j++)
	{
		if(strcmp(p[j],p[j+1])>0)
		{
			strcpy(temp,p[j]);
			strcpy(p[j],p[j+1]);
			strcpy(p[j+1],temp);
		}
	}
}
printf("\nDisplaying files in sorting order\n");
for(i=0;i<cnt;i++)
	printf("%s\n",p[i]);
closedir(dp);
return 0;
}
