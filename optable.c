#include"struct.h"
int optable(opcd **ppHead,char *opcode,char *instr, char *op1,char *op2)
{
  struct opcd *pTemp,*pNwnode;
  pNwnode=(opcd*)malloc(sizeof(opcd));
  if(pNwnode == NULL)
    return 1;
  
  pNwnode->opcode = (char*)malloc(sizeof(char)*((strlen(opcode)+1)));
  if(pNwnode->opcode == NULL)
    return 1;
  strcpy(pNwnode->opcode,opcode);

  pNwnode->mn = (char*)malloc(sizeof(char)*((strlen(instr))+1));
  if(pNwnode->mn == NULL)
    return 1;
  strcpy(pNwnode->mn,instr);
  
  pNwnode->op1 = (char*)malloc(sizeof(char)*((strlen(op1))+1));
  if(pNwnode->op1 == NULL)
		return 1;
  strcpy(pNwnode->op1,op1);

  pNwnode->op2 = (char*)malloc(sizeof(char)*((strlen(op2))+1));
  if(pNwnode -> op2 == NULL)
    return 1;
  strcpy(pNwnode ->op2,op2);
  pNwnode -> op2[strlen(pNwnode -> op2)-1]='\0';  
  pNwnode ->pNext = NULL;
  if(*ppHead == NULL)
    {
      *ppHead = pNwnode;
      return 0;
    }
  
  pTemp = *ppHead;
  while(pTemp -> pNext != NULL)
    pTemp = pTemp->pNext;
  pTemp -> pNext = pNwnode;
  return 0;
}


