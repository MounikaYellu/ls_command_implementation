/*This function creates a new block dynamically to store the information of a student and links it appropriately into the singly linked list */
#include"MyHeader.h"
void add(NODE **ptr)
{
NODE *new,*temp;
new=(NODE *)malloc(sizeof(NODE));
printf("\n Enter Roll: ");
scanf("%d",&new->roll);
printf("\n Enter Name: ");
scanf("%s",new->name);
printf("\n Enter Marks:");
scanf("%f",&new->mark);
/* link ( New Record ) connected at the front
new->link=*ptr;
*ptr=new; */

/* Link ( New Record ) connected at the end
if(*ptr==0)
*ptr=new;
else
{
	temp=*ptr;
	while(temp->link) temp=temp->link;
	temp->link=new;
} */

// New Record as per Roll ( Adding Records in a Sorted order )
if(*ptr==0)
*ptr=new;
else if(new->roll<(*ptr)->roll)
{
	new->link=*ptr;
	*ptr=new;
}
else
{
	temp=*ptr;
	while((temp->link)&&(temp->link->roll<new->roll))
	temp=temp->link;
	new->link=temp->link;
	temp->link=new;
}
}
























