#include <stdio.h>
#include <stdlib.h>

/* ****************************
Pending tasks:
4. Add swich statement for input.

******************************/

typedef struct node_s
{
	int data;
	struct node_s *next;
} node_t;

node_t *head;


void findNthNodeFromLast(int pos)
{
	int i;
	node_t *first = head;
	node_t *second = head;

	if (head == NULL)
		return;

	for (i=1; i < pos; i++) {
		first = first->next;
		if (first == NULL) {
			printf("Given wrong position\n");
			return;
		}
	}
	
	while (first->next != NULL) {
		first = first->next;
		second = second->next;
	}
		
	printf("Nth position value %d\n", second->data);
	return;
}

void insertToHead(int val)
{
	node_t *temp = (node_t *) malloc(sizeof(node_t));
	if (temp == NULL) {
		printf("Memory allocation is failed for new node\n");
		return;
	}
	temp->data = val;
	temp->next = head;
	head = temp;
	return;
}

void printLinkedList()
{
	node_t *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

void printLinkedListInRecursive(node_t *p)
{
	if (p == NULL)
		return;
	printf("%d ", p->data);
	printLinkedListInRecursive(p->next);
}

void revLinkedListInRecursive(node_t *p)
{
	if (p->next == NULL) {
		head = p;
		return;
	}
	revLinkedListInRecursive(p->next);
	node_t *q = p->next;
	q->next = p;
	p->next = NULL;
}

void freeLinkedList()
{
	node_t *temp = head;
	node_t *prev = NULL;
	while (temp != NULL)
	{
		prev = temp;	
		temp = temp->next;
		free(prev);
	}
	head = NULL;
	return;
}

void reverseInIterative()
{
	node_t *temp = head;
	node_t *prev = NULL;
	node_t *next = NULL;

	while (temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}		
	head = prev;		
}

void deleteNthNode(int pos)
{
	node_t *temp = head;
	int i = 0;
	if (head == NULL & pos != 1)
	{
		printf("Enter wrong position to delete\n");
		return;
	}

	if (pos == 1)
	{
		head = temp->next;
		free(temp);
		return;
	}

	node_t *temp1 = head;
	for (i = 0; i < pos - 2; i++)
	{
		temp1 = temp1->next;
		if (temp1->next == NULL)
		{
			printf("Enter wrong position\n");
			return;
		}
	}
	temp = temp1->next;
	temp1->next = temp->next;
	free(temp);
	return;
}

void insertNodeToN(int pos)
{
	int i = 0;
	if (head == NULL & pos != 1) 
	{
		printf("Enter wrong position\n");
		return;
	}

	node_t *temp = (node_t *) malloc(sizeof(node_t));
	temp->data = 200;
	temp->next = NULL;

	if (pos == 1) 
	{
		temp->next = head;
		head = temp;
		return;
	}

	node_t *temp1 = head;
	for (i = 0; i < pos - 2; i++)
	{
		temp1 = temp1->next;
		if (temp1 == NULL)
		{
			printf("Enter wrong position\n");
			return;
		}
	}

	temp->next = temp1->next;
	temp1->next = temp;
	return;
}

void prepareLinkedList(void)
{
	int entries = 0;
	int i;
	int temp = 0;
	printf("Enter the no of nodes:");
	scanf("%d", &entries);
	for(i=0; i < entries; i++)
	{
		temp++;
		insertToHead(temp);
	}
}

void main()
{
	head = NULL;
	int position = 0;
	int option = 0;


	while (1) 
	{
		printf("1. Prepare linked list\n");
		printf("2. Print node from last\n");
		printf("3. Delete nth node from list\n");
		printf("4. Insert node in  nth position\n");
		printf("5. Reverse LL with recursive method\n");
		printf("6. Reverse LL with iterative method\n");
		printf("7. print linked list\n");
		printf("8. Exit\n");
		
		printf ("Please select option to execute\n");
		scanf("%d", &option);

		if ( (option < 1) || (option > 8)) 
		{
			printf("Select proper option\n");
			continue;
		}


		switch (option)
		{
			case 1:
				prepareLinkedList();
				continue;
			case 2:
				printf("Enter the position to print from last\n");
				scanf("%d", &position);
				findNthNodeFromLast(position);
				continue;
			case 3:
				printf("Enter the position to delete node\n");
				scanf("%d", &position);
				deleteNthNode(position);
				continue;
			case 4:
				printf("Enter the position to insert node\n");
				scanf("%d", &position);
				insertNodeToN(position);
				continue;
			case 5:
				revLinkedListInRecursive(head);
				printLinkedList();
				continue;
			case 6:
				reverseInIterative();
				printLinkedList();
				continue;
			case 7:
				printLinkedList();
				printf("\n");
				continue;
			case 8:
				freeLinkedList();
				break;
		}
		break;		

	}
}
