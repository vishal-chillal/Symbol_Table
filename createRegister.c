#include"struct.h"
#define zero 0;

int insert_rg(regNode **head,char *regName)
{
  regNode *temp,*newnode;
  newnode=(regNode*)malloc(sizeof(regNode));
  newnode->regName = malloc(strlen(regName)+1);
  if(newnode==NULL)
             return -1;
  strcpy(newnode->regName,regName);
  newnode->next=NULL;
  if(*head == NULL)
    {
      *head = newnode;
      return 0;
    }
  else
    {
	  temp = *head;
	  while(temp->next != NULL)
	  {
			  temp = temp->next;
      }
      temp->next = newnode;
      return 0;
    }
  return 1;
}

void display_rg(regNode *head)
{
		regNode *temp = head;
		while(temp->next != NULL)
		{
				printf("%s",temp->regName);
				temp=temp->next;
		}
		printf("%s",temp->regName);
}

int createRg_Table(regNode **first)
{
		
		FILE *fp;
		char buf [1024];
		fp = fopen("input2","r");
		if (fp == NULL)
		{
				exit(0);
		}		
		while(fgets(buf,sizeof(buf), fp) != NULL)
		{
			//buf[strlen(buf) - 1] = '\0';
			insert_rg(first,buf);
		}
		display_rg(*first);
		//		display_rg(first);
		fclose(fp);
		return 0;
}
