#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct ACCE{
   double x;
   double y;
   double z;
   double avg;
};

struct Node{

  struct ACCE data;
  struct Node* nextNode;
};

struct LList{
      
  struct Node* head;
  struct Node* last;
  int count;

};

struct Node* addNewNode(struct LList* list, int pos);

void printList(struct LList* list)
{
   struct Node* temp = list->head;
   while(temp!=NULL)
   {
     printf("%f\n",temp->data.avg);
     temp = temp->nextNode;
   }

}

void reverseList(struct LList* list)
{
   struct Node* curr = list->head;
   struct Node* temp = NULL;
   list->last = list->head;
   while(curr!=NULL)
   {
     temp = curr;
     curr = curr->nextNode;
     temp->nextNode = list->head;
     list->head = temp;
   }

   list->last->nextNode = NULL;

}

int main(int argc,char* args[])
{
   char buff[1024]={0};
   char *temp;
   char* token;
   if(argc < 3) 
   {
      printf("Input file not spacified!");
      return  -1;
   } 

   printf("Input File: %s\n", args[1]);

   struct LList ACCEList;
   ACCEList.head = NULL;
   ACCEList.last = NULL;
   ACCEList.count = 0;
   

   FILE * file = fopen(args[1],"r");

   int n = 0;

   while(fgets(buff,1024,file))
   {
        temp = strdup(buff);
        token = strtok(temp,";");
        if(strcmp(token,args[2])==0)
        { 
           struct Node* node = addNewNode(&ACCEList,-1);
           
           token=strtok(NULL,";");
           token=strtok(NULL,";");
           token=strtok(NULL,";"); //X
           node->data.x = strtod(token,NULL);
           token=strtok(NULL,";"); //Y
           node->data.y = strtod(token,NULL);
           token=strtok(NULL,";"); //Z
           node->data.z = strtod(token,NULL);
           
           
           double d = (node->data.x + node->data.y + node->data.z)/3.0;
           node->data.avg = d;

        }
        free(temp);
        temp = NULL;
   }

   //reverseList(&ACCEList);

   printList(&ACCEList);


   fclose(file);
}


struct Node* addNewNode(struct LList* list, int pos)
{
   
     struct Node* node = malloc(sizeof(struct Node));
     node->nextNode = NULL;

   if(list->head == NULL)
   {
     list->head = node;
     list->last = node; 
   }
   else{
        if(pos==0)
        {
                node->nextNode = list->head;
		list->head = node;
        }
        else if(pos == -1)
        {
          list->last->nextNode = node;
          list->last = node;
        }
        else
        {
          struct Node* temp = list->head;
	   while(temp!=NULL)
	   {
	    
	     temp = temp->nextNode;
	   }
        }
   }
   list->count++;
   return node;
}


