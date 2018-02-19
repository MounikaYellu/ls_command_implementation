// This file contains Student Record Menu 
#include"MyHeader.h"
/*UpdateListFromFile function is used to get the Previous student Records into RAM i.e. It constructs a list of records in heap memory */
void save(NODE *ptr)
{
FILE *fp;
fp=fopen("Student_DB.dat","w");
while(ptr)
{
fwrite(ptr,sizeof(NODE)-sizeof(NODE*),1,fp);
ptr=ptr->link;
}
fclose(fp);
}
NODE *UpdateListFromFile(void)
{
NODE v,*new,*head=NULL,*last;
FILE *fp;
fp=fopen("Student_DB.dat","r");
if(fp==0) return 0;
while(fread(&v,sizeof(NODE)-sizeof(NODE *),1,fp)==1)
{
	new=(NODE *) malloc(sizeof(NODE));
	memcpy(new,&v,sizeof(NODE)-sizeof(NODE *));
	if(head==0)
	{
		head=new;
		last=new;
	}
	else
	{
		last->link=new;
		last=new;
	}
}
fclose(fp);
return head;
}
int main()
{
int c;
NODE *head=NULL;
head=UpdateListFromFile(); 
while(1)
{
	printf("\n **************MENU***************** \n");
	printf("\t1.Add new record \n\t2.Show the list \n\t3.Delete a record 		\n\t4.Save \n\t0.exit\n");
	printf("Enter your choice : \n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:add(&head);break;
		case 2:print(head);break;
		case 3:del(&head);break;
		case 4:save(head);break;
		case 0:return 1; break;
		default:printf(" Invalid choice , Enter choice again \n");
	}
}
return 0;
}

