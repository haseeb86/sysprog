#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
	char title[50];
	int id;
};	

struct Node
{
	struct Book data;
	struct Node *nextNode;
};

void PrintAllNodes(struct Node *node_ptr)
{
    while(node_ptr!=NULL)
    {
    	printf("%s / ",node_ptr->data.title);
    	printf("ID: %d \n",node_ptr->data.id);
    	node_ptr = node_ptr->nextNode;
    }
}

struct Node* AddNode()
{
    static int node_id = 1;
    struct Node *node_ptr = (struct Node*)malloc(sizeof(struct Node));
    /////////// inseart data in node ////////////
    strcpy(node_ptr->data.title , "New Book");
    node_ptr->data.id = node_id++;
    node_ptr->nextNode = NULL;
    /////////// -------------------- ////////////
    return node_ptr;
}

struct Node* ReverseNodes(struct Node *head_ptr)
{
  struct Node *curr_ptr; // = malloc (sizeof(struct Node)); 
  
  if (head_ptr == NULL || head_ptr->nextNode == NULL) 
  {
    return head_ptr;
  }
  //temp_ptr->nextNode = curr_ptr->nextNode;
  //ReverseNodes(curr_ptr->nextNode);
  //curr_ptr = temp_ptr->nextNode;
  //curr_ptr->nextNode = temp_ptr;
  struct Node *temp_ptr = ReverseNodes(head_ptr->nextNode);
  curr_ptr = head_ptr->nextNode;
  curr_ptr->nextNode = head_ptr;
  head_ptr->nextNode=NULL;
  
  return temp_ptr;
}

int main()
{
	struct Node *HEAD=NULL;
	struct Node *CURR = malloc (sizeof(struct Node));
	int node_count=1;

    HEAD = CURR;
    for(int i=0;i<10;i++)
    {
        CURR->nextNode=AddNode();
        node_count++;
        CURR  = CURR->nextNode;        
    }

    PrintAllNodes(HEAD);
    printf("\n\n Reverse Order \n");
    HEAD = ReverseNodes(HEAD);
    //HEAD = reverse_recursive(HEAD);
    PrintAllNodes((HEAD));
    
    for(int i=0;i<node_count;i++)
    {
        if(CURR->nextNode!=NULL)
        {
            HEAD=CURR->nextNode;
            free(CURR);
        }
    }
	return 0;
}
