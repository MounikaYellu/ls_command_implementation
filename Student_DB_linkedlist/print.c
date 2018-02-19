// This function dislays the complete list of student records 
#include"MyHeader.h"
void print(NODE *temp)
{
if(temp==NULL)
printf("\n No Records Found \n");
else
{
	printf("\n Below is the Student data \n");
	while(temp)
	{
		printf("%d\t%s\t\t%f\n",temp->roll,temp->name,temp->mark);
		temp=temp->link;
	}
}
}
