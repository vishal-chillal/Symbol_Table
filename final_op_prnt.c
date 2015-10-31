#include"struct.h"
int final_op_default(char *mneMonic,char *op1,char *op2,opcd *O_head)
{
  printf(" %d \t %d \t %d \n",strlen(mneMonic),strlen(op1),strlen(op2));
  while(O_head != NULL)
    {
      //  printf("%s|%s",op2,O_head->op2);
      if(strcmp(mneMonic,O_head->mn)==0)
	 if((strcmp(op1,O_head->op1)==0) && (strcmp(op2,O_head->op2)==0)) 
	{	
	  printf(" %s \n",O_head->opcode);
	  return 0;
	}
      
	    O_head = O_head->pNext;
    }

  return 1;
}

int final_op_sec(char *mneMonic,char *op1,char *op2,sysTab *O_head)
{
  return 0;
}
  

int final_op_Lsec(char *mneMonic,char *op1,char *op2,litTab *pHead)
{
  return 0;
}
/* { */
/*   while(O_head != NULL) */
/*     { */
/*       if(strcmp(mneMonic,O_head->mn)==0) */
/* 	{ */
/* 	  if(strcmp(op1,O_head->op1)==0) */
/* 	    if(strcmp(op2,O_head->op2)==0) */
/* 	      return 0; */
/* 	} */
/*       else */
/* 	O_head = O_head->pNext; */
/*     } */
/*   return 1; */
/* } */
