#include"struct.h"
int prnt_opcd(opcd **ppHead)
{
  opcd *temp;
  temp = *ppHead;
  if(temp == NULL)
    printf("\nnull\n");
  
  while(temp->pNext != NULL)
    {
      printf("%s \t| %s | %s | %s \n",temp->opcode,temp->mn,temp->op1,temp->op2);
      temp = temp->pNext;
    }
  return 0;
}
