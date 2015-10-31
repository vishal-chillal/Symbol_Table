#include "struct.h"
int check_Rg(char *op1,regNode *R_head)
{
  while(R_head != NULL)
    {       
      if(strcmp(R_head->regName,op1)!=0 )
	return 0;
      R_head = R_head->next;
    }
  return 1;
}

  

