#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start = NULL;

struct node *create_cll(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	
	printf("\nEnter -1 to end\nEnter the data:");
	scanf("%d",&num);
	
	while(num!=-1)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num;
		if(start == NULL)
		{
			new_node->next = new_node;
			start = new_node;
		}
		else
		{
			ptr = start;
			while(ptr->next != start)
			{
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->next = start;
		}
		printf("\nEnter the data:");
		scanf("%d",&num);
	}
	
	return start;
};
struct node *display(struct node *)
{
	struct node *ptr;
	ptr=start;
	printf("Tail<-");
	while(ptr->next != start)
	{
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
	printf("%d->Head",ptr->data);
	
	return start;
};

struct node *insert_beg(struct node *)
{
	struct node *new_node,*ptr;
	int num;
	
	printf("\nEnter the data:");
	scanf("%d",&num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	
	while(ptr->next != start)
	{
		ptr = ptr->next;
	}
	ptr->next = new_node;
	new_node->next = start;
	start = new_node;
	
	return start;
};
struct node *insert_end(struct node *)
{
	struct node *new_node,*ptr;
	int num;
	
	printf("\nEnter the data:");
	scanf("%d",&num);
	
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	
	while(ptr->next != start)
	{
		ptr = ptr->next;	
	}
	ptr->next = new_node;
	new_node->next = start;
	
	return start;
};

struct node *delete_beg(struct node *)
{
	struct node *ptr;
	ptr = start;
	
	while(ptr->next != start)
	{
		ptr = ptr->next;	
	}
	
	ptr->next = start->next;
	free(start);
	start = ptr->next;
	
	return start;
};
struct node *delete_end(struct node *)
{
	struct node *ptr,*preptr;
	ptr = start;
	
	while(ptr->next != start)
	{
		preptr = ptr;
		ptr = ptr->next;	
	}
	
	preptr->next = ptr->next;
	free(ptr);
	
	return start;
};
struct node *delete_after(struct node *)
{
	struct node *ptr,*preptr;
	int val;
	
	printf("\nEnter thevalue after which node has to deleted:");
	scanf("%d",&val);
	
	ptr = start;
	preptr = ptr;
	while(preptr->data != val)
	{
		preptr = ptr;
		ptr = ptr->next;	
	}
	
	preptr->next = ptr->next;
	if(ptr==start)
	{
		start = preptr->next;	
	}
	free(ptr);
	
	return start;
};

struct node *delete_list(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr->next != start)
	{
		start = delete_end(start);	
	}	
	free(start);
	return start;
};
int main()
{
	int option;
	
	do
	{
		printf("\n*** MAIN MENU ***");
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Add a node at the beginning");
		printf("\n 4: Add a node at the end");
		printf("\n 5: Delete a node from the beginning");
		printf("\n 6: Delete a node from the end");
		printf("\n 7: Delete a node after the given node");
		printf("\n 8: Delete the list");
		printf("\n 9: Exit");
		
		printf("\n\nEnter your option to use Circularly Linked List:");
		scanf("%d",&option);
		switch(option)
		{
			case 1: start = create_cll(start);
					printf("CIRCULARLY LINKED LIST IS CREATED");
			break;
			case 2:
					start = display(start);
			break;
			case 3:
					start = insert_beg(start);
			break;
			case 4:
					start = insert_end(start);
			break;
			case 5:
					start = delete_beg(start);
			break;
			case 6:
					start = delete_end(start);
			break;
			case 7:
					start = delete_after(start);
			break;
			case 8:
					start = delete_list(start);
					printf("CIRCULARLY LINKED LIST IS DELETED");
			break;
		}
	}while(option!=9);
		
}
