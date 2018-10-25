#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
	int data;
	struct node_s *next;
} node_t;

node_t *head;

void insertToHead(int val)
{
	node_t *temp = (node_t *) malloc(sizeof(node_t));
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

void main()
{
	head = NULL;
	insertToHead(10);
	insertToHead(11);
	insertToHead(12);
	printf("LL after insertToHead:\n");
	printLinkedList();
	printf("LL after recursive print:\n");
	printLinkedListInRecursive(head);
	printf("\n");
	reverseInIterative();
	printf("LL after reversteInIterative:\n");
	printLinkedList();
	freeLinkedList();
	printf("LL after clean:\n");
	printLinkedList();
}
