/*Write a menu driven program to implement Double Linked list */
#include<stdio.h>
#include<stdlib.h>

void create();
void traverse();
void insert_begin();
void insert_end();
void insert_afternode();
void insert_location();
void delete_begin();
void delete_end();
void delete_afternode();
void delete_location();

struct node
{
	int info;
	struct node *next;
	struct node *prev;
};
struct node *start = NULL;

main()
{
	int choice;
	while(1)
	{
		printf("\n0.Creation\n1.Traverse\n2.Insert at Beginning\n3.Insert at End\n4.Insert after a given node\n5.Insert at a specific location\n6.Delete from Beginning\n7.Delete from End\n8.Deleet after a Given node\n9.Delete from specific location\n10.Exit\n");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:create();
					break;
			case 1:traverse();
					break;
			case 2:insert_begin();
					break;
			case 3:insert_end();
					break;
			case 4:insert_afternode();
					break;
			case 5:insert_location();
					break;
			case 6:delete_begin();
					break;
			case 7:delete_end();
					break;
			case 8:delete_afternode();
					break;
			case 9:delete_location();
					break;
			case 10:exit(0);
			default:printf("\nWrong Choice\n");
					break;
		}
	}
}
void create()
{
	int total,item,index;
	struct node *newnode,*temp;
	if(start == NULL)
	{
		printf("\nEnter the total number of nodes you want to keep\n");
		scanf("%d",&total);
		if(total<=0)
		{
			printf("\nList size must be greater than zero\n");
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node));
			printf("\nEnter the value to keep in the node\n");
			scanf("%d",&item);
			temp->info = item;
			temp->next = NULL;
			temp->prev = NULL;//Addition in double linked list
			start = temp;
			for(index=2;index<=total;index++)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				printf("\nEnter the value to keep in the node\n");
				scanf("%d",&item);
				newnode->info = item;
				newnode->next = NULL;
				newnode->prev = temp;
				temp->next = newnode;
				temp = newnode;
			}
			printf("\nList is created\n");
		}
	}
	else
	{
		printf("\nList is already present\n");
	}	
}
void traverse()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = start;
		printf("\nValues of list are\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp = temp->next;
		}
		printf("\n");
	}
}
void insert_begin()
{
	struct node *newnode;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = NULL;
		newnode->prev = NULL;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			newnode->next = start;
			start->prev = newnode;//Added to make double linked list
			start = newnode;
		}
	}
}
void insert_end()
{
	struct node *newnode,*temp;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = NULL;
		newnode->prev = NULL;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			temp = start;
			while(temp->next !=NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
		}
	}
}
void insert_afternode()
{
	struct node *newnode,*temp, *ptr;
	int item,value;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = NULL;
		newnode->prev = NULL;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			printf("\nEnter the node after which you want to insert\n");
			scanf("%d",&value);
			temp=start;
			while(temp!=NULL && temp->info!=value)
			{
				temp=temp->next;
			}
			if(temp == NULL)
			{
				printf("\nNode is not present\n");
			}
			else
			{
				ptr = temp->next;
				newnode->next = ptr;
				ptr->prev = newnode;
				temp->next = newnode;
				newnode->prev = temp;
			}
		}
	}
}
void insert_location()
{
	struct node *temp,*ptr,*newnode;
	int count=1,loc;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = NULL;
		newnode->prev = NULL;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			printf("\nEnter the location at which you want to insert\n");
			scanf("%d",&loc);
			if(loc == 1)
			{
				newnode->next = start;
				start->prev = newnode;
				start = newnode;
			}
			else
			{
				temp=start;
				while(temp!=NULL && count!=loc)
				{
					ptr=temp;
					temp=temp->next;
					count++;
				}
				if(temp == NULL)
				{
					printf("\nNode is not present\n");
				}
				else
				{
					ptr->next = newnode;
					newnode->prev = ptr;
					newnode->next = temp;
					temp->prev = newnode;
				}
			}
		}
	}			
}
void delete_begin()
{
	struct node *temp;
	if(start == NULL)	
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = start;
		printf("\nDeleted node = %d\n",temp->info);
		start = start->next;
		start->prev = NULL;//To convert to double linked list
		free(temp);
	}
}
void delete_end()
{
	struct node *temp,*ptr;
	if(start == NULL)	
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = start;
		if(start->next == NULL)
		{
			printf("\nDeleted node = %d\n",start->info);
			free(temp);
			start = NULL;
		}
		else
		{
			while(temp->next != NULL)
			{
				ptr = temp;
				temp = temp->next;
			}
			printf("\nDeleted node = %d\n",temp->info);
			ptr->next = NULL;
			free(temp);
		}
	}
}
void delete_afternode()
{
	struct node *ptr,*temp,*ptr1;
	int value;
	if(start == NULL)	
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter the node after which you want to delete\n");
		scanf("%d",&value);
		ptr=start;
		while(ptr!=NULL && ptr->info!=value)
		{
			ptr=ptr->next;
		}
		if(ptr == NULL)
		{
			printf("\nNode is not present\n");
		}
		else if(ptr->next == NULL)
		{
			printf("\nNo node is present after this node\n");
		}
		else
		{
			temp = ptr->next;
			ptr1 = temp->next;
			ptr->next = ptr1;
			ptr1->prev = ptr;
			printf("\nDeleted node = %d\n",temp->info);
			free(temp);
		}
	}		
}
void delete_location()
{
	struct node *ptr,*ptr1,*temp;
	int loc,count=1;
	if(start == NULL)	
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter the location from which you want to delete\n");
		scanf("%d",&loc);
		ptr=start;
		while(ptr!=NULL && count!=loc)
		{
			ptr1 = ptr;
			ptr = ptr->next;
			count++;
		}
		if(ptr == NULL)
		{
			printf("\nNode is not present\n");
		}
		else if(loc == 1)
		{
			start = start->next;
			start->prev = NULL;
			printf("\nDeleted node = %d\n",ptr->info);
			free(ptr);
		}
		else
		{
			temp = ptr->next;
			ptr1->next = temp;
			temp->prev = ptr1;
			printf("\nDeleted node = %d\n",ptr->info);
			free(ptr);
		}		
	}	
}
