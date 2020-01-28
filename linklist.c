#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
	char title[50];
	int id;
};	

struct Node {
	struct Book data;
	struct Node *nextNode;
};

void PrintBook(struct Book *bookptr)
{
	printf("Name: %s \n",bookptr->title);
	printf("Book ID: %d \n",bookptr->id);
}

struct Node* GetBook()
{	
	static int bootid=1;
	struct Node *node = malloc(sizeof(struct Node));
	/////////////////////////////////	
	strcpy(node->data.title,"Name 1");
	node->data.id=bookid++;
	/////////////////////////////////
	//node->nextNode=NULL;
	return &node;
}

int main()
{
	struct Node *head=NULL;
	struct Node *curr=NULL;
	int count=0;
		
	head=curr;
	curr->nextMode=GetBook();
	count++;
	curr=curr->nextNode;

	curr->nextNode=GetBook();
	count++;
	curr=curr->nextNode;

	curr->nextNode=GetBook();
	count++;
	curr=curr->nextNode;

	curr=GetBook();
	count++;
	c
	for(int i=0;i<5000;i++)
	{
		curr->nextNode=GetBook();
		count++;
		curr=curr->nextNode;
	}
	for(int i=0;i<count;i++)
	{
		head=curr-nextNext;
		free(head);
	}
	return 0;
}
