#include"struct.h"
int print_table(sysTab **head)
{
  sysTab *temp;
  (*head)->lineNo = 0;
  temp = *head;
  while(temp != NULL)
    {
      printf("%.8X | %d\t| %s\t| %s\t| %s\t| %s\n",temp->lineNo,temp->index,temp->name,temp->section,temp->val,temp->type);
      temp = temp->pNext;
    }
  return 0;
}

int text_print_table(TsysTab **head)
{
  TsysTab *temp;
  temp = *head;
  while(temp != NULL)
    {
      printf("%d\t | %d\t| %s\t| %s\t| %d\t| %s\n",temp->lineNo,temp->index,temp->name,temp->section,temp->val,temp->type);
      temp = temp->pNext;
    }
  return 0;
}

