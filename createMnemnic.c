#include"struct.h"
#define zero 0;

int insert_mn(MnemonicNode **head,char *MnemonicName,int elt)
{
  MnemonicNode *temp,*newnode;
			      
  newnode=(MnemonicNode*)malloc(sizeof(MnemonicNode));
  newnode->MnemonicName = malloc(strlen(MnemonicName)+1);
  if(newnode==NULL)
             return -1;
  strcpy(newnode->MnemonicName,MnemonicName);
  newnode->value = elt;
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

void display_mn(MnemonicNode *head)
{
		MnemonicNode *temp = head;
		while(temp !=NULL)
		{
		  printf("%d : %s " ,strlen(temp->MnemonicName),temp->MnemonicName);
		  temp = temp->next;
		}
		//printf("%s",temp->MnemonicName);
}

int createMn_Table(MnemonicNode **first)
{
		
		FILE *fp;
		char buf [1024];
		fp = fopen("input1","r");
		if (fp == NULL)
		{
				exit(0);
		}		
		while(fgets(buf,sizeof(buf), fp) != NULL)
		{
			buf[strlen(buf) - 1] = '\0';
			insert_mn(first,buf,0);
		}
		//display_mn(*first);
		fclose(fp);
		return 0;
}
