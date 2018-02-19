//This function deletes a Record according to given RollNo
#include"MyHeader.h"
void del(NODE **ptr)
{
int roll2del;
NODE *temp,*prev;
if(*ptr==0)
{
	printf("List is Empty\n");
	return;
}
printf("Enter Roll no to Delete \n");
scanf("%d",&roll2del);
temp=(*ptr);
while(temp&&(temp->roll!=roll2del))
{
	prev=temp;
	temp=temp->link;
}
if(temp==NULL)
{
	printf(" Node not found\n");
	return;
}
if(temp==(*ptr))
(*ptr)=temp->link;
else
prev->link=temp->link;
free(temp);
printf("\n Delete Successful\n");
}



