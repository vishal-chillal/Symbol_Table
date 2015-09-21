#include"struct.h"
int print_table(sysTab **head)
{
  sysTab *temp;
  temp = *head;
  while(temp->pNext != NULL)
    {
      printf("%d | %d | %s | %s | %s | %s \n",temp->lineNo,temp->index,temp->name,temp->section,temp->val,temp->type);
      temp = temp->pNext;
    }
  return 0;
}

int text_print_table(TsysTab **head)
{
  TsysTab *temp;
  temp = *head;
  while(temp->pNext != NULL)
    {
      printf("%d | %d | %s | %s | %d | %s \n",temp->lineNo,temp->index,temp->name,temp->section,temp->val,temp->type);
      temp = temp->pNext;
    }
  return 0;
}

