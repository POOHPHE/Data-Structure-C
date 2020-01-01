#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start = NULL;

struct node *create_dll(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	
	printf("\nEnter -1 to end\nEnter the data:");
	scanf("%d",&num);
	
	while(num!=-1)
	{
		if(start == NULL)
		{
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node->data = num;
			new_node->prev = NULL;	
			new_node->next = NULL;
			start = new_node;
		}
		else
		{
			ptr = start;
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node->data = num;
			
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->prev = ptr;
			new_node->next = NULL;
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
	printf("NULL<-");
	while(ptr != NULL)
	{
		printf("%d-><-",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
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
	start->prev = new_node;
	new_node->next = start;
	new_node->prev = NULL;
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
	
	while(ptr->next != NULL)
	{
		ptr = ptr->next;	
	}
	ptr->next = new_node;
	new_node->prev = ptr;
	new_node->next = NULL;
	
	return start;
};
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr;
	int num,val;
	printf("\nEnter the data:");
	scanf("%d",&num);
	
	printf("\nEnter the value before which the data has to be inserted:");
	scanf("%d",&val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	while(ptr->data != val)
	{
		ptr = ptr->next;
	}
	new_node->next = ptr;
	new_node->prev = ptr->prev;
	ptr->prev->next = new_node;
	ptr->prev = new_node;
	return start;
};
struct node *insert_after(struct node *start)
{
	struct node *new_node,*ptr;
	int num,val;
	printf("\nEnter the data:");
	scanf("%d",&num);
	
	printf("\nEnter the value after which the data has to be inserted:");
	scanf("%d",&val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	while(ptr->data != val)
	{
		ptr = ptr->next;
	}
	new_node->next = ptr;
	new_node->prev = ptr->next;
	ptr->next->prev = new_node;
	ptr->next = new_node;
	return start;
};

struct node *delete_beg(struct node *)
{
	struct node *ptr;
	ptr = start;
	start = start->next;
	start->prev = NULL;
	
	free(start);
	return start;
};
struct node *delete_end(struct node *)
{
	struct node *ptr;
	ptr = start;
	
	while(ptr->next != NULL)
	{
		ptr = ptr->next;	
	}
	
	ptr->prev->next = NULL;
	free(ptr);
	
	return start;
};
struct node *delete_before(struct node *)
{
	struct node *ptr,*temp;
	int val;
	
	printf("\nEnter the value before which node has to deleted:");
	scanf("%d",&val);
	
	ptr = start;
	while(ptr->data != val)
	{
		ptr = ptr->next;	
	}
	temp = ptr->prev;
	if(temp == start)
	{
		start = delete_beg(start);
	}
	else
	{
		ptr->prev = temp->prev;
		temp->prev->next = ptr;
	}
	free(temp);
	
	return start;
};
struct node *delete_after(struct node *)
{
	struct node *ptr,*temp;
	int val;
	
	printf("\nEnter the value after which node has to deleted:");
	scanf("%d",&val);
	
	ptr = start;
	while(ptr->data != val)
	{
		ptr = ptr->next;	
	}
	
	temp = ptr->next;
	ptr->next = temp->next;
	temp->next->prev = ptr;
	free(temp);
	
	return start;
};

struct node *delete_list(struct node *start)
{
	
	while(start != NULL && start->next != NULL)
	{
		start = delete_beg(start);	
	}	
	
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
		printf("\n 5: Add a node before the given node");
		printf("\n 6: Add a node after the given node");
		printf("\n 7: Delete a node from the beginning");
		printf("\n 8: Delete a node from the end");
		printf("\n 9: Delete a node before the given node");
		printf("\n 10: Delete a node after the given node");
		printf("\n 11: Delete the list");
		printf("\n 12: Exit");
		
		printf("\n\nEnter your option to use Doubly Linked List:");
		scanf("%d",&option);
		switch(option)
		{
			case 1: start = create_dll(start);
					printf("DOUBLY LINKED LIST IS CREATED");
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
					start = insert_before(start);
			break;
			case 6:
					start = insert_after(start);
			break;
			case 7:
					start = delete_beg(start);
			break;
			case 8:
					start = delete_end(start);
			break;
			case 9:
					start = delete_before(start);
			break;
			case 10:
					start = delete_after(start);
			break;
			case 11:
					start = delete_list(start);
					printf("DOUBLY LINKED LIST IS DELETED");
			break;
		}
	}while(option!=12);
		
}
